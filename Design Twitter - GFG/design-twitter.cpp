//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Twitter {
  public:
    // Initialize your data structure here
    unordered_map<int,set<int>>following;
    unordered_map<int,vector<pair<int,int>>>tweets;
    long long time;
    Twitter() {
        time=0;
    }

    // Compose a new tweet
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }

    // Retrieve the 10 most recent tweet ids as mentioned in question
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>>pq;
        
        for(auto it: tweets[userId])    pq.push(it);
        for(auto it: following[userId])
            for(auto jt: tweets[it])    pq.push(jt);
            
        while(!pq.empty() && res.size()<10){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    // Follower follows a followee. If the operation is invalid, it should be a
    // no-op.
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    // Follower unfollows a followee. If the operation is invalid, it should be
    // a no-op.
    void unfollow(int followerId, int followeeId){
        following[followerId].erase(followeeId);
    }
};

//{ Driver Code Starts.

int main() {
    Twitter obj;

    int total_queries;
    cin >> total_queries;
    while (total_queries--) {
        int query;
        cin >> query;

        // if query = 1, postTweet()
        // if query = 2, getNewsFeed()
        // if query = 3, follow()
        // if query = 4, unfollow()

        if (query == 1) {
            int userId, tweetId;
            cin >> userId >> tweetId;
            obj.postTweet(userId, tweetId);
        } else if (query == 2) {
            int userId;
            cin >> userId;
            vector<int> vec = obj.getNewsFeed(userId);
            for (int a : vec) cout << a << " ";
            cout << endl;
        } else if (query == 3) {
            int follower, followee;
            cin >> follower >> followee;
            obj.follow(follower, followee);
        } else {
            int follower, followee;
            cin >> follower >> followee;
            obj.unfollow(follower, followee);
        }
    }
    return 0;
}
// } Driver Code Ends