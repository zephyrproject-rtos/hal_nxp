# Syncing MCUXpresso SDK code into hal_nxp

## 1. Background

Some code in hal_nxp — device headers, drivers, middleware — comes from the
[MCUXpresso SDK (MCUX SDK)](https://github.com/nxp-mcuxpresso), whose source is
**spread across many separate Git repos** (`mcuxsdk-core`, `mcux-component`,
`mcux-devices-rt`, ...), pinned by a **west manifest**. The SDK **releases
periodically**, and each release is **imported into hal_nxp**.

**The import is a direct file copy, not a `git merge`/patch replay**, because:

- hal_nxp needs only a *subset* of the SDK; build scripts, examples, Kconfig,
  linker scripts, prebuilt archives, etc. must be **removed**.
- A merge assumes shared history and 1:1 file correspondence — neither holds
  when curating a subset of many repos into a rearranged layout.

So the model is: **copy the wanted files → trim the rest → commit a snapshot.**

### The problem: patches hal_nxp carries ahead of the SDK

A plain copy would clobber fixes hal_nxp carries on top of upstream. Fixes flow
**both directions**, and the SDK release window makes the two sides drift:

- **hal_nxp → SDK:** a fix lands in hal_nxp first and is cherry-picked back to
  the SDK, but misses the release window. On re-import it must be **re-applied**.
- **SDK → hal_nxp:** an SDK fix is cherry-picked *early* into hal_nxp. Whether
  the next release contains it depends on the window — on re-import we must
  **skip** the ones the release already absorbed and **re-apply** the rest.

So on every re-import, for each hal_nxp patch, we must decide: **does the new
release already contain it?** That requires linking each hal_nxp patch to its
counterpart commit on the other side.

---

## 2. How it works

Three parts cooperate:

| Part | Where | Role |
|------|-------|------|
| `import.yaml` | hal_nxp root (`mcux/`) | Declares what to copy, from which repo@revision, and what to trim. See [`import-schema.md`](./import-schema.md). |
| `sync_msdk.py` | `mcux/scripts/sync_msdk/` | Runs the two-phase import + patch re-apply. |
| `west pick_hal_nxp` | SDK private | Cherry-picks patches between the two sides and stamps the link trailer. |

Two ideas make the patch decision automatic:

- **A trailer links each patch to its counterpart.** Every patch cherry-picked
  between the two sides carries a commit-message trailer naming the matching
  commit (injected automatically by `west pick_hal_nxp`):
  - SDK → hal_nxp: `mcux-sdk-commit: <repo-name>: <sdk-sha>`
  - hal_nxp → SDK: `hal-nxp-commit: <hal_nxp-sha>`

  `<repo-name>` is the GitHub repo name (matching a source's `name` in
  `import.yaml`). With the link, the tool answers "already in the release?" via
  an ancestor test: `git merge-base --is-ancestor <patch-sha> <release-sha>`.

- **A checkpoint bounds the scan.** The import snapshot commit's *title* carries
  a `mcux-sync-<entry>` marker. Every time import new SDK code, the tool will
  scan back to the previous checkpoint to find patches that need re-applying.

### The sync algorithm

`sync_msdk.py sync --entry <entry>`:

1. Copy each source's files, run the `remove`/`pin` trims, and **commit the
   snapshot** (the new checkpoint).
2. Scan hal_nxp history back to the previous `mcux-sync-<entry>` checkpoint (or
   `--since-sha`) and collect commits carrying a trailer.
3. **Keep only this entry's patches.** The shared history holds every team's
   patches; a patch belongs to this entry if its trailer `<repo-name>` is one of
   the entry's sources, or (for `hal-nxp-commit`) it touches one of the entry's
   `dest_path` prefixes (longest-prefix-wins). Others are ignored here.
4. **Decide each patch:** ancestor of the new release → **skip**; otherwise
   **re-apply**. Trailer-less patches can't be tested, so they re-apply
   unconditionally unless listed in `drop_patch` (see below).
5. **Re-apply** by cherry-pick, in order. Empty picks are skipped. On conflict:
   an interactive terminal prompts `[c]`ontinue / `[s]`kip / `[a]`bort.

### A picture of the two histories

The diagram traces one entry through **two imports**. The bottom lane is
**hal_nxp** (a single shared history; `-o-` are unrelated commits); the top
lane is one of the entry's **SDK source repos**. `[ SYNC@rel ]` are the copy-in
**snapshots**, whose commit title carries the `mcux-sync-<entry>` checkpoint.
Fixes flow *both* ways, and every cherry-pick carries a trailer linking it to
its twin on the other side.

```text
                               trailer:                     trailer:
                               hal-nxp-commit: <P1-SHA>     hal-nxp-commit: <P2-SHA>
                                      |                            |
                   SDK rel1           |                 SDK rel2   |
SDK (mcux-core)   /                   v                /           v
  ...--o---o--- R1 --o--  .... --o--  P1' --o-- .... R2 --o .. -- P2' --o--...
                |                     ^              |            ^
                |                     | pick         |           / pick patch
                |                     |              |          /
                |                     |              +--------------------------+
                |                     |                       /                 |
=============== | =================== | ==================== /==================|===================
                |                     |                     /                   |                P2 reapplied
HAL_NXP         v                     |                    /                    v                /
    --o-- [SYNC @rel1] --o-- ...--o-- P1 ---o-- .. --o-- P2 --o-- --o--o-- [SYNC @rel2] ------- P2" ------
                ^        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~         ^
            sync snapshot                          ^                        sync snapshot
            title: mcux-sync-basic: sync R1        |                        title: mcux-sync-basic: sync R2
                                                   |
                            scan patches in this range, P1 is included in rel2,
                            but P2 is not, so apply P2 again as P2"
```

**Reading the diagram.** `P1` and `P2` are two fixes that were born in hal_nxp
and cherry-picked back into the SDK as their twins `P1'` and `P2'`. Each twin
carries a `hal-nxp-commit: <sha>` trailer that points back at the hal_nxp commit
it came from - that trailer is what lets the tool pair the two sides later. On
the SDK line the releases `R1` and `R2` are cut at fixed points, and the timing
of each cherry-pick relative to `R2` is the whole story:

- `P1'` lands **before** `R2`, so `R2` already contains `P1`'s change.
- `P2'` lands **after** `R2`, so `R2` does **not** contain `P2`'s change yet.

**What the sync does.** When importing `R2`, the tool first copies the `R2` tree
and commits it as the snapshot `[SYNC @rel2]` (its title carries
`mcux-sync-basic: sync R2`, which also becomes the next checkpoint). It then
looks only at the hal_nxp commits in the scan range - the commits **after** the
previous checkpoint `[SYNC @rel1]` up to now (the `~~~~` span, which includes
`P1` and `P2`). For each one it runs the ancestor test against the release SHA:

```text
  P1   hal-nxp-commit: <P1-SHA>   is-ancestor(P1', R2)?  YES -> SKIP     (R2 already has it)
  P2   hal-nxp-commit: <P2-SHA>   is-ancestor(P2', R2)?  NO  -> RE-APPLY (missed the release)
```

**Result:** on top of the fresh `[SYNC @rel2]` snapshot the tool re-applies only
`P2`, which reappears as `P2"` - while `P1` is dropped because the new copy
already carries it.


### drop_patch -- the manual skip list


Commits predating the trailer convention have **no trailer**, so the ancestor
test can't skip them. `drop_patch` is a per-entry list of hal_nxp SHAs that must
**never** be re-applied -- it wins over the ancestor test. Use it for such legacy
commits or obsolete workarounds; prefer the automatic trailer test otherwise.
Field syntax is in [`import-schema.md`](./import-schema.md).

---

## 3. Quick start

**Prerequisites:**
- A local west workspace of the MCUX SDK, folders `manifests`, `mcuxsdk` are in this workspace.
- Define the system environment variable `MCUX_SDK_DIR` to point to the root of the MCUX SDK workspace.
- Python deps: `pip install pyyaml ruamel.yaml`.

```bash
cd <hal_nxp>/mcux

# Phase 1 — update: resolve each source's revision from the manifest, write it
# back into import.yaml, and queue upstream-deleted files as `remove` patterns.
# For example, this command will fill the SHAs for the `basic` entry from the v26.09.00-pvw2 manifest:
python scripts/sync_msdk/sync_msdk.py update --entry basic --manifest v26.09.00-pvw2

#   --> Review import.yaml: confirm the revisions, remove patterns, and pins. <--

# Phase 2 — sync: copy + trim + commit the snapshot, then re-apply patches the
# release does not yet contain.
python scripts/sync_msdk/sync_msdk.py sync --entry basic
```

Note: flag `--since-sha <sha>`, it is needed when this is the first time you run the sync
for a new entry, it means the hal_nxp SHA when the entry was synced last time. The tool
will scan back to this SHA to find patches that need re-applying. For example,
```bash
python scripts/sync_msdk/sync_msdk.py sync --entry basic --since-sha 2ba4f142394d01bb2c159bee1188b352274dcf40
```

Note: If you want to manually modify the `import.yaml` revisions, phase 1 is optional.

---

## 4. Onboarding your own repo

Add an **entry** to `import.yaml` — a group of related upstream repos owned by
one maintainer, advancing on its own checkpoint independently of other teams.

```yaml
entries:
  - name: mine                       # unique; also the checkpoint suffix
    description: "My middleware for hal_nxp"
    manifest:                        # for reference + the `update` command
      repo: https://github.com/nxp-mcuxpresso/mcuxsdk-manifests
      revision: v26.09.00-pvw2
    sources:
      - repo: https://github.com/nxp-mcuxpresso/my-repo
        name: my-repo                # GitHub repo name; the trailer key
        revision: <40-char-sha-or-tag>
        dest_path: mcux/mcux-sdk-ng/middleware/mine   # relative to hal_nxp ROOT
        copy:                        # Python regexes, relative to the repo root
          - ".*"                     # ".*" copies the whole repo
    actions:                         # trimming, run in order after all copies
      - type: remove                 # remove files matching these regexes
        patterns:                    # Python regexes, relative to hal_nxp root
          - "^mcux/.*\\.a$"
          - "^mcux/mcux-sdk-ng/middleware/mine/(.*/)?Kconfig[^/]*$"
          - "^mcux/mcux-sdk-ng/middleware/mine/example(/|$)"
      - type: pin                    # hold specific files which will not be updated
        patterns:                    # Python regexes, relative to hal_nxp root
          - "^mcux/mcux-sdk-ng/middleware/mine/(.*/)?Kconfig[^/]*$"
```

The data you prepare (full field reference in [`import-schema.md`](./import-schema.md)):

- **Sources** — for each repo: `repo` (clone URL); `name` (GitHub repo name,
  last URL segment without `.git` — the trailer key, ancestor-test target, and
  manifest lookup key, so it must be exact); `revision` (SHA or tag, filled by
  `update`); `dest_path` (where the repo root maps, from the hal_nxp root);
  `copy` (regexes selecting which files to copy).
- **Trim actions** — `remove` regexes for everything Zephyr doesn't need
  (build glue, examples, Kconfig, docs, archives). See the `basic` entries.
- **`pin`** (optional) — hold specific files at a fixed hal_nxp version.
- **`drop_patch`** (optional) — hal_nxp SHAs never to re-apply (§2).

Verify before running for real:

```bash
python scripts/sync_msdk/sync_msdk.py update --entry mine --dry-run
python scripts/sync_msdk/sync_msdk.py sync   --entry mine --dry-run
```

On the first sync there is no checkpoint, use `--sync-sha` instead, otherwise
the tool scans full history for your entry's patches; later syncs scan only
back to the previous checkpoint.

---

See [`import-schema.md`](./import-schema.md) for the full `import.yaml` field
reference.
