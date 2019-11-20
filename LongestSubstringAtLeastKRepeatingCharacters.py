class Solution:
    def longestSubstring(self, s, k):
        counter = [0 for x in range(26)]
        for i in range(len(s)):
            counter[ord(s[i]) - ord('a')] += 1

        lo = 0
        hi = len(s)-1
        while lo<=hi:

            while lo<=hi and 0<counter[ord(s[lo])-ord('a')]<k :
                counter[ord(s[lo])-ord('a')]-=1
                lo+=1
            while  hi>=lo and 0<counter[ord(s[hi])-ord('a')]<k :
                counter[ord(s[hi])-ord('a')]-=1
                hi-=1

            if self.check(counter,k) == True:
                return hi-lo+1
            lo1=lo
            hi1=hi
            while lo <= hi:
                if counter[ord(s[hi])-ord('a')]<k:
                    lo=lo1
                    while hi1>hi:
                        counter[ord(s[hi1])-ord('a')]-=1
                        hi1-=1
                    break
                if counter[ord(s[lo])-ord('a')]<k:
                    hi=hi1
                    while lo1<lo:
                        counter[ord(s[lo1])-ord('a')]-=1
                        lo1+=1
                    break
                hi-=1
                lo+=1

        return 0

    def check(self, counter, k):

        for i in counter:
            if 0<i<k:
                return False
        return True


if __name__ == '__main__':
    solution = Solution()
    print(solution.longestSubstring('caaaacac', 4))