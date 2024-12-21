#!/bin/bash

# Prompt the user for the directory name and destination
read -p "Enter the name of the directory to create: " dir_name
read -p "Enter the destination path: " destination

# Create the directory at the specified destination
mkdir -p "$destination/$dir_name"

# Check if the directory was successfully created
if [ $? -eq 0 ]; then
    echo "Success! Directory '$dir_name' created at '$destination'."
    echo "List of directories in '$destination':"
    # List directories only in the destination
    ls -d "$destination"/*/ 2>/dev/null
else
    echo "Failed to create directory. Please check the destination path and try again."
fi