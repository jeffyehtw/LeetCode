class Logger {
private:
    unordered_map<string, int> umap;
public:
    Logger() {
        umap.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (umap.find(message) == umap.end()) {
            umap[message] = timestamp + 10;
            return true;
        } else {
            if (timestamp < umap[message]) {
                return false;
            } else {
                umap[message] = timestamp + 10;
                return true;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
