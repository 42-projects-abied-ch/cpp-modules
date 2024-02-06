#!/bin/bash

if [ ! -f RPN ]; then
    make
fi

input1="8 9 * 9 - 9 - 9 - 4 - 1 +"
input2="7 7 * 7 -"
input3="1 2 * 2 / 2 * 2 4 - +"
input4="(1 + 1)"
input5="1 2 3 4 5 6 7 8 9 10 + + + + + + + + +"
input6="1 2 3 4 5 6 7 8 9 10"
input7="1 3 + +"
input8="1 3 + 2 *"
input9="1 3 + 2 * 4 /"
input10="1 3 + 2 * 4 / 5 -"

#!/bin/bash

expected_output1="42"

# Convert the string to an array
input1=($input1)

# Get the actual output
actual_output=$(./RPN "${input1}")
./RPN "${input1}"
echo "Test 1"
echo "Expected: $expected_output1"
echo "Result: $actual_output"

# Check if the actual output matches the expected output
if [ "$actual_output" == "$expected_output1" ]; then
    echo "Test 1 was successful."
else
    echo "Test 1 failed."
fi



