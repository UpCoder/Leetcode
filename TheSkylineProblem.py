class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        localtion_height = {}
        for ele in buildings:
            start = ele[0]
            end = ele[1]
            height = ele[2]
            for i in range(start, end+1):
                cur_height = localtion_height.get(i, 0)
                if cur_height == 0:
                    localtion_height[i] = height
                else:
                    localtion_height[i] = max(height, cur_height)
        keys = localtion_height.keys()
        sorted(keys)
        points = []
        last = -1
        for loc in keys:
            cur_height = localtion_height.get(loc)
            if cur_height > last:
                points.append([loc, cur_height])
                last = cur_height
                continue
            if cur_height < last:
                points.append([loc, cur_height])
                last = cur_height
                continue
            if cur_height == last:
                continue
        return points


if __name__ == '__main__':
    solution = Solution()
    buildings=[[2, 9, 10], [3, 7, 15], [5, 12, 12], [15, 20, 10], [19, 24, 8]]
    print(solution.getSkyline(buildings))
