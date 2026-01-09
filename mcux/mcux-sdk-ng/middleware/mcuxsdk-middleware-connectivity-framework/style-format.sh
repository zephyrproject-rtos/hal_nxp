#!/bin/bash
#
#  Copyright (c) 2024, NXP.
#

#
# The script to check or format source code of Connectivity Framework.
#
# Format c/c++:
#
#     style-format.sh format
#
# Check only:
#
#     style-format.sh check
#

set -e

# Check bash version. MCUXpresso has added bash in buildtools/bin since 11.9.0, which causes assignment of EXCLUDE_DIRS,
# EXCLUDE_FILES etc.. to fail.
BASH_PATH=`which bash`
SUB_PATH='ide/buildtools'
if [[ "$BASH_PATH" == *"$SUB_PATH"* ]]; then
    echo "Rename bash in MCUXpresso $BASH_PATH or change path to force use of /usr/bin/bash"
    exit 1
fi

readonly BUILD_JOBS=$(getconf _NPROCESSORS_ONLN)
readonly EXCLUDE_DIRS=(zephyr/subsys zephyr/include zephyr/lib zephyr/port/settings)
# must not be empty
readonly EXCLUDE_FILES=(placeholder.c)
readonly CLANG_SOURCES=('*.c' '*.cpp' '*.h' '*.hpp' '*.ch')

CLANG_VERSION="$(clang-format --version)"
EXPECTED_VERSION="clang-format version 16.0.0"

check_clang_version()
{
    command -v clang-format >/dev/null 2>&1 || { echo >&2 "clang is required. Please install LLVM package. Aborting ..."; exit 1; }
    case "${CLANG_VERSION}" in "${EXPECTED_VERSION}"*);;
        *)
            echo "${EXPECTED_VERSION} is required"
            exit 1
            ;;
    esac
}

do_clang_format()
{
    echo -e '========================================'
    echo -e '     format c/c++ (clang-format)'
    echo -e '========================================'

    echo "Formatting..."

    file_list=$(git diff --name-only HEAD  --diff-filter=AM "${CLANG_SOURCES[@]}" \
                        | grep -v -E "^($(echo "${EXCLUDE_DIRS[@]}" | tr ' ' '|'))"     \
                        | grep -v -E "*($(echo "${EXCLUDE_FILES[@]}" | tr ' ' '|'))")
    echo $file_list
    for i in $(echo $file_list); do
        clang-format -style=file -i $i
    done
    echo "Formatting done."
    echo "Checking git status:"
    echo

    git status
}

do_clang_format_check()
{
    echo -e '========================================'
    echo -e '     check c/c++ (clang-format)'
    echo -e '========================================'

    echo "Checking..."
    set +e
    echo $1
    if [ "$1" == 'pre-commit-check' ]; then
        #the pre commit check applies to the staged files. The diff-filter option is to exclude the deleted files (A Added, M Modified)
        git diff --name-only --cached --diff-filter=AM "${CLANG_SOURCES[@]}" | grep -v -E "^($(echo "${EXCLUDE_DIRS[@]}" | tr ' ' '|'))"     \
                                        | grep -v -E "*($(echo "${EXCLUDE_FILES[@]}" | tr ' ' '|'))"    \
                                        | xargs -n3 -P"${BUILD_JOBS}" clang-format -style=file --dry-run --Werror
    else
        # The clang check on the repository applies to all previous commits becasue a pull request may consist of several commits.
        # otherwise "git diff --name-only HEAD HEAD~1 --diff-filter=AM" could have worked for single commit PRs.
        git ls-files "${CLANG_SOURCES[@]}" | grep -v -E "^($(echo "${EXCLUDE_DIRS[@]}" | tr ' ' '|'))"     \
                                        | grep -v -E "*($(echo "${EXCLUDE_FILES[@]}" | tr ' ' '|'))"    \
                                        | xargs -n3 -P"${BUILD_JOBS}" clang-format -style=file --dry-run --Werror

    fi

    error_code=$?
    set -e

    if [ "$error_code" == "0" ]; then
        echo "All files are formatted as expected."
    else
        echo "Formatting is required, run ./style-format.sh to apply required formatting."
        exit $error_code
    fi
}

do_clang_format_all()
{
    echo -e '========================================'
    echo -e '     format c/c++ (clang-format)'
    echo -e '========================================'

    echo "Formatting..."

    file_list=$(git ls-files "${CLANG_SOURCES[@]}" | grep -v -E "^($(echo "${EXCLUDE_DIRS[@]}" | tr ' ' '|'))"     \
                                        | grep -v -E "*($(echo "${EXCLUDE_FILES[@]}" | tr ' ' '|'))")

    for i in $(echo $file_list); do
        clang-format -style=file -i $i
    done
    echo "Formatting done."
    echo "Checking git status:"
    echo

    git status
}

main()
{
    check_clang_version || exit 1

    PRECOMMIT_SCRIPT=`git rev-parse --git-path hooks`/pre-commit

    if [ -f "$PRECOMMIT_SCRIPT" ]; then
        local compare_hook=`diff -q "$PRECOMMIT_SCRIPT" "scripts/pre_commit_fwk.template"`
        if [ ! "$compare_hook" ]; then
            echo "Found fwk pre-commit hook"
        else
            echo "Existing pre-commit hook but differs"
            cp scripts/pre_commit_fwk.template $PRECOMMIT_SCRIPT
        chmod +x $PRECOMMIT_SCRIPT
        fi
    else
        echo "Pre-commit hook not existing"
        cp scripts/pre_commit_fwk.template $PRECOMMIT_SCRIPT
        chmod +x $PRECOMMIT_SCRIPT
    fi
    if [ $# == 0 ]; then
        do_clang_format
    elif [ "$1" == 'format' ]; then
        do_clang_format
    elif [ "$1" == 'check' ] || [ "$1" == 'pre-commit-check' ]; then
        do_clang_format_check $1
    elif [ "$1" == 'format-all' ]; then
        do_clang_format_all
    else
        echo >&2 "Unsupported action: $1. Supported: format, check"
        # 128 for Invalid arguments
        exit 128
    fi
}

main "$@"
