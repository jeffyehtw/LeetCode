bool compare(pair<int, int> x, pair<int, int> y) {
    return x.first > y.first || (x.first == y.first) && x.second < y.second;
}

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        // var
        vector<pair<int, int>> result;
        
        sort(people.begin(), people.end(), compare);
        
        for (int i = 0; i < people.size(); i++) {
            result.insert(result.begin() + people[i].second, people[i]);
        }
        
        return result;
    }
};