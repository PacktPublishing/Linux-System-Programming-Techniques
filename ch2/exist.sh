#!/bin/bash 

# Check if the user supplied exactly one argument 
if [ "$#" -ne 1 ]; then 
    echo "You must supply exactly one argument." 
    echo "Example: $0 /etc" 
    exit 1 # Return with value 1 
fi 

# Check if the file/argument exists 
test -e "$1" # Perform the actual test
if [ "$?" -eq 0 ]; then 
    echo "File or directory exists" 
elif [ "$?" -eq 1 ]; then 
    echo "File or directory does not exist" 
else 
    echo "Unknown return value from test..." 
fi 
exit 0 # Return with value 0

