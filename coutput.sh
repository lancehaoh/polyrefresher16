#!/bin/bash
# Output Checker script for CS1020

# Validate Command line arguments
if [ $# -ne 1 ]
then
    echo "Usage: ./output.sh filename"
    exit 1;
fi

# Read the name of the cpp file
NAME=$1;

# Check if specified file exists
if ! [[ -f $NAME.cpp ]]
then
    echo "$NAME.cpp does not exist."
    exit 2
fi

# Check if input and output folder exist
if ! [[ -d input ]]
then
    echo "Folder input does not exist."
    exit 3
elif ! [[ -d output ]]
then
    echo "Folder output does not exist"
    exit 4
fi

# Start operations of Checking Script
echo "Running output checker script..."
echo -ne "\n"

# Compile cpp file
g++ -o $NAME $NAME.cpp

# Create a user output directory if necessary
echo "Checking for directory myoutput..."
if ! [[ -d myoutput ]]
then
    mkdir myoutput
    echo "Directory myoutput created!"
else
    echo "Directory myoutput exists."
fi

# Get all the input filenames
INPUTFILES=();
INPUTFILES_NUM=0;
OUTPUTFILES=();
OUTPUTFILES_NUM=0;

# Get the filenames in the input and output folder and write to temporary files
ls -l input/ | tr -s [[:space:]] | cut -f9 -d' ' | grep "^$" -v > inputFolderDAT
ls -l output/ | tr -s [[:space:]] | cut -f9 -d' ' | grep "^$" -v > outputFolderDAT

# Write the filenames in the input foder into an array
while read inputfile
do
    INPUTFILES[$INPUTFILES_NUM]=$inputfile
    INPUTFILES_NUM=$INPUTFILES_NUM+1;
done < inputFolderDAT;

# Write the filenames in the output folder into an array
while read outputfile
do
    OUTPUTFILES[$OUTPUTFILES_NUM]=$outputfile
    OUTPUTFILES_NUM=$OUTPUTFILES_NUM+1;
done < outputFolderDAT;

FILENUM=0;

echo -ne "\n"

# Perform output testing
echo "Testing CPP Program..."
echo -ne "\n"
while [[ $FILENUM  -lt $INPUTFILES_NUM ]]
do
    ./$NAME < input/${INPUTFILES[$FILENUM]} > myoutput/${OUTPUTFILES[$FILENUM]}
    diff output/${OUTPUTFILES[$FILENUM]} myoutput/${OUTPUTFILES[$FILENUM]} > /dev/null
    if [ $? -ne 0 ]
    then
        echo "File" ${OUTPUTFILES[$FILENUM]} "is different!"
    else
        echo "File" ${OUTPUTFILES[$FILENUM]} "is the same!"
    fi
    FILENUM=$FILENUM+1;
done

# Clean up temporary files
echo -ne "\n"
echo "Testing done! Cleaning up temporary files..."
rm -f inputFolderDAT
rm -f outputFolderDAT
rm -f $NAME

echo -ne "\n"
echo "Script Finished!"
# End of script
