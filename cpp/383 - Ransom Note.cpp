class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // var
        vector<int> m(127, 0);
        vector<int> r(127, 0);
        
        // init
        for (int i = 0; i < magazine.length(); i++)
            m[magazine[i]]++;
            
        // run
        for (int i = 0; i < ransomNote.length(); i++)
            if (++r[ransomNote[i]] > m[ransomNote[i]])
                return false;
        return true;
    }
};