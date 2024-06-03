# Commit Messages

Please make sure that you have read those recommendations carefully.

The following outlines the additional conventions that are used in all TetraOS repositories (e.g. Solaris Cosmos-Shell).

## Example

```
status/volume: Automatically mute in vacuum

In space, no one can hear you scream. There is no point
in emitting sound that cannot be perceived, so automatically
mute all output streams.

```

## Description

Try to always prefix commit subjects with a relevant topic, such
as `overview:` or `st/actor:`. Less specific changes can use more
general topics such as `st` or `cpp`.

As a general rule, it is always better to write too much in the
commit message body than too little.

## References

References should always be expressed as full URL instead of the
`#1234` shorthand, so they still work outside the GitHub UI.

If a merge requests consists of multiple commits and none of them
fixes the issue completely, use the plain issue URL without prefix
as reference, and use the automatic issue closing syntax in the
description of the merge request.

Do not add any `Part-of:` line, as that will be handled automatically
when merging.

## The Fixes tag

If a commit fixes a regression caused by a particular commit, it
can be marked with the `Fixes:` tag. To produce such a tag, use

```
git show -s --pretty='format:Fixes: %h ("%s")' <COMMIT>
```

or create an alias

```
git config --global alias.fixes "show -s --pretty='format:Fixes: %h (\"%s\")'"
```

and then use

```
git fixes <COMMIT>
```
