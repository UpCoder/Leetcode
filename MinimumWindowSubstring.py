import numpy as np
import collections


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        dict_t = collections.Counter(t)
        print(dict_t)
        l = r = 0
        target_len = len(t)
        find_len = 0
        dict_f = {}
        res = ""
        while r < len(s):
            c = s[r]
            if dict_t.get(c, 0) != 0:
                dict_f[c] = dict_f.get(c, 0) + 1
                if dict_f[c] <= dict_t[c]:
                    find_len += 1
            r += 1
            while l <= r and find_len == target_len:
                cur_res = s[l:r]
                if res == "" or len(res) > len(cur_res):
                    res = cur_res
                c = s[l]
                if dict_f.get(c, 0) != 0:
                    dict_f[c] -= 1
                    if dict_f[c] < dict_t[c]:
                        find_len -= 1
                l += 1
        return res


if __name__ == '__main__':
    print('ok')
    solution = Solution()
    s = "ADOBECODEBANC"
    t = "ABC"
    print(solution.minWindow(s, t))