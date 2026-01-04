class Twitter {
private:
    int time;
    // userId -> vector of {time, tweetID}
    unordered_map<int, vector<pair<int,int>>> tweets;
    // userId -> set of following
    unordered_map<int, unordered_set<int>> follows;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>result;
        priority_queue<pair<int,int>>pq;
        follows[userId].insert(userId);

        for(int followee: follows[userId]){
            for(auto &tweet: tweets[followee]){
                pq.push(tweet);
            }
        }
        int count = 0;
        while(!pq.empty() && count <10){
            result.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return result;
        
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            follows[followerId].erase(followeeId);
        }
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