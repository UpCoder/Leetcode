import numpy as np
class Solution(object):
    # def canCompleteCircuit(self, gas, cost):
    #     """
    #     :type gas: List[int]
    #     :type cost: List[int]
    #     :rtype: int
    #     """
    #     profit = 0
    #     for i in range(len(gas)):
    #         profit = gas[i]
    #         s = i
    #         count_station = 1
    #         while profit >= 0 and count_station <= len(gas):
    #             profit -= cost[s]
    #             if profit < 0:
    #                 break
    #             count_station += 1
    #             s += 1
    #             s = s % len(gas)
    #             profit += gas[s]
    #         if count_station == (len(gas) + 1):
    #             return s
    #     return -1

    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        profit = []
        for station_gas, station_cost in zip(gas, cost):
            profit.append(station_gas - station_cost)
        if np.sum(profit) < 0:
            return -1
        extra = 0.0
        count = 0
        i = 0
        while i < len(gas):
            # 遍历起点
            if count < 0:
                count = 0
            while count < len(gas) and extra >= 0.0:
                extra += profit[(i+count) % len(gas)]
                count += 1
            if extra < 0.0:
                extra -= profit[i]
                count -= 1
                i += 1
                continue
            if count == len(gas):
                return i
        return -1


if __name__ == '__main__':
    solution = Solution()
    gas = [1, 2, 3, 4, 5]
    cost = [3, 4, 5, 1, 2]
    print(solution.canCompleteCircuit(gas, cost))
    gas = [2, 3, 4]
    cost = [3, 4, 3]
    print(solution.canCompleteCircuit(gas, cost))
