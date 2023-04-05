class RandomizedSet {
private:
    int n = 0;
    unordered_map<int, int*> umap;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (umap.find(val) == umap.end()) {
            int* p = (int*)malloc(sizeof(int));
            *p = val;
            umap[val] = p;
            n++;      
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if (umap.find(val) == umap.end()) {
            return false;
        } else {
            free(umap[val]);
            umap.erase(val);
            n--;
            return true;
        }
    }
    
    int getRandom() {
        int index = 0;
        auto it = umap.begin();

        index = rand() % n;
        for (int i = 0; i < index; i++, it++);


        return *(it->second);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
