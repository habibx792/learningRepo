#ifndef NotificationEngine_H
#define NotificationEngine_H

#include <string>
#include <iostream>
#include <vector>
#include "Db.h"
#include "channel.h"    
#include "subscriber.h" 

using namespace std;

class NotificationEngine
{
protected:
    Database *db;

public:
    virtual void sendNotification(Subscriber *subscriber, Channel *channel) = 0;
    virtual void sendVideoNotification(Channel *channel) = 0;
    virtual ~NotificationEngine() {}
};

class EmailNotification : public NotificationEngine
{
public:
    EmailNotification(Database *database)
    {
        this->db = database;
    }

    void sendNotification(Subscriber *subscriber, Channel *channel) override
    {
        if (db && subscriber && channel && db->checkSubscription(subscriber, channel))
        {
            cout << "Sending email notification to "
                 << subscriber->getEmail()
                 << " about new content on "
                 << channel->getChannelName() << endl;

            cout << channel->getLatestVideo() << endl;
        }
    }

    void sendVideoNotification(Channel *channel) override
    {
        if (!channel || !db)
            return;

        vector<Subscriber *> vec = db->getSubscribers(channel);
        for (Subscriber *subscriber : vec)
        {
            if (subscriber)
            {
                cout << "Sending video notification to "
                     << subscriber->getEmail()
                     << " about new content on "
                     << channel->getChannelName() << endl;
            }
        }
    }

    void sendUserNotification(Subscriber *subscriber)
    {
        if (!subscriber)
            return;

        cout << "Sending user notification to "
             << subscriber->getEmail() << endl;
    }
};

#endif