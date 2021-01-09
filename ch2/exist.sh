#!/bin/bash 

# Check if the user supplied exactly one argument 
if [ "$#" -ne 1 ]; then 
    echo "You must supply exactly one argument." 
    echo "Example: $0 /etc" 
    exit 1 # Return with value 1 
fi 

# Check if the file/directory exists 
test -e "$1" # Perform the actual test
if [ "$?" -eq 0 ]; then 
    echo "File or directory exists" 
elif [ "$?" -eq 1 ]; then 
    echo "File or directory does not exist" 
    exit 3 # Return with a special code so other
           # programs can use the value to see if a 
           # file dosen't exist
else 
    echo "Unknown return value from test..."
    exit 1 # Unknown error occured, so exit with 1
fi 
exit 0 # If the file or directory exists, we exit 
       # with 0

