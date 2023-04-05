class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // var
        int result = 0;
        unordered_map<int, int> ab;
        unordered_map<int, int> cd;
        
        // init
        fill_map(A, B, ab);
        fill_map(C, D, cd);
        
        for(auto i = ab.begin(); i != ab.end(); i++) {
           auto j = cd.find(-i->first);
           if(j != cd.end())
             result += i->second * j->second;
        }
        
        return result;
    }
    
    void fill_map(vector<int>& A, vector<int>& B, unordered_map<int, int>& m) {
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B.size(); j++)
                m[A[i] + B[j]]++;
    }
};