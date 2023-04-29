class Twitter {
private:
    vector<vector<bool>> connect;
    vector<pair<int, int>> tweets;
public:
    Twitter() {
        connect = vector<vector<bool>>(10001, vector<bool>(10001, false));
        for (int i = 0; i < connect.size(); i++) {
            connect[i][i] = true;
        }
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back(make_pair(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;

        for (int i = tweets.size() - 1; (i > -1) && ret.size() < 10; i--) {
            if (connect[userId][tweets[i].first]) {
                ret.push_back(tweets[i].second);
            }
        }

        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        connect[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        connect[followerId][followeeId] = false;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
