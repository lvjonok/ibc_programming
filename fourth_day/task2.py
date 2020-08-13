import time, itertools

perm_answer = []

def get_permutations(array, left_values):
    answer = []
    if left_values:
        for new_value in left_values:
            new_array = array + [new_value]
            new_left = left_values[:]
            new_left.remove(new_value)
            answer.append(get_permutations(new_array, new_left))
        return answer
    else:
        global perm_answer
        perm_answer.append(array)
        return array

numbers = input().split()

t1 = time.time()

get_permutations([], numbers)
for perm in perm_answer:
    print(" ".join(perm))

t2 = time.time()
print('Time is', t2 - t1) # 2.54 secs for 8 values
