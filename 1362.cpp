class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> ret = { -1, -1 };
        vector<int> nums(2, num + 1);
        nums[1] += 1;
        int min = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> divisors;
            int sqrt = pow(nums[i], 0.5);
            
            for (int j = sqrt; j > -1; j--) {
                if (nums[i] % j == 0) {
                    if ((nums[i] / j) - j < min) {
                        ret[0] = j;
                        ret[1] = nums[i] / j;
                        min = (nums[i] / j) - j;
                    }
                    break;
                }
            }
        }
        
        return ret;
    }
};
