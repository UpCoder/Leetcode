import numpy as np


def dfs(graph, used, cur):
    for i in range(len(graph)):
        if i == cur:
            continue
        if used[i] == 0 and graph[cur][i] == 1:
            used[i] = 1
            dfs(graph, used, i)


if __name__ == '__main__':
    send_name = input()
    num_group = int(input())
    names_group = []
    names_lists = []
    name2id = {}
    for i in range(num_group):
        names = input()
        names_list = names.split(',')
        names_lists.append(names_list)
        for name in names_list:
            if name2id.get(name, -1) == -1:
                name2id[name] = len(name2id.keys())
            else:
                continue
    graph = np.zeros([len(name2id.keys()), len(name2id.keys())], np.int8)
    for names_list in names_lists:
        for i in range(len(names_list)):
            for j in range(i+1, len(names_list)):
                graph[name2id[names_list[i]], name2id[names_list[j]]] = 1
                graph[ name2id[names_list[j]], name2id[names_list[i]]] = 1

    used = [0] * len(graph)
    used[name2id[send_name]] = 1
    dfs(graph, used, name2id[send_name])
    print(np.sum(used))