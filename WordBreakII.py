class Solution(object):
    # 遍历wordDict 找到合适的顺序，使得其可以组成s
    def wordBreakCore(self, s, wordDict, res, cur_res_list, cur_res_str, garbage_set):
        if s == '':
            res.append(cur_res_list[:])
            return True
        if garbage_set.get(s, 0) == -1:
            return False
        result_flag = False
        for word in wordDict:
            if s.startswith(word):
                cur_res_list.append(word)
                if self.wordBreakCore(s[len(word):], wordDict, res, cur_res_list, cur_res_str + word, garbage_set):
                    result_flag = True
                cur_res_list.pop(-1)
        if not result_flag:
            garbage_set[s] = -1
            return False
        return True

    # 遍历字符串s，找到合适的划分点
    def wordBreakCoreV2(self, s, s_idx, wordDict, res, cur_res_list, cur_res_str, record_res_dict):
        if cur_res_str == s:
            res.append(cur_res_list[:])
            return True, []
        record_res = record_res_dict.get(s_idx, None)
        if record_res is not None:
            results = []
            for l in record_res:
                one_result = cur_res_list[:]
                one_result.extend(l)
                results.append(one_result)
            res.extend(results)
            return True, record_res
        cur_index_result_flag = False
        cur_index_result_array = []
        cur_str = ''
        for i in range(s_idx, len(s)):
            cur_str = cur_str + s[i]
            if cur_str in wordDict:
                cur_res_list.append(cur_str)
                result_flag, result_array = self.wordBreakCoreV2(s, i+1, wordDict, res, cur_res_list,
                                                                 cur_res_str + cur_str, record_res_dict)
                if result_flag:
                    cur_index_result_flag = True
                    if len(result_array) == 0:
                        cur_index_result_array.append([cur_str])
                    else:
                        new_result_array = []
                        for ele in result_array:
                            ele = [cur_str] + ele
                            new_result_array.append(ele)
                        cur_index_result_array.extend(new_result_array)
                cur_res_list.pop(-1)
        if not cur_index_result_flag:
            return False, []
        record_res_dict[s_idx] = cur_index_result_array[:]
        return True, cur_index_result_array[:]

    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        newWordDict = []
        for word in wordDict:
            if word not in s:
                continue
            newWordDict.append(word)
        res = []
        # self.wordBreakCoreV2(s, 0, newWordDict, res, [], "", {})
        self.wordBreakCore(s, newWordDict, res, [], "", {})
        res_str = [' '.join(ele) for ele in res]
        return res_str


if __name__ == '__main__':
    solution = Solution()
    s = 'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa'
    wordDict = ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
    # s = "catsanddog"
    # wordDict = ["cat", "cats", "and", "sand", "dog", "s"]
    result = solution.wordBreak(
        s, wordDict
    )
    print(result)
# "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
# ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]