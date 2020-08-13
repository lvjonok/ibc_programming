import time, itertools

numbers = input().split()

t1 = time.time()

for perm in itertools.permutations(numbers, len(numbers)):
    print(" ".join(perm))

t2 = time.time()
print('Time is', t2 - t1) # 2.54 secs for 8 values