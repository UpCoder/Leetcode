# -*- coding=utf-8 -*-
import os
import numpy as np


def count_char(string, t_c):
    return str(string).count(t_c)


def core(pattern_str, input_str, end_pos):
    pattern_str = str(pattern_str)
    if pattern_str.startswith('<'):
        right = pattern_str.find('>')
        pattern_str = pattern_str[1:right] + pattern_str[right+1:]
        return core(pattern_str, input_str)
    if pattern_str.startswith('['):
        right = pattern_str.find(']')
        pattern_str_without = pattern_str[right+1:]
        pattern_str_with = pattern_str[1:right] + pattern_str[right + 1:]
        return core(pattern_str_without, input_str) or core(pattern_str_with, input_str)
    jiankuohu = pattern_str.find('<')
    zhonghuohu = pattern_str.find('[')
    shuxian = pattern_str.find('|')
    for i in range(len(pattern_str)):
        if shuxian == -1 and pattern_str[i] != input_str[i]:
            return False
        # if pattern_str[i] != input_str[i] and shuxian > zhonghuohu and shuxian > jiankuohu:
        #     return False
        if shuxian != -1 and count_char(pattern_str[:shuxian], '<') == count_char(pattern_str[:shuxian], '>') \
                and count_char(pattern_str[:shuxian], '[') == count_char(pattern_str[:shuxian], ']'):
            if jiankuohu == -1:
                jiankuohu = len(pattern_str) + 1
            if zhonghuohu == -1:
                zhonghuohu = len(pattern_str) + 1

            # sub_str = pattern_str[:min(jiankuohu, zhonghuohu)]
            return core(pattern_str[shuxian:], input_str) or core()
            sub_str = pattern_str[:jiankuohu]
            sub_str_splited = sub_str.split('|')
            result_flag = False
            for ele in sub_str_splited:
                result_flag = result_flag or core(ele + pattern_str[min(jiankuohu, zhonghuohu):], input_str)
                if result_flag:
                    return result_flag
            return False
        if pattern_str[i] == input_str[i]:
            continue
        elif pattern_str[i] == '[' or pattern_str[i] == '<':
            return core(pattern_str[i:], input_str[i:])
        else:
            return False
    return True


def solution(pattern_str, input_str):
    if input_str.find('@{singer}') == -1:
        return False
    pattern_str_splited = pattern_str.split('@{singer}')
    input_str_splited = input_str.split('@{singer}')
    first_part = core(pattern_str_splited[0], input_str_splited[0])
    print(first_part)
    second_part = core(pattern_str_splited[1], input_str_splited[1])
    print(second_part)
    return first_part and second_part


if __name__ == '__main__':
    pattern = input()
    input_str = input()
    print(solution(pattern, input_str))

# <[播]放|来>[一|几]<首|曲|个>@{singer}的<歌[曲]|[流行]音乐>
# 来几首@{singer}的流行音乐

