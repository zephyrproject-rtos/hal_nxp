# import.yaml Schema

This document describes **how to write `import.yaml`** — its structure and every
field. `import.yaml` (at the hal_nxp root, `mcux/`) declares which MCUXpresso SDK
files are imported into hal_nxp, from which upstream repo and revision, and which
files are trimmed afterwards.

For the *why* and *how* — the sync problem, the patch-tracking mechanism
(trailers, checkpoints, `drop_patch`), the two-phase workflow, and the
`west pick_hal_nxp` tool — see
[`sync-guide.md`](./sync-guide.md).

## Top-level Structure

```yaml
entries:
  - <entry>
  - <entry>
  ...
```

## Entry

An entry corresponds to a group of logically related upstream repos, owned by the
same maintainer.

```yaml
- name: <string>           # Unique entry identifier, used by the --entry argument,
                           # and also the suffix of the checkpoint marker
  description: <string>    # Human-readable description
  manifest:                # Manifest info for this release, for reference and the
                           # update command only
    repo: <url>
    revision: <git-revision>
  sources:                 # One or more upstream sub-repos
    - <source>
    - <source>
  actions:                 # Entry-level ordered action list, executed in order
    - <action>             # after all sources have been copied
    - <action>             # Only type: remove / type: pin allowed (no type: patch)
  drop_patch:              # Optional. hal_nxp commit SHAs in this entry that the
    - <hal_nxp-sha>        # sync tool must NOT re-apply (manual skip list)
    - <hal_nxp-sha>
```

## Source (upstream repo)

```yaml
- repo: <url>              # Upstream git repo address (GitHub repo address)
  name: <string>           # The GitHub repo name for this source (the key used in
                           # the trailer)
                           # = last segment of the GitHub clone origin URL without .git
                           # e.g.: mcux-component, mcux-devices-rt, mcux-devices-wireless
  revision: <git-revision> # Revision used for this sync: a commit SHA or a tag
  note: <string>           # Optional, supplementary note, e.g. the source branch name
  dest_path: <path>        # Destination path in the hal_nxp repo (relative to hal_nxp root);
                           # the upstream repo root maps directly onto this path
  copy:                    # Python regex list, matched against paths relative to the
    - <regex>              # upstream repo root; selects which files are copied
    - <regex>
```

**A source has no `src_path`.** The upstream repo root maps directly onto
`dest_path`. The `copy` list selects *which* files under the repo root are
copied: each entry is a Python regex matched against the file path relative to
the repo root (using `/`, no leading `/`). A matched file is copied to
`dest_path` while **keeping its path relative to the repo root**, so
`^cmake/extension/` copied with `dest_path: mcux-sdk-ng` lands under
`mcux-sdk-ng/cmake/extension/...`. Use `".*"` to copy the whole repo.

**A source only describes where to copy from and to.** It has no `remove` (or any
other action) field: every remove/pin step is an **entry-level action**, executed
in order after all sources are copied. This keeps all trimming logic in one place
(the entry's `actions` list) instead of being scattered per source.

**About `name` (important)**: Each upstream sub-repo is published on GitHub after
release; `repo` and the local development clone both point to the same GitHub repo.
The patch trailer records the **GitHub repo name**, and the ancestor test
(`git merge-base --is-ancestor`) is done against the same GitHub repo. Therefore
the `name` field must contain the **GitHub-side repo name** (last segment of the
repo URL without `.git`), consistent with the `<repo-name>` used by
`west pick_hal_nxp` (from the GitHub clone's origin URL). It is also the key used
to look the source up in the west manifest.

**Execution order**:
1. For every source in the entry, copy the files under `repo@revision`'s root
   that match the `copy` regex list into `dest_path` (preserving each file's
   path relative to the repo root).
2. Once all sources are copied, execute the entry-level `actions` list in order.

## Action (entry-level operation)

After all sources are copied, the actions list is executed in order.
**Only two action types are supported: `remove` and `pin`.**

### type: remove

Deletes files in hal_nxp that match. Used to:
- Delete files no longer needed after all sources are copied
- Delete files removed upstream that must be removed in sync (auto-appended by the
  `update` command)

```yaml
- type: remove
  patterns:                # Python regex list, matched against file paths relative
    - <regex>              # to the hal_nxp root
    - <regex>
```

### type: pin

Takes specific files from a certain commit in hal_nxp's own history and overwrites
the current working tree. Used for scenarios where "certain files must stay at a
fixed version and not follow upstream updates".

```yaml
- type: pin
  commit: <git-sha>        # Optional. A commit SHA in the hal_nxp repo.
                           # Defaults to HEAD when omitted.
  patterns:                # Python regex list, matched against files to overwrite
    - <regex>              # relative to the hal_nxp root
```

## drop_patch (optional per-entry field)

`drop_patch` is a per-entry list of **hal_nxp commit SHAs the sync tool must NOT
re-apply** for that entry. Its purpose and behavior (why it exists, how it
interacts with trailers and the ancestor test) are explained in the guide; here
is only the field shape:

```yaml
- name: basic
  # ...
  drop_patch:
    - 1234abcd   # absorbed by mcuxsdk-core v26.09; no trailer, drop it
    - deadbeef   # obsolete workaround, do not carry forward
```

- Each item is a hal_nxp commit SHA (full or abbreviated); any git-recognizable
  abbreviation works.
- An optional trailing `# reason` comment is strongly recommended.
- The list is scoped to the entry it lives under.

## Regex Matching Notes

- All `copy`/`remove`/`pin` patterns use **Python standard regular expressions**
  (the `re` module).
- `copy` patterns are matched relative to the **upstream repo root**.
- `remove` and `pin` patterns are matched relative to the hal_nxp **repo root**
  (i.e. they start with the `mcux/` prefix, matching the paths git reports).
- The match target is always the **file path** (using the `/` separator), without
  a leading `/`.

## Maintenance Rules

- **`revision` may be a full 40-character commit SHA or a tag**; branch names are
  not allowed (record a branch hint in the `note` field if useful).
- After each sync, `sources[].revision` should be updated to the revision (SHA
  or tag) actually used this time — the `update` command does this for you.
- The source `name` field must contain the **GitHub repo name**, consistent with
  the `<repo-name>` used by `west pick_hal_nxp` when injecting trailers.
- For patches that carry **no trailer** (e.g. commits predating the trailer
  convention) but should not be re-applied, add their hal_nxp SHA to the entry's
  `drop_patch` list with a short `# reason` comment.
