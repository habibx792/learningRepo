#ifndef Subscriber_H
#define Subscriber_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Channel;

class Subscriber
{
private:
    string name;
    vector<Channel *> channels;
    string email;

public:
    Subscriber(string name, string email) : name(name), email(email)
    {
    }

    string getName()
    {
        return name;
    }

    string getEmail()
    {
        return email;
    }

    void subScribe(Channel *channel)
    {
        if (find(channels.begin(), channels.end(), channel) == channels.end())
        {
            channels.push_back(channel);
            cout << "Subscriber " << name << " subscribed to channel " << channel->getChannelName() << endl;
        }
        else
        {
            cout << "Already subscribed to channel " << channel->getChannelName() << endl;
        }
    }
};

#endif