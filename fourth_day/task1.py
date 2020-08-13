import itertools

def get_path_cost(path, matrix, n):
    path_cost = 0
    for i in range(n):
        path_cost += matrix[path[i]][path[(i + 1) % n]]
    return path_cost

n = int(input())

matrix = [[int(num) for num in input().split()] for i in range(n)]

min_path_cost = 320000
for path in itertools.permutations(range(n), n):
    min_path_cost = min(min_path_cost, get_path_cost(path, matrix, n))

print(min_path_cost)