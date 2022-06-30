class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        // var
        int result = 0;
        
        // run
        for (int i = 0; i < points.size(); i++) {
            // var
            map<double, int> m;
            map<double, int>::iterator it;

            for (int j = 0; j < points.size(); j++) {
                if (i == j)
                    continue;
                
                double dist = cal_distance(points[i], points[j]);
                if (m.find(dist) == m.end())
                    m[dist] = 1;
                else
                    m[dist]++;
            }
            
            // sum
            for (it = m.begin(); it != m.end(); it++)
                if (it->second > 1)
                    result += cal_permutation(it->second, 2);
        }
        return result;
    }
    
    double cal_distance(pair<int, int> a, pair<int, int> b) {
        // var
        int dx = a.first - b.first;
        int dy = a.second - b.second;
        
        return dx * dx + dy * dy;
    }
    
    int cal_permutation(int n, int k) {
        if (!n || !k)
            return 1;
            
        // var
        int result = 1;
        
        // run
        for (int i = n - k + 1; i <= n; i++)
            result *= i;
        
        return result;
    }
};