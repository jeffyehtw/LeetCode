class LRUCache {
private:
    int c;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> umap;
public:
    LRUCache(int capacity) {
        c = capacity;
        cache.clear();
        umap.clear();
    }
    
    int get(int key) {
        if (umap.find(key) == umap.end()) {
            return -1;
        } else {
            auto item = *umap[key];
            cache.erase(umap[key]);
            cache.push_front(item);
            umap[key] = cache.begin();
            return item.second;
        }
    }
    
    void put(int key, int value) {
        if (umap.find(key) == umap.end()) {
            if (cache.size() == c) {
                cout << "erase " << cache.back().first << endl;
                umap.erase(cache.back().first);
                cache.pop_back();
            }
        } else {
            cache.erase(umap[key]);
        }
        cache.push_front(make_pair(key, value));
        umap[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
