class Solution {
public:
    string frequencySort(string s) {
        // var
        string result = "";
        pair<int, int> p[256];
        
        // init
        for (int i = 0; i < 256; i++) {
            p[i].first = i;
            p[i].second = 0;
        }
        for (int i = 0; i < s.length(); i++)
            p[s[i]].second++;
            
        // bubble sort
        for (int i = 0; i < 256; i++) {
            for (int j = 1; j < 256 - i; j++) {
                // var
                int af = p[j - 1].first;
                int bf = p[j].first;
                int as = p[j - 1].second;
                int bs = p[j].second;
                
                if (as > bs || (as == bs && af > bf))
                    swap(p[j - 1], p[j]);
            }
            // add result
            result += string(p[255 - i].second, char(p[255 - i].first));
        }
        return result;
    }
};