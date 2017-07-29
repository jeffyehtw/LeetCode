class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        // var
        int diff = 1;
        sort(candies.begin(), candies.end());
        
        for (int i = 1; i < candies.size(); i++) {
            if (candies[i - 1] != candies[i])
                diff++;
        }
        
        return min(diff, int(candies.size() / 2));
    }
};