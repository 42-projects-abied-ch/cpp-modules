import random
import sys
import subprocess
import os

def generate_random_numbers(n, range_start=1, range_end=100):
    return random.sample(range(range_start, range_end + 1), n)

if __name__ == "__main__":
	if len(sys.argv) < 2 or len(sys.argv) > 3:
		print("Usage: python script.py <n> [-v, --valgrind]")
		sys.exit(1)
	if os.path.isfile("./PmergeMe") is False:
		subprocess.run("make")
	n = int(sys.argv[1])
	if len(sys.argv) == 3:
		if sys.argv[2] == "-v" or sys.argv[2] == "--valgrind":
			args = ["valgrind", "./PmergeMe"]
		else:
			print("Usage: python script.py <n> [-v, --valgrind]")
			sys.exit(1)
	else:
		args = ["./PmergeMe"]
	random_numbers = generate_random_numbers(n)
	random_numbers_str = [str(num) for num in random_numbers]
	subprocess.run(args + random_numbers_str)