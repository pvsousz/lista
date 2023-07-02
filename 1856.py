N = int(input())
initial_list = list(map(int, input().split()))
Q = int(input())

enemy_list = []
enemy_indices = {}


for i, enemy in enumerate(initial_list):
    enemy_list.append(enemy)
    enemy_indices[enemy] = i


for _ in range(Q):
    operation = input().split()
    if operation[0] == 'I':
        p, e = map(int, operation[1:])
        idx = enemy_indices[e]
        enemy_list.insert(idx + 1, p)
        for enemy in enemy_list[idx + 2:]:
            enemy_indices[enemy] += 1
        enemy_indices[p] = idx + 1
    elif operation[0] == 'R':
        e = int(operation[1])
        idx = enemy_indices[e]
        enemy_list.pop(idx)
        for enemy in enemy_list[idx:]:
            enemy_indices[enemy] -= 1
        del enemy_indices[e]
    elif operation[0] == 'Q':
        a, b = map(int, operation[1:])
        idx_a = enemy_indices[a]
        idx_b = enemy_indices[b]
        result = abs(idx_b - idx_a) - 1
        print(result)
