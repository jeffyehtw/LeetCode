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
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UF uf(n);

        for (int i = 0; i < edges.size(); i++) {
            if (uf.connected(edges[i][0], edges[i][1])) {
                return false;
            }
            uf.join(edges[i][0], edges[i][1]);
        }

        return (uf.count() == 1);
    }
};
