#!/bin/bash

checkerrors()
{
    if [ $? != 0 ]
    then
        exit 1
    fi
}

#add the env path for these commands, in case they are not set.
export PATH=$PATH:/bin:/usr/bin

TARGET_RSRC_DIR="$TARGET_BUILD_DIR"/../../../Resources/ObjectModelLib/

# create object model directory directory
if [ ! -d "$TARGET_RSRC_DIR" ]; then
    mkdir $TARGET_RSRC_DIR
fi

rm -f "$TARGET_RSRC_DIR/"*.idrc
for file in `ls "$REZ_COLLECTOR_DIR" | grep '\.idrc$'`
do
#   echo "cp \"$REZ_COLLECTOR_DIR/$file\" \"$TARGET_RSRC_DIR\""
    cp "$REZ_COLLECTOR_DIR/$file" "$TARGET_RSRC_DIR"
    checkerrors
done

rm -rf "$TARGET_RSRC_DIR/"idrc_*
for folder in `ls "$REZ_COLLECTOR_DIR" | grep 'idrc_'`
do
#   echo "cp -R \"$REZ_COLLECTOR_DIR/$folder\" \"$TARGET_RSRC_DIR\""
    cp -R "$REZ_COLLECTOR_DIR/$folder" "$TARGET_RSRC_DIR"
    checkerrors
done

#Also copy the .rsrc file. ObjectModelLib needs this file to be present in the target dir
cp -f "$REZ_COLLECTOR_DIR/ObjectModel.fr.rsrc" "$TARGET_RSRC_DIR/ObjectModelLib.rsrc"
checkerrors
touch "$REZ_COLLECTOR_DIR/resourcesCopied.txt"
exit 0
