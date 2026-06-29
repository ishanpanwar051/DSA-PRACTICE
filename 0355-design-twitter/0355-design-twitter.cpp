class Twitter {
public:

int timer;

unordered_map<int,unordered_set<int>>followMap;
unordered_map<int,vector<pair<int,int>>>tweets;

    Twitter() {
timer = 0;

    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId] .push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;

        for(auto &x:tweets[userId]) pq.push(x);

        for(int user:followMap[userId]){
            for(auto &x : tweets[user])
            pq.push(x);
        }
        vector<int>ans;

        while(!pq.empty() && ans.size()<10){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;

        followMap[followerId].insert(followeeId);

    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
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