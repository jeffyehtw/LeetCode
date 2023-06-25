class UF {
private:
    int cnt;
    vector<int> sizes;
    vector<int> parent;
    int find(int p) {
        while (parent[p] != p) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
public:
    UF (int n) {
        cnt = n;
        parent = vector<int>(n, 0);
        sizes = vector<int>(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    bool connected(int p, int q) {
        return (find(p) == find(q));
    }
    void join(int p, int q) {
        int rootp = find(p);
        int rootq = find(q);

        if (rootp == rootq) {
            return;
        }
        if (sizes[rootp] < sizes[rootq]) {
            parent[rootp] = rootq;
            sizes[rootp] += sizes[rootq];
        } else {
            parent[rootq] = rootp;
            sizes[rootq] += sizes[rootp];
        }
        cnt--;
    }
    int count() {
        return cnt;
    }
};

class Solution {   
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        int ret = 0;
        UF uf(n + 1);

        sort(connections.begin(), connections.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        for (int i = 0; i < connections.size(); i++) {
            int src = connections[i][0];
            int dst = connections[i][1];
            int cost = connections[i][2];

            if (uf.connected(src, dst)) {
                continue;
            }
            ret += cost;
            uf.join(src, dst);
        }

        return (uf.count() == 2) ? ret : -1;
    }
};
