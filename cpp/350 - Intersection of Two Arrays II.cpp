class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // init
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // var
        vector<int> result(nums1.size() + nums2.size());
        vector<int>::iterator it;
        
        it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), result.begin());
        result.resize(it - result.begin());

        return result;
    }
    
    void remove_duplicate(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ) {
            if (nums[i - 1] == nums[i])
                nums.erase(nums.begin() + i);
            else
                i++;
        }
    }
};