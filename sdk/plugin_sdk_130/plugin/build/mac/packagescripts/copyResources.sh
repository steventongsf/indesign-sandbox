#!/bin/bash

checkerrors()
{
    if [ $? != 0 ]
    then
        exit 1
    fi
}

if [[ -e "$REZ_COLLECTOR_DIR/frFilePath" && -e "$REZ_COLLECTOR_DIR/resourcesCopied.txt" && "$REZ_COLLECTOR_DIR/resourcesCopied.txt" -nt "$REZ_COLLECTOR_DIR/frFilePath" ]]
then
    echo Resources are up-to-date.
    exit 0
fi

#add the env path for these commands, in case they are not set.
export PATH=$PATH:/bin:/usr/bin

rm -rf "$TARGET_BUILD_DIR/$UNLOCALIZED_RESOURCES_FOLDER_PATH/"*.idrc
for file in `ls "$REZ_COLLECTOR_DIR" | grep '\.idrc$'`
do
#   echo "cp \"$REZ_COLLECTOR_DIR/$file\" \"$TARGET_BUILD_DIR/$UNLOCALIZED_RESOURCES_FOLDER_PATH\""
   cp "$REZ_COLLECTOR_DIR/$file" "$TARGET_BUILD_DIR/$UNLOCALIZED_RESOURCES_FOLDER_PATH"
   checkerrors
done

rm -rf "$TARGET_BUILD_DIR/$UNLOCALIZED_RESOURCES_FOLDER_PATH/"idrc_*
for folder in `ls "$REZ_COLLECTOR_DIR" | grep 'idrc_'`
do
#   echo "cp -R \"$REZ_COLLECTOR_DIR/$folder\" \"$TARGET_BUILD_DIR/$UNLOCALIZED_RESOURCES_FOLDER_PATH\""
   cp -R "$REZ_COLLECTOR_DIR/$folder" "$TARGET_BUILD_DIR/$UNLOCALIZED_RESOURCES_FOLDER_PATH"
   checkerrors
done 

touch "$REZ_COLLECTOR_DIR/resourcesCopied.txt"
exit 0

