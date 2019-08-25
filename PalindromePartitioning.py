import numpy as np


class Solution:
    def is_huiwen(self, s):
        for i in range(len(s) // 2):
            if s[i] != s[len(s)-i-1]:
                return False
        return True

    def core(self, flag, x, path_str, res, n, s):
        '''

        :param flag:
        :param x:
        :param path_str:
        :param res:
        :return:
        '''
        if x == n:
            res.append(path_str[:])
            return
        for y in range(x, n):
            if flag[x, y]:
                path_str.append(s[x:(y+1)])
                flag[x, y] = False
                self.core(flag, y+1, path_str, res, n, s)
                path_str.pop(len(path_str)-1)
                # flag[x, y] = True

    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        len_s = len(s)
        flag = np.asarray([[False] * len_s] * len_s)
        for i in range(len(s)):
            for j in range(i, len(s)):
                flag[i, j] = self.is_huiwen(s[i:j+1])

        res = []
        path_str = []
        self.core(flag, 0, path_str, res, len_s, s)
        return res


if __name__ == '__main__':
    solution = Solution()
    res = solution.partition('seeslaveidemonstrateyetartsnomedievalsees')
    print(res)
