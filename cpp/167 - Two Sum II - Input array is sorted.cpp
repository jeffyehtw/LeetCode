class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // var
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> result;

        while (left < right) {
            
            cout << left << " " << right << endl;
            // var
            int sum = numbers[left] + numbers[right];

            if (sum == target)
                return vector<int>({ left + 1, right + 1 });
            else if (sum > target)
                right--;
            else
                left++;
        }
        return vector<int>();
    }
};