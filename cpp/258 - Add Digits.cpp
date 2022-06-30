class Solution {
public:
    int addDigits(int num) {
        if (num >= 10) {
            // var
            int temp = num % 9;
            
            if (temp == 0)
                return 9;
            return temp;
        }
        else
            return num;
    }
};