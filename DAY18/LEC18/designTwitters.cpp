#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    int time = 0;

    struct Tweet {
        int id;
        int time;
        Tweet* next;

        Tweet(int id, int time) {
            this->id = id;
            this->time = time;
            this->next = nullptr;
        }
    };

    unordered_map<int, Tweet*> tweets;
    unordered_map<int, unordered_set<int> > followMap;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        Tweet* newTweet = new Tweet(tweetId, time++);

        newTweet->next = tweets[userId];
        tweets[userId] = newTweet;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        priority_queue<pair<int, Tweet*> > pq;

        followMap[userId].insert(userId);

        for(int followee : followMap[userId]) {
            if(tweets[followee] != nullptr) {
                Tweet* tweet = tweets[followee];

                pq.push(make_pair(tweet->time, tweet));
            }
        }

        while(!pq.empty() && result.size() < 10) {
            pair<int, Tweet*> current = pq.top();
            pq.pop();

            Tweet* tweet = current.second;

            result.push_back(tweet->id);

            if(tweet->next != nullptr) {
                pq.push(make_pair(tweet->next->time, tweet->next));
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followMap[followerId].erase(followeeId);
        }
    }
};

int main() {
    Twitter twitter;

    twitter.postTweet(1, 5);

    vector<int> feed1 = twitter.getNewsFeed(1);

    cout << "Feed 1: ";
    for(int x : feed1) {
        cout << x << " ";
    }
    cout << endl;

    twitter.follow(1, 2);

    twitter.postTweet(2, 6);

    vector<int> feed2 = twitter.getNewsFeed(1);

    cout << "Feed 2: ";
    for(int x : feed2) {
        cout << x << " ";
    }
    cout << endl;

    twitter.unfollow(1, 2);

    vector<int> feed3 = twitter.getNewsFeed(1);

    cout << "Feed 3: ";
    for(int x : feed3) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}