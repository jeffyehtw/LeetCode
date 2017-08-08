class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        // var
        vector<int> x = parse(a);
        vector<int> y = parse(b);
        
        // cal
        int real = x[0] * y[0] - x[1] * y[1];
        int complex = x[0] * y[1] + x[1] * y[0];
        
        return to_string(real) + "+" + to_string(complex) + "i";            
    }
private:
    vector<int> parse(string var) {
        // var
        int index = var.find('+');
        return vector<int>({
            stoi(var.substr(0, index)),
            stoi(var.substr(index + 1, var.length() - index - 1))
        });
    }
};