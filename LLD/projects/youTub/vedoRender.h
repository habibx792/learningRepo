#ifndef VideoRender_H
#define VideoRender_H

#include <string>
#include <iostream>
#include "video.h"
#include <time.h>
#include <random>

using namespace std;

class VideoRender
{
private:
    static VideoRender *instance;
    random_device rd;

    VideoRender() {}

public:
    static VideoRender *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new VideoRender();
        }
        return instance;
    }

    void renderVideo(video *video)
    {
        if (!video)
            return;

        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, 1);

        cout << "Title: " << video->getTitle() << endl;
        cout << "Duration: " << video->getDuration() << " minutes" << endl;
        cout << "Rendering video frames..." << endl;

        for (int i = 0; i < video->getFrameCount(); i++)
        {
            // cout << "Frame No is Redering : " << i;
            int rowBit = dist(gen);

            for (int j = 0; j < video->getFrameCount(); j++)
            {
                int colBit = dist(gen);
                cout << rowBit<<" " <<colBit;
            }
            cout  <<endl;
        }
    }
};

VideoRender *VideoRender::instance = nullptr;

#endif