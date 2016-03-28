#pragma once
#include "stdafx.h"

//Implement a simple twitter.Support the following method :
//
//  - postTweet(user_id, tweet_text).Post a tweet.
//
//  - getTimeline(user_id).Get the given user's most recently 10 tweets posted by himself, 
//      order by timestamp from most recent to least recent.
//
//  - getNewsFeed(user_id).Get the given user's most recently 10 tweets in his news feed 
//    (posted by his friends and himself). Order by timestamp from most recent to least recent.
//  
//  - follow(from_user_id, to_user_id).from_user_id followed to_user_id.
//
//  - unfollow(from_user_id, to_user_id).from_user_id unfollowed to to_user_id.

namespace lintcode
{
    class Tweet
    {
    public:
        Tweet(int user, string text)
            :user_id(user), tweet_text(text)
        {
        }

        int id;
        int user_id;
        string tweet_text;

        static Tweet create(int user, string text)
        {
            return{ user, text };
        }
    };

    // post mode
    class MiniTwitter {
    public:
        MiniTwitter()
        {
            // initialize your data structure here.
        }

        // @param user_id an integer
        // @param tweet a string
        // return a tweet
        Tweet postTweet(int user_id, string tweet_text)
        {
            Tweet post = Tweet::create(user_id, tweet_text);

            // post to self time line
            mapTimeLine[user_id].push_back(post);

            // post to self news feeds
            mapNewsFeeds[user_id].push_back(post);

            // write to followed by user news feeds
            for (int follower : mapFollowedBy[user_id])
            {
                mapNewsFeeds[follower].push_back(post);
            }

            return post;
        }

        // @param user_id an integer
        // return a list of 10 new feeds recently
        // and sort by timeline
        vector<Tweet> getNewsFeed(int user_id)
        {
            // Write your code here
            vector<Tweet>& allNewsFeed = mapNewsFeeds[user_id];
            vector<Tweet> result;
            int count = 0;

            for (int i = allNewsFeed.size() - 1; i >= 0 && count++ < 10; i--)
            {
                result.push_back(allNewsFeed[i]);
            }

            return result;
        }

        // @param user_id an integer
        // return a list of 10 new posts recently
        // and sort by timeline
        vector<Tweet>  getTimeline(int user_id)
        {
            // Write your code here
            vector<Tweet>& allTimeLine = mapTimeLine[user_id];
            vector<Tweet> result;
            int count = 0;

            for (int i = allTimeLine.size() - 1; i >= 0 && count++ < 10; i--)
            {
                result.push_back(allTimeLine[i]);
            }

            return result;
        }

        // @param from_user_id an integer
        // @param to_user_id an integer
        // from user_id follows to_user_id
        void follow(int from_user_id, int to_user_id)
        {
            // Write your code here
            if (from_user_id == to_user_id)
                return;

            // to_user_id is followed by from_user_id now.
            mapFollowedBy[to_user_id].insert(from_user_id);

            // get the to_user_id new feeds
            const vector<Tweet>& feeds = getTimeline(to_user_id);
            mapNewsFeeds[from_user_id].insert(mapNewsFeeds[from_user_id].end(), feeds.begin(), feeds.end());

        }

        // @param from_user_id an integer
        // @param to_user_id an integer
        // from user_id unfollows to_user_id
        void unfollow(int from_user_id, int to_user_id)
        {
            if (from_user_id == to_user_id)
                return;

            // to_user_id is no longer followed by from_user_id
            mapFollowedBy[to_user_id].erase(from_user_id);
            
            // update the from_user_id news feeds.
            vector<Tweet>& feeds = mapNewsFeeds[from_user_id];
            feeds.erase(std::remove_if(feeds.begin(), feeds.end(), [&](const Tweet& t) {
                return t.user_id == to_user_id;
            }), feeds.end());
        }
    private:
        unordered_map<int, vector<Tweet>> mapTimeLine;
        unordered_map<int, vector<Tweet>> mapNewsFeeds;

        // to_user_id, list of from_user_id
        unordered_map<int, unordered_set<int>> mapFollowedBy;
    };
}