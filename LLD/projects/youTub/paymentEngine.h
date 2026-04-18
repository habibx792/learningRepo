#ifndef PaymentEngine_H
#define PaymentEngine_H
#include <string>
#include <iostream>
#include "Db.h"
#include "channel.h"
#include <vector>
using namespace std;

class PaymentEngine
{
private:
    Database *db;
    static PaymentEngine *instance;

    PaymentEngine() : db(nullptr) {}

public:
    static PaymentEngine *getInstance()
    {
        if (instance == NULL)
        {
            instance = new PaymentEngine();
        }
        return instance;
    }

    void setDatabase(Database *database)
    {
        db = database;
    }

    void send()
    {
        if (!db)
            return;

        vector<Channel *> monoTizedChannels = db->getMonitoredChannels();
        for (int i = 0; i < monoTizedChannels.size(); i++)
        {
            cout << "Payment of 500 is Sending to " << monoTizedChannels[i]->getChannelName() << endl;
        }
    }
};

PaymentEngine *PaymentEngine::instance = nullptr;

#endif