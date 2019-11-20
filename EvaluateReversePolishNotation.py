class Solution(object):
    def do_op(self, a, b, op):
        if op == '+':
            return int(a + b)
        if op == '*':
            return int(a * b)
        if op == '-':
            return int(a - b)
        if op == '/':
            return int(a / b)
        return 0

    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        operator = ['+', '-', '*', '/']
        numbers = []
        for token in tokens:
            if token in operator:
                second = numbers.pop(-1)
                first = numbers.pop(-1)
                numbers.append(self.do_op(first, second, token))
            else:
                numbers.append(int(token))
        return numbers[0]


if __name__ == '__main__':
    solution = Solution()

    print(solution.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]))