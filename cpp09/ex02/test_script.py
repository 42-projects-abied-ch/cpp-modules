import random
import sys
import subprocess

def generate_random_numbers(n, range_start=1, range_end=2147483647):
    return random.sample(range(range_start, range_end + 1), n)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <n>")
        sys.exit(1)

    n = int(sys.argv[1])
    random_numbers = generate_random_numbers(n)
    random_numbers_str = [str(num) for num in random_numbers]
    subprocess.run(["./PmergeMe"] + random_numbers_str)