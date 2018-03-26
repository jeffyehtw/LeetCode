class Solution {
public:
    int compress(vector<char>& chars) {
        // var
        int index = 0;
        
        while (index < chars.size()) {
            // var
            int count = 1;
            int next = index + 1;
            
            while (index + 1 < chars.size() && chars[index] == chars[index + 1]) {
                chars.erase(chars.begin() + index + 1);
                count++;
            }
            
            if (count == 1) {
                index = next;
                continue;
            }
            
            while (count) {
                chars.insert(chars.begin() + index + 1, '0' + count % 10);
                count /= 10;
                next++;
            }
            
            index = next;
        }
        return chars.size();
    }
};
