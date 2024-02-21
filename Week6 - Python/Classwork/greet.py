# 1
from sys import argv

if len(argv) != 2:
    print("Wrong command line")
else:
    print(f"Hello, {argv[1]}")

# Command line
# python greet.py Jill
# xxxxxx argv[0]  argv[1]

# 2
import sys

if len(sys.argv) != 2:
    print("Wrong command line")
    sys.exit(1) # 如同C語言的 return 1;

print(f"Hello, {sys.argv[1]}")
sys.exit(0)
