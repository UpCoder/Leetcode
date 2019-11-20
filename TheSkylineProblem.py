class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        if len(buildings) == 0:
            return []
        localtion_height = {}
        for ele in buildings:
            start = ele[0]
            end = ele[1]
            height = ele[2]
            flag = -1
            for i in range(start, end+1):
                cur_height = localtion_height.get(i, 0)
                localtion_height[i] = max(cur_height, height)
        keys = list(localtion_height.keys())
        sorted(keys)
        points = []
        last = -1
        for loc in range(keys[0], keys[-1] + 1):
            cur_height = localtion_height.get(loc, 0)
            if cur_height == last:
                continue
            if cur_height > last:
                last = cur_height
                points.append([loc, cur_height])
                continue
            if cur_height < last:
                last = cur_height
                # points[-1][1] = cur_height
                points.append([loc-1, cur_height])
                continue
        points.append([keys[-1], 0])
        return points


if __name__ == '__main__':
    solution = Solution()
    buildings = [[2, 9, 10], [3, 7, 15], [5, 12, 12], [15, 20, 10], [19, 24, 8]]
    print(solution.getSkyline(buildings))
