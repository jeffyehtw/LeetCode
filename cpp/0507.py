class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        i = 2
        sum = 1
        divisors = [1]

        if num <= 2:
            return False

        while i * i < num:
            if num % i == 0:
                if i not in divisors:
                    divisors.append(i)
                    sum += i
                if num / i not in divisors:
                    divisors.append(num / i)
                    sum += num / i

            i = i + 1
        
        return num == sum

