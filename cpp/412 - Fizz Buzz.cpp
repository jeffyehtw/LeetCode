class Solution {
public:
    vector<string> fizzBuzz(int n) {
        // var
        vector<string> result;
        
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0)
                result.push_back("FizzBuzz");
            else 
                result.push_back(i % 3 == 0 ? "Fizz" : i % 5 == 0 ? "Buzz" : to_string(i));
        }
        
        return result;
    }
};