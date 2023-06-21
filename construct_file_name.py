import sys

args = sys.argv[1:]
file_name = args[0].split(".")[0]

for arg in args[0].split(".")[-1].split():
    file_name += "_" + arg

print(file_name + ".cpp")