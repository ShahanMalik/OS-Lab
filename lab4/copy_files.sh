#!/bin/bash

# Prompt the user for the source files and destination directory
read -p "Enter the path of files to be copied (you can use wildcards like *.txt): " source_files
read -p "Enter the destination directory: " destination

# Ensure the destination directory exists
mkdir -p "$destination"

# Copy the files to the destination
cp $source_files "$destination"

# Check if the copy operation was successful
if [ $? -eq 0 ]; then
    echo "Success! Files have been copied to '$destination'."
    echo "List of directories in '$destination':"
    # List directories only in the destination
    ls -d "$destination"/*/ 2>/dev/null
else
    echo "Failed to copy files. Please check the file paths and try again."
fi