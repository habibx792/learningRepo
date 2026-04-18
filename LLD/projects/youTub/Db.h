#ifndef Database_H
#define Database_H

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "channel.h"
#include "video.h"
#include "subscriber.h"

using namespace std;

class Database
{
private:
    Database()
    {
        cout << "Database connection initialized." << endl;
    }

    string connectionSting;
    unordered_map<Channel *, vector<video *>> videoMap;
    vector<Channel *> channels;
    vector<Subscriber *> subscribers;
    unordered_map<Channel *, vector<Subscriber *>> subscriberMap;

    static Database *instance;

public:
    static Database *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Database();
        }
        return instance;
    }

    void addVideo(Channel *channel, video *vid)
    {
        videoMap[channel].push_back(vid);
    }

    void addChannel(Channel *channel)
    {
        if (find(channels.begin(), channels.end(), channel) == channels.end())
        {
            channels.push_back(channel);
        }
    }

    vector<Channel *> getMonitoredChannels()
    {
        vector<Channel *> monitoredChannels;
        for (auto channel : channels)
        {
            if (channel->getSubcriberCount() >= 5)
            {
                monitoredChannels.push_back(channel);
            }
        }
        return monitoredChannels;
    }

    void addSubscriber(Subscriber *subscriber)
    {
        if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end())
        {
            subscribers.push_back(subscriber);
        }
    }

    void addSubscription(Channel *channel, Subscriber *subscriber)
    {
        subscriberMap[channel].push_back(subscriber);
    }

    Subscriber *getSubscriber(Subscriber *subscriber)
    {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end())
        {
            return *it;
        }
        return nullptr;
    }

    video *getVideo(Channel *channel)
    {
        if (videoMap.find(channel) != videoMap.end() && !videoMap[channel].empty())
        {
            return videoMap[channel].back();
        }
        return nullptr;
    }

    video *getVideo(Channel *channel, string videoTopic, string title)
    {
        if (videoMap.find(channel) == videoMap.end())
            return nullptr;

        vector<video *> &videos = videoMap[channel];
        for (video *vid : videos)
        {
            if (vid && vid->videoTopic() == videoTopic && vid->getTitle() == title)
            {
                return vid;
            }
        }
        return nullptr;
    }

    vector<Subscriber *> getSubscribers(Channel *channel)
    {
        if (subscriberMap.find(channel) != subscriberMap.end())
        {
            return subscriberMap[channel];
        }
        return vector<Subscriber *>();
    }

    bool checkSubscription(Subscriber *subscriber, Channel *channel)
    {
        return channel && channel->isSubcribe(subscriber);
    }
};

Database *Database::instance = nullptr;

#endif