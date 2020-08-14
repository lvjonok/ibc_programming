import time

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

def get_path_cost(path, matrix, n):
    path_cost = 0
    for i in range(n):
        path_cost += matrix[path[i]][path[(i + 1) % n]]
    return path_cost

n = int(input())
matrix = [[int(i) for i in input().split()] for j in range(n)]

t1 = time.time()

get_permutations([], [i for i in range(n)])

min_path_cost = 320000

for local_path in perm_answer:
    if local_path[0] != 0: continue
    min_path_cost = min(min_path_cost, get_path_cost(local_path, matrix, n))

print(min_path_cost)

t2 = time.time()
print("Time is", t2 - t1)   # 0.0004sec for 5 cities