class Solution {
private:
    vector<pair<string, int>> tmp;
    void sort(vector<pair<string, int>>& people, int left, int right) {
        int mid = (left + right) >> 1;

        if (left == right) {
            return;
        }
        sort(people, left, mid);
        sort(people, mid + 1, right);
        merge(people, left, mid, right);
    }
    void merge(vector<pair<string, int>>& people, int left, int mid, int right) {
        for (int i = left; i <= right; i++) {
            tmp[i] = people[i];
        }
        for (int i = left, j = left, k = mid + 1; i <= right; i++) {
            if (j == mid + 1) {
                people[i] = tmp[k];
                k++;
            } else if (k == right + 1) {
                people[i] = tmp[j];
                j++;
            } else if (tmp[j].second < tmp[k].second) {
                people[i] = tmp[k];
                k++;
            } else {
                people[i] = tmp[j];
                j++;
            }
        }
    }
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ret;
        vector<pair<string, int>> vp;

        for (int i = 0; i < names.size(); i++) {
            vp.push_back(make_pair(names[i], heights[i]));
        }
        tmp = vp;
        sort(vp, 0, vp.size() - 1);
        for (int i = 0; i < vp.size(); i++) {
            ret.push_back(vp[i].first);
        }

        return ret;
    }
};
