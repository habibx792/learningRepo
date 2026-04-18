#ifndef UploadEngine_H
#define UploadEngine_H

#include <string>
#include <iostream>
#include "Db.h"
#include "video.h"
#include "channel.h"

using namespace std;

class UploadEngine
{
private:
    Database *db;
    UploadEngine() : db(nullptr) {}
    static UploadEngine *instance;

public:
    static UploadEngine *getInstance()
    {
        if (instance == NULL)
        {
            instance = new UploadEngine();
        }
        return instance;
    }

    void setDatabase(Database *database)
    {
        db = database;
    }

    void uploadVideo(video *video, Channel *channel)
    {
        if (db && video && channel)
        {
            db->addVideo(channel, video);
            channel->uploadVideos(video);
            cout << "Uploaded the video: " << video->getTitle() << endl;
        }
    }
};

UploadEngine *UploadEngine::instance = nullptr;

#endif