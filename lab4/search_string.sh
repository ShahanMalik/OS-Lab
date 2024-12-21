#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <file_path> <search_string>"
    exit 1
fi

file_path=$1
search_string=$2

# Check if the file exists
if [ ! -f "$file_path" ]; then
    echo "File not found: $file_path"
    exit 1
fi

# Display lines containing the search string
grep "$search_string" "$file_path"