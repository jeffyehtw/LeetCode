class Solution {
public:
    string intToRoman(int num) {
        // var
        string result;
        const string THOUSAND[] = {"", "M", "MM", "MMM"};
        const string HUNDRED[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        const string TEN[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        const string ONE[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        result += THOUSAND[(num / 1000) % 10];
        result += HUNDRED[(num / 100) % 10];
        result += TEN[(num / 10) % 10];
        result += ONE[num % 10];
        
        return result;
    }
};