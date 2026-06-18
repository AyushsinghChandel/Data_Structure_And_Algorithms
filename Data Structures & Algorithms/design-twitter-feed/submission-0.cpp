class Twitter {
    private:
    int time;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;

        for(auto& tweet : tweets[userId]){
            maxHeap.push(tweet);
        }

        for(auto& followId : following[userId]){
            for(auto& tweet : tweets[followId]){
                maxHeap.push(tweet);
            }
        }

        vector<int> feed;
        while(!maxHeap.empty() && feed.size() < 10){
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
