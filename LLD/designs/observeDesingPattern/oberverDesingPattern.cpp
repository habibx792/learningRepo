#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
#include <algorithm>
using namespace std;

class A
{
};
class ISubscriber
{
public:
    virtual void update() = 0;
    virtual string getName() = 0;
    virtual ~ISubscriber() {}
};
class Ichannel
{
public:
    virtual void subscibe(ISubscriber *subscriber) = 0;
    virtual void unsubscribe(ISubscriber *subscriber) = 0;
    virtual void notifySubscribers() = 0;

    virtual ~Ichannel() {}
};
class Channel : Ichannel
{
    vector<ISubscriber *> subscribers;
    string chanelName;
    string lasterVideo;

public:
    Channel(const string &name) : chanelName(name) {}
    void subscibe(ISubscriber *subscriber) override
    {
        if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end())
        {
            subscribers.push_back(subscriber);
            return;
        }
        cout << "Already Subscriber added to channel: " << chanelName << endl;
    }
    void unsubscribe(ISubscriber *subscriber) override
    {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end())
        {
            subscribers.erase(it);
        }
        cout << "Subscriber removed from channel: " << chanelName << endl;
    }
    void notifySubscribers() override
    {
        for (const auto &subscriber : subscribers)
        {
            cout << subscriber->getName() << " notified about new video!" << endl;
            subscriber->update();
        }
    }
    void uploadVideo(const string &videoTitle)
    {
        lasterVideo = videoTitle;
        notifySubscribers();
    }
    string getVideoDetails()
    {
        return "Our Channel Uploaded  vidio with title : " + lasterVideo;
    }
};
class Subsriber : public ISubscriber
{
    string name;
    vector<Channel *> channels;

public:
    Subsriber(const string &subscriberName, Channel *channel) : name(subscriberName)
    {
        if (find(channels.begin(), channels.end(), channel) == channels.end())
        {
            channels.push_back(channel);
        }
    }
    string getName()
    {
        return name;
    }
    void update() override
    {
        // cout << "Subscriber: " << name << " notified about new video!" << endl;
        for (const auto &channel : channels)
        {
            cout << channel->getVideoDetails() << endl;
        }
    }
};

int main()
{

    Channel *channel = new Channel("Tech Talks");

    Subsriber *Ghuluam_Habib = new Subsriber("Ghulam Habib", channel);
    Subsriber *Alexy = new Subsriber("Alexy", channel);
    channel->subscibe(Alexy);
    channel->subscibe(Ghuluam_Habib);
    channel->uploadVideo("C++ Observant Design Pattern");
    channel->unsubscribe(Ghuluam_Habib);
    cout << endl;
    cout << Ghuluam_Habib->getName() << "Will be notified about the new video!" << endl;
    channel->uploadVideo("Learn Design Pattern By Xians");
    // channel->notifySubscribers();
    cout << "========================= " << endl;

    Ghuluam_Habib->update();
    Alexy->update();
    delete channel;
    delete Ghuluam_Habib;
    delete Alexy;

    return 0;
}