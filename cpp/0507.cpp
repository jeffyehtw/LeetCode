class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 1 + num;
        vector<int> divisors = { num, 1 };

        if (num == 1) {
            return false;
        }

        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                if ((num / i) == divisors.back()) {
                    break;
                }
                divisors.push_back(num / i);
                divisors.push_back(i);
                sum += (num / i);
                sum += i;
            }
        }
    
        return sum == num * 2;
    }
};
