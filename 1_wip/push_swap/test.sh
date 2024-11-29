#!/bin/bash

echo "Running Makefile"
make re

#if the exit code of the previous command is not 0, then…
if [ $? -ne 0 ]; then
    exit 1;
fi

MAX=500  # Set the max size for the descending list
COUNT=0
echo "testing list with descending elements with an increasing size (max size = $MAX):"
for ((i = 2; i <= MAX; i++)); do
    INPUT=""
    for ((j = i; j > 0; j--)); do
        INPUT="$INPUT$j "
    done
    
    RESULT=$(./push_swap $INPUT | ./checker_linux $INPUT)
    if [ "$RESULT" == "KO" ]; then
        ((COUNT++))
        echo "[ $i - 1 ]"
        echo -e "\e[31m× KO\e[0m"  # Red small cross for KO
        echo "-------------------------------------------"
    else
        if [ "$RESULT" != "OK" ]; then
            echo "Error"
            echo "-------------------------------------------"
        fi
    fi
done
if [ $COUNT -eq 0 ]; then
    echo -e "\e[32mALL TESTS ✓ OK\e[0m"  # Green plain checkmark for OK
fi
echo "*** End of tests ***"
