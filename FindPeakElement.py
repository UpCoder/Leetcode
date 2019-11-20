class Solution(object):
    def meet_cond(self, idx, nums):
        if idx == 0 and nums[idx] > nums[1]:
            return True
        if idx == len(nums)-1 and nums[idx-1] < nums[idx]:
            return True
        if nums[idx] > nums[idx-1] and nums[idx] > nums[idx+1]:
            return True
        return False

    def findPeakElementCore(self, l, r, nums):
        if l > r:
            return -1
        mid = int((l + r) / 2)
        if self.meet_cond(mid, nums):
            return mid
        index = self.findPeakElementCore(l, mid-1, nums)
        if index != -1:
            return index
        index = self.findPeakElementCore(mid + 1, r, nums)
        return index

    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # size = len(nums)
        # if size == 1:
        #     return 0
        # l = 0
        # r = size-1
        # if self.meet_cond(l, nums):
        #     return l
        # if self.meet_cond(r, nums):
        #     return r
        # return self.findPeakElementCore(l, r, nums)
        for i in range(len(nums)):
            if self.meet_cond(i, nums):
                return i
        return -1

if __name__ == '__main__':
    solution = Solution()
    print(solution.findPeakElement([1,2,1,3,5,6,4]))