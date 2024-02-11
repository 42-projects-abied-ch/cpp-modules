if [ ! -f PmergeMe ]; then
    make
fi

if [ "$#" -ne 1 ]; then
    echo "Usage: ./random_input.sh <n>"
    exit 1
fi

./PmergeMe $(python3 test_script.py $1)