class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        // var
        int sum = INT_MAX;
        vector<string> result;
        map<string, int> m;
        
        for (int i = 0; i < list1.size(); i++)
            m[list1[i]] = i + 1;
        
        for (int i = 0; i < list2.size(); i++) {
            // var
            int index = m[list2[i]];
        
            if (index == 0)
                continue;
        
            if (index + i < sum) {
                result = vector<string>();
                result.push_back(list2[i]);
                sum = index + i;
            }
            else if (index + i == sum)
                result.push_back(list2[i]);
        }
        return result;
    }
};