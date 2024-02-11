import random
import sys
from datetime import datetime, timedelta

def random_date(start, end):
    return start + timedelta(seconds=random.randint(0, int((end - start).total_seconds())))

start = datetime(2008, 1, 1)
end = datetime(2030, 12, 31)

num_lines = int(sys.argv[1]) if len(sys.argv) > 1 else 100000

with open('inputs/large_test_file.csv', 'w') as test_file:
    test_file.write("date | value\n")
    for _ in range(num_lines):
        if random.choice([True, False]):
            date = random_date(start, end)
            value = random.randint(0, 1000)
            test_file.write(f"{date.strftime('%Y-%m-%d')} | {value}\n")
        else:
            year = random.randint(2000, 2030)
            month = random.randint(1, 20)
            day = random.randint(1, 40)
            value = random.randint(-1000, 2000)
            test_file.write(f"{year}-{month:02d}-{day:02d} | invalid\n")