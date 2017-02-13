class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;

        // fix  
        while (nums1.size() > m)
            nums1.pop_back();
        while (nums2.size() > n)
            nums2.pop_back();
        
        // run  
        for (int i = 0; i < nums1.size() && nums2.size(); i++) {
            while (nums2[0] < nums1[i]) {
                nums1.insert(nums1.begin() + i, nums2[0]);
                nums2.erase(nums2.begin());
            }
        }
        
        // rest
        for (int k = 0; k < nums2.size(); k++)
            nums1.push_back(nums2[k]);
    }
};