#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
class IDocsReader
{
public:
    virtual void unlockPdf(string fileName) = 0;
    virtual ~IDocsReader() = default;
};
class RealDocs : public IDocsReader
{
private:
    string fileName;

public:
    RealDocs(string filename) : fileName(filename)
    {
    }
    void unlockPdf(string fileName) override
    {
        cout << "[Real Docs] Unlocking PDF: " << fileName << endl;
    }
};
class User
{
    string name;
    bool isPremium;

public:
    User(string n, bool isPremium) : name(n), isPremium(isPremium) {}
    bool isPremiumUser() const
    {
        return isPremium;
    }
    string getName() const
    {
        return name;
    }
};
class DocProxy : public IDocsReader
{
private:
    RealDocs *realDocs;
    string fileName;
    User *user;

public:
    DocProxy(string filename, User *u) : fileName(filename), realDocs(nullptr), user(u) {}

    void unlockPdf(string fileName) override
    {
        if (realDocs == nullptr && user->isPremiumUser())
        {
            realDocs = new RealDocs(fileName);
        }
        else{
            cout<<"User Does Not Have Access to Unlock PDF: " << fileName << endl;
            return;
        }
        realDocs->unlockPdf(fileName);
    }
};

int main()
{
    User *user = new User("Alice", true);
    IDocsReader *proxy = new DocProxy("document.pdf", user);
    User *user2 = new User("Bob", false);
    IDocsReader *proxy2 = new DocProxy("document.pdf", user2);
    proxy->unlockPdf("document.pdf");
    proxy2->unlockPdf("document.pdf");
    delete proxy;
    delete proxy2;
    delete user;
    delete user2;
    return 0;
}