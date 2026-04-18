#ifndef Channel_H
#define Channel_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "video.h" 


class Subscriber;

using namespace std;

class Channel
{
private:
    string channelName;
    int accountNumber;
    int subcribeCount;
    vector<Subscriber *> subscribers;
    vector<video *> videos;

public:
    Channel(string name, int accountNumber) : channelName(name), accountNumber(accountNumber), subcribeCount(0)
    {
    }

    void uploadVideos(video *vid)
    {
        videos.push_back(vid);
    }
    vector<Subscriber *> getSubScribers()
    {
        return subscribers;
    }

    vector<video *> getVidoes()
    {
        return videos;
    }

    string getChannelName()
    {
        return channelName;
    }

    int getSubcriberCount()
    {
        return subcribeCount;
    }

    void incrementSubriber()
    {
        subcribeCount++;
    }

    string getLatestVideo()
    {
        if (!videos.empty())
        {
            return videos.back()->getTitle();
        }
        return "No videos yet";
    }

    void subscirbe(Subscriber *subscriber)
    {
        if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end())
        {
            subscribers.push_back(subscriber);
            incrementSubriber();
        }
    }

    bool isSubcribe(Subscriber *subscriber)
    {
        return find(subscribers.begin(), subscribers.end(), subscriber) != subscribers.end();
    }

    void unSubcribes(Subscriber *subscriber)
    {
        subscribers.erase(remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
        if (subcribeCount > 0)
        {
            subcribeCount--;
        }
    }
};

#endif