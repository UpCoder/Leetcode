class Solution(object):
    def findMissingRanges(self, nums, lower, upper):
        low = lower - 1
        result = []
        nums.append(upper + 1)
        for num in nums:
            diff = num - low
            if diff == 2:
                result.append('{}'.format(num-1))
            elif diff > 2:
                result.append('{}->{}'.format(low + 1, num-1))
            low = num
        return result


    def findMissingRangesV3(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """
        l = lower
        r = lower
        result = []
        flag_dict = {}
        for num in nums:
            flag_dict[num] = 1
        while r <= upper:
            if flag_dict.get(r, 0) == 1:
                if l == r:
                    r += 1
                    l += 1
                    continue
                if (r-1) == l:
                    result.append('{}'.format(l))
                    l = r + 1
                    r = r + 1
                    continue
                result.append('{}->{}'.format(l, r-1))
                l = r + 1
                r = r + 1
                continue
            else:
                r += 1
        if upper not in nums:
            if (r-1) != l:
                result.append('{}->{}'.format(l, r-1))
            else:
                result.append('{}'.format(l))
        return result

    def findMissingRangesV2(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """
        all_nums = range(lower, upper+1)
        all_nums_set = set(all_nums)
        nums_set = set(nums)
        missing_values = list(all_nums_set - nums_set)
        print(missing_values)
        if len(missing_values) == 0:
            return []
        result = []
        start_v = missing_values[0]
        last_v = start_v
        for m_v in missing_values[1:]:
            if m_v == (last_v + 1):
                last_v = m_v
                continue
            if last_v == start_v:
                result.append('{}'.format(start_v))
                start_v = m_v
                last_v = m_v
                continue
            else:
                result.append('{}->{}'.format(start_v, last_v))
                start_v = m_v
                last_v = m_v
                continue
        return result


if __name__ == '__main__':
    solution = Solution()
    print(solution.findMissingRanges([0, 1, 3, 50, 75], 0, 99))