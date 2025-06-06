# How to make an Expansion version

*If you need instructions on how to release a new Expansion version, check out the enclosed instruction book. - AsparagusEduardo*

## 1.- Autogenerating a changelog for the `master` branch.
 *Requires Write access to the repo.*
 
If the changelog you're making is for a minor version (Eg. 1.3.0), make sure to sync the `upcoming` branch with `master` before starting. Keep in mind that if there are unreleased changes in `master`, they should be made into a patch version released alongside minor version.
- Go to https://github.com/rh-hideout/pokeemerald-expansion/releases.
- Press the option "Draft a new release".
- Fill the following fields:
    - In "Choose a tag", write the name of the tag for the desired release number.
        - Eg. for version 1.2.3, write `expansion/1.2.3`. ***It cannot be an existing tag.***
    - In "Target" choose `master`.
    - In "Previous tag", select the latest version released.
- Press "Generate release notes". This will fill the description with a list of PRs made to the `master` branch since the lastest release.
- You may copy the contents to your editor of choice for step 2.
- If the changelog you're making is for a minor version (Eg. 1.3.0), proceed to step 1B, without closing the current window.

## 1B.- Autogenerating a changelog for the `upcoming` branch.
- Delete the text and title generated in the site.
- Change "Target" to `upcoming`.
- Press "Generate release notes". This will autogenerate the description with changes from both branches, as they've been merged.
- Use a comparison tool to remove any shared PRs from `master`. (I use [WinMerge](https://winmerge.org/) for this).
    - Also remove any shared "New Contributor" entries.
- You should now have a text that only contains PRs made to `upcoming`.

## 2.- Sorting PRs in the changelog
- Copy the `docs/changelogs/template.md` file into a new file with the corresponding version for file and folder. Eg, for 1.2.3, you copy the file into `docs/changelogs/1.2.x/1.2.3.md`.
- Use the following Regex to adapt all PR links into the format currently used:
    - Search
        ```
        in https://github\.com/rh-hideout/pokeemerald-expansion/pull/(\d+)
        ```
    - Replace
        ```
        in [#$1](https://github.com/rh-hideout/pokeemerald-expansion/pull/$1)
        ```
- At the bottom of the template, replace the "____" in `<!--Last PR: ____-->` with the number of the last PR in your autogenerated changelog. This will help you keep track of any new PRs that are merged in before you're finished with your changelog.
- Sort the PRs by the categories present in the PR taking the following considerations:
    - Keep the language of the changelog as newbie friendly as possible, explaining how the PR affects them.
    - The format of the main line is the following:
        ```
        {{Description of the change}} by @{{GitHub user}} in {{PR link}}
        ```
    - If a PR reverted by a different PR, both should be removed.
        - If the reverted PR's contents are then re-added it should be treated as if it's the first time added, with all the proper documentation needed.
    - If a PR's content fits into multiple categories, like fixing two unrelated Ability and Move effects, you may duplicate the PR line and put it in both categories, changing the description of it accordingly.
    - When refering to an element present in the code, always enclose them with ` to easily tell them apart. Eg:
        - "Converted `settotemboost` command to `callnative`"
        - "Changed `MOVEEND_` defines to an enum"
    - A PR's technical changes that may conflict with user changes should have an entry in the "**REFACTORS**" section at the beginning of the changelog. Any of these changes that requires a migration script should also be marked as such by appending the corresponding emoji listed there. The section should include, but it's not limited to:
        - Massive data format and/or structuring changes.
        - Converting defines to enums.
        - Renaming structs and/or their fields.
        - Removing enums/defines/structs.
    - For fixes:
        - Once on their respective categories, if a PR fixes multiple issues at once in that category, you may make a sublist of those issues to properly detail each one and avoid just writing "Fixed multiple ability issues" or an overly verbose sentence for the PR.
        - Try to fit the contents of a PR as a single sentence in past tense that.
        - ***DON'T*** write something like "Fixed Parental Bond", as this doesn't explain *what* was fixed in Parental Bond. Instead, write something like "Fixed Parental Bond not affecting Snore".
    - For new configs:
        - Add the name of the config as part of the sentence, with subitems explaining what they do based on their generation if it's a generational config. Eg:
            ```
            * Added missing `B_AFTER_YOU_TURN_ORDER` config by @PhallenTree in [#5400](https://github.com/rh-hideout/pokeemerald-expansion/pull/5400)
                * Gen 5-7: After You fails if the order remains the same after using After You.
                * Gen 8+: After You no longer fails if the turn order remains the same after using After You.
            ```
    - For other new features:
        - Explain how to use the feature completely, listing all its features as needed. For now, this is the only source of documentation for these features, so it's important to be thorough.

# 3.- Preparing the code for the new version
- Search for all non-changelog instances of the previous released version and update them to the newer version. As of writing, it's these files:
    - `README.md`:
        ```diff
        -Based off RHH's pokeemerald-expansion 1.2.2 https://github.com/rh-hideout/pokeemerald-expansion/
        +Based off RHH's pokeemerald-expansion 1.2.3 https://github.com/rh-hideout/pokeemerald-expansion/
        ```
        ```diff
        -- Once you have your remote set up, run the command `git pull RHH expansion/X.Y.Z`, replacing X, Y and Z with the digits of the respective version you want to update to (eg, to update to 1.2.2, use `git pull RHH expansion/1.2.2`).
        +- Once you have your remote set up, run the command `git pull RHH expansion/X.Y.Z`, replacing X, Y and Z with the digits of the respective version you want to update to (eg, to update to 1.2.3, use `git pull RHH expansion/1.2.3`).
        ```
    - `.github/ISSUE_TEMPLATE/*.yaml`
        - Patch version:
            ```diff
            options:
            -   1.2.2 (Latest release)
            +   1.2.3 (Latest release)
                master (default, unreleased bugfixes)
                upcoming (Edge)
            +   1.2.2
                1.2.1
                1.2.0
            ```
        - Minor Version:
            ```diff
            options:
            -   1.2.2 (Latest release)
            +   1.2.3 (Latest release)
                master (default, unreleased bugfixes)
                upcoming (Edge)
            +   1.2.2
                1.2.1
                1.2.0
            -   1.1.6
            -   1.1.5
            -   1.1.4
            -   1.1.3
            -   1.1.2
            -   1.1.1
            -   1.1.0
            -   pre-1.1.0
            +   pre-1.2.0
            ```
    - `docs/SUMMARY.md`:
        - Patch version:
            ```diff
            [Changelog](./CHANGELOG.md)
                - [1.2.x]()
            +       - [Version 1.2.3](changelogs/1.2.x/1.2.3.md)
                    - [Version 1.2.2](changelogs/1.2.x/1.2.2.md)
                    - [Version 1.2.1](changelogs/1.2.x/1.2.1.md)
                    - [Version 1.2.0](changelogs/1.2.x/1.2.0.md)
            ```
        - Minor version:
            ```diff
            [Changelog](./CHANGELOG.md)
            +   - [1.3.x]()
            +       - [Version 1.3.0](changelogs/1.3.x/1.3.0.md)
                - [1.2.x]()
                    - [Version 1.2.2](changelogs/1.2.x/1.2.2.md)
                    - [Version 1.2.1](changelogs/1.2.x/1.2.1.md)
                    - [Version 1.2.0](changelogs/1.2.x/1.2.0.md)
            ```
    - `include/constants/expansion.h`:
        - The defines should already have the version we're targetting as part of the previous changelog process.
            ```diff
            -// Last version: 1.2.2
            +// Last version: 1.2.3
                #define EXPANSION_VERSION_MAJOR 1
                #define EXPANSION_VERSION_MINOR 2
                #define EXPANSION_VERSION_PATCH 3

                // FALSE if this this version of Expansion is not a tagged commit, i.e.
                // it contains unreleased changes.
            -#define EXPANSION_TAGGED_RELEASE FALSE
            +#define EXPANSION_TAGGED_RELEASE TRUE
            ```
# 4.- Make a PR with the changes listed in Steps 2/3.
- Also post the changelog for feedback from contributors and maintainers.
- Once all feedback has been addresses, you may merge.
# 5.- Create the release on GitHub
- Copy the contents of your manual changelog into the description of your release.
- Modify the title to "Version {{version}}", eg. "Version 1.2.3"
- Be sure to have the "Set as the latest release" option set,
- Press "Publish Release".
- This will create a new tag in the repo that users can pull from like they can with branches.
# 6.- Post-release handling
- ***DON'T ACCEPT ANY NEW PRs YET.*** We have to prepare for the next cycle first.
- Go to `include/constants/expansion.h` and merge the following changes to the repo (PR or direct commit, doesn't matter much):
    - Patch version:
        ```diff
         // Last version: 1.2.3
            #define EXPANSION_VERSION_MAJOR 1
            #define EXPANSION_VERSION_MINOR 2
        -   #define EXPANSION_VERSION_PATCH 3
        +   #define EXPANSION_VERSION_PATCH 4

            // FALSE if this this version of Expansion is not a tagged commit, i.e.
            // it contains unreleased changes.
        -#define EXPANSION_TAGGED_RELEASE TRUE
        +#define EXPANSION_TAGGED_RELEASE FALSE
        ```
With this, the repo is ready again to receive new PRs.

# Now you're ready to make the announcements!
- We tend to post on the following Discord Servers:
    - [RH-Hideout](https://discord.gg/6CzjAG6GZk)
        - Requires role to post in #announcements channel.
    - [Team Aqua's Hideout](https://discord.gg/team-aqua-s-hideout-976252009114140682)
        - Requires role to post in #romhacking-updates channel.
    - [What a Hack!](https://discord.gg/whack-a-hack-292436944670162955) 
        - Announcements are done in Spanish, but not the changelogs themselves.
        - Requires role to ping "Decompilaciones" role.
    - [pret](https://discord.gg/R4c3FA95dP)
    - [PokéCommunity](https://discord.gg/pokecommunity)

You can make a highlight of changes in the announcement itself, but it's not needed. (I also like using Discord emotes to highlight certain features during announcements, but gain, it's not needed).
