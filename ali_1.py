# -*- coding=utf-8 -*-
import numpy as np

class Result:
    def __init__(self):
        self.path = []
        self.sum = 0.0


def cal_similarity(sentence1, sentence2):
    set_1 = set()
    set_2 = set()
    for word in sentence1:
        set_1.add(word)
    for word in sentence2:
        set_2.add(word)
    intersection = list(set_1.intersection(set_2))
    union = list(set_1.union(set_2))
    return (1.0 * len(intersection)) / (1.0 * len(union))


def dfs(similarities, cur, target, cur_sim_sum, r, path, result_obj):
    if cur == len(similarities):
        if cur_sim_sum > result_obj.sum:
            result_obj.sum = cur_sim_sum
            result_obj.path = path[:]
            # print(result_obj.path)
        return
    for i in range(r + 1):

        cur_used = target + i
        if cur_used >= len(similarities[0]):
            continue
        cur_sim_sum += similarities[cur][cur_used]
        path.append(cur_used)
        dfs(similarities, cur + 1, cur_used + 1, cur_sim_sum, r, path, result_obj)
        cur_sim_sum -= similarities[cur][cur_used]
        # path = path[:-1]
        path.pop(len(path)-1)


def solution(list1, list2, x):
    similarities = np.zeros([len(list1), len(list2)], np.float)
    for idx1, sentence1 in enumerate(list1):
        for idx2, sentence2 in enumerate(list2):
            similarities[idx1][idx2] = cal_similarity(sentence1, sentence2)
    result_obj = Result()
    dfs(similarities, 0, 0, 0.0, x, [], result_obj)
    print(','.join([str(ele) for ele in result_obj.path]))


if __name__ == '__main__':
    result_path = []
    result_sim = 0.0
    list1_input = raw_input().strip()
    list2_input = raw_input().strip()
    x = int(input())
    list1 = list1_input.split(',')
    list2 = list2_input.split(',')
    # print(list1, list2, x)
    solution(list1, list2, x)

