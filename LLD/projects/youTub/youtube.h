#ifndef YouTube_H
#define YouTube_H

#include <string>
#include <iostream>
#include "Db.h"
#include "video.h"
#include "uploadEngine.h"        
#include "vedoRender.h"        
#include "paymentEngine.h"      
#include "notinficationEngine.h" 
#include "channel.h"           

using namespace std;

class YouTube
{
private:
    PaymentEngine *paymentEngine;
    Database *db;
    UploadEngine *upEngine;
    VideoRender *videoRender;
    NotificationEngine *engine;
    static YouTube *instance;
    YouTube() {}
public:
    static YouTube *getInstance()
    {
        if (instance == NULL)
        {
            instance = new YouTube();
        }
        return instance;
    }

    void setDependeny(PaymentEngine *engine, Database *database,
                      UploadEngine *uploadEngine,
                      VideoRender *videoRender,
                      NotificationEngine *eng)
    {
        this->paymentEngine = engine;
        this->db = database;
        this->upEngine = uploadEngine;
        this->videoRender = videoRender;
        this->engine = eng;
    }

    void upload(video *vid, Channel *ch)
    {
        if (upEngine && vid && ch)
        {
            upEngine->uploadVideo(vid, ch);
            cout << "Your Video is Saved to DB: " << vid->getTitle() << endl;
        }
    }

    void renderVedo(string topic, string title, Channel *channel)
    {
        if (db && videoRender && channel)
        {
            video *vid = db->getVideo(channel, topic, title);
            if (vid)
            {
                videoRender->renderVideo(vid);
            }
        }
    }

    void send(Channel *channel)
    {
        if (engine && channel)
        {
            engine->sendVideoNotification(channel);
        }
    }

    video *getLastestVideo(Channel *channel)
    {
        if (db && channel)
        {
            return db->getVideo(channel);
        }
        return nullptr;
    }
    void addChanenlSubcriber(Channel *channel, vector<Subscriber *> sub)
    {
        for (int i = 0; i < sub.size(); i++)
        {
            Subscriber *suby = sub[i];
            db->addSubscription(channel, suby);
        }
    }
};

YouTube *YouTube::instance = nullptr;

#endif