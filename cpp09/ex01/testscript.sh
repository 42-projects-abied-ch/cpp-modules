#!/bin/bash

if [ ! -f RPN ]; then
    make
fi

while IFS= read -r line
do
    IFS=':' read -ra parts <<< "$line"
    testcase="${parts[0]}"
    expected_output="${parts[1]}"
    expected_exit_code="${parts[2]}"
    actual_output=$(./RPN "$testcase")
    exit_code=$?
    bold="\033[1m"
    printf "$bold\"$testcase\"$reset\nExpected: $expected_output - Result: $actual_output\n"

    if [ "$actual_output" == "$expected_output" ]; then
        printf "Output: ✅ | "
    else
        printf "Output: ❌ |"
    fi
    if [ "$exit_code" == "$expected_exit_code" ]; then
        printf "Exit code: ✅\n\n"
    else
        printf "Exit code: ❌\n\n"
    fi
	sleep 0.05
done < testcases.txt



