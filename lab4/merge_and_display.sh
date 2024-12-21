#!/bin/bash

# Check if at least one file is provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <file1> <file2> ... <fileN>"
    exit 1
fi

# Create a temporary file to store the merged content
merged_file=$(mktemp)

# Merge all input files into the temporary file
cat "$@" > "$merged_file"

# Display the merged content using less
less "$merged_file"

# Clean up the temporary file
rm "$merged_file"

