#include <iostream>
#include <vector>

#include "youtube.h"
#include "uploadEngine.h"
#include "channel.h"
#include "subscriber.h"
#include "video.h"
#include "paymentEngine.h"
#include "notinficationEngine.h"

using namespace std;

int main()
{

    Database *db = Database::getInstance();
    YouTube *yt = YouTube::getInstance();

    PaymentEngine *payment = PaymentEngine::getInstance();
    payment->setDatabase(db);
    UploadEngine *upload = UploadEngine::getInstance();

    upload->setDatabase(db);
    VideoRender *render = VideoRender::getInstance();
    NotificationEngine *notif = new EmailNotification(db);
    yt->setDependeny(payment, db, upload, render, notif);

    Channel *c1 = new Channel("Tech", 101);
    Channel *c2 = new Channel("Gaming", 102);
    Channel *c3 = new Channel("Music", 103);
    vector<Channel *> channels;
    channels.push_back(c1);
    channels.push_back(c2);
    channels.push_back(c3);
    db->addChannel(c1);
    db->addChannel(c2);
    db->addChannel(c3);
    vector<Subscriber *> subs;
    for (int i = 1; i <= 10; i++)
    {
        Subscriber *s = new Subscriber(
            "User" + to_string(i),
            "user" + to_string(i) + "@gmail.com");

        subs.push_back(s);
        db->addSubscriber(s);
    }
    for (int i = 0; i < 10; i++)
    {
        if (i % 3 == 0)
        {
            c1->subscirbe(subs[i]);
            subs[i]->subScribe(c1);
        }
        else if (i % 3 == 1)
        {
            c2->subscirbe(subs[i]);
            subs[i]->subScribe(c2);
        }
        else
        {
            c3->subscirbe(subs[i]);
            subs[i]->subScribe(c3);
        }
    }
    for (int i = 0; i < channels.size(); i++)
    {
        Channel *ch = channels[i];
        for (int j = 0; j < ch->getSubScribers().size(); j++)
        {
            vector<Subscriber*> suby = ch->getSubScribers();
            yt->addChanenlSubcriber(ch, suby);
        }
    }

    video *v1 = new video("C++ Basics", 10, "Tech", 30, 30);
    video *v2 = new video("Gaming Highlights", 15, "Gaming", 20, 40);
    video *v3 = new video("Top Music", 20, "Music", 30, 50);

    yt->upload(v1, c1);
    yt->upload(v2, c2);
    yt->upload(v3, c3);

    yt->send(c1);
    yt->send(c2);
    yt->send(c3);

    yt->renderVedo("Tech", "C++ Basics", c1);

    cout << "\nSystem executed successfully!" << endl;

    // Cleanup
    delete v1;
    delete v2;
    delete v3;
    delete c1;
    delete c2;
    delete c3;
    for (auto s : subs)
        delete s;
    delete notif;

    return 0;
}