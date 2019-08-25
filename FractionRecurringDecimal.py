class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator < 0 and denominator < 0:
            numerator = -numerator
            denominator = - denominator
        is_neg = False
        if numerator < 0 or denominator < 0:
            is_neg = True
            numerator = abs(numerator)
            denominator = abs(denominator)

        if numerator == 0:
            return "0"
        yushu = []
        shangs = []
        divided = numerator
        record_locations = {}
        exisit_loop = False
        first_flag = True
        while divided != 0:
            if divided > denominator:
                first_flag = False
                new_divided = divided % denominator
                if record_locations.get(divided, -1) != -1:
                    exisit_loop = True
                    break
                shangs.append(
                    divided // denominator
                )
                record_locations[divided] = len(shangs)
                divided = new_divided * 10
            else:
                if first_flag:
                    divided *= 10
                    first_flag = False
                    continue
                first_flag = False
                if record_locations.get(divided, -1) != -1:
                    exisit_loop = True
                    break
                # shangs.append(0)
                divided = divided * 10
                shangs.append(0)
                record_locations[int(divided / 10)] = len(shangs)
        result_str = ""
        if numerator % denominator == 0:
            point_loc = -1
        elif numerator > denominator:
            point_loc = 1
        else:
            point_loc = 0
        if not exisit_loop:
            result_str = result_str + ''.join([str(ele) for ele in shangs])
            if point_loc != -1:
                if point_loc == 0:
                    result_str = '0.' + result_str
                else:
                    result_str = result_str[:len(str(shangs[0]))] + '.' + result_str[len(str(shangs[0])):]
        else:
            loop_start_loc = record_locations.get(divided)-1
            loop_end_loc = len(shangs)
            result_str = '('
            s = loop_start_loc
            while s < loop_end_loc:
                result_str += str(shangs[s])
                s += 1
            result_str = result_str + ')'
            # result_str = '({})'.format(''.join(shangs[loop_start_loc:loop_end_loc]))
            print(result_str)
            s = 0
            perfix = ''
            while s < loop_start_loc:
                perfix += str(shangs[s])
                s += 1
            result_str = perfix + result_str

            if point_loc == 0:
                result_str = '0.' + result_str
            if point_loc == 1:
                result_str = result_str[:len(str(shangs[0]))] + '.' + result_str[len(str(shangs[0])):]
        if is_neg:
            return '-' + result_str
        else:
            return result_str


if __name__ == '__main__':
    solution = Solution()
    print(solution.fractionToDecimal(-2147483648,
                                     -10))