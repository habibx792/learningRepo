// meke header file
#ifndef vido_H
#define vido_H

#include <string>
#include <iostream>
#include "youtube.h"
using namespace std;

class video
{
private:
    string title;
    int duration;
    string topic;
    int videoNumber;
    int frameCount;

protected:
    // member variables
public:
    // constructors
    video(string title, int duration, string topic, int videoNumber, int frameCount) : title(title), duration(duration), topic(topic), videoNumber(videoNumber), frameCount(frameCount)
    {
        cout << "Video created with title: " << title << endl;
    }
    int getFrameCount()
    {
        
        return frameCount;
    }
    string getTitle()
    {
        return title;
    }
    int getDuration()
    {
        return duration;
    }
    string videoTopic()
    {
        return topic;
    }
    int getVideoNumber()
    {
        return videoNumber;
    }
};

#endif // vido_H