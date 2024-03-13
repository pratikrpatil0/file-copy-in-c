#!/bin/bash

# Check the value of the first command-line argument ($1)
if [ "$1" == 0 ]; then
    echo "No errors found"
elif [ "$1" == 255 ]; then
    echo "Incorrect number of arguments"
elif [ "$1" == 254 ]; then
    echo "Invalid Arguments"
else
    # If the value is not one of the predefined error codes, use perror to display error message
    perror $1
fi
