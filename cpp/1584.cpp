class UF {
private:
    int cnt;
    vector<int> parent;
    vector<int> size;
    int find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
public:
    UF (int n) {
        cnt = n;
        parent = vector<int>(n, 0);
        size = vector<int>(n, 1);
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
        if (size[rootp] < size[rootq]) {
            parent[rootp] = rootq;
            size[rootq] += size[rootp];
        } else {
            parent[rootq] = rootp;
            size[rootp] += size[rootq];
        }
        cnt--;
    }
    int count() {
        return cnt;
    }
};

class Solution {
private:
    int distance(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ret = 0;
        int n = points.size();
        UF uf(n);
        vector<vector<int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i == j) {
                    continue;
                }
                edges.push_back({ 
                    i, 
                    j, 
                    distance(points[i], points[j])
                });
            }
        }
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        for (int i = 0; (i < edges.size()) && (uf.count() > 1); i++) {
            if (uf.connected(edges[i][0], edges[i][1])) {
                continue;
            }
            ret += edges[i][2];
            uf.join(edges[i][0], edges[i][1]);
        }

        return (uf.count() == 1) ? ret : -1;
    }
};
