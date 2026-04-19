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
class IImage
{
public:
    virtual void display() = 0;
    virtual ~IImage() = default;
};
class RealImage : public IImage
{
private:
    string fileName;

public:
    RealImage(string filename)
    {
        this->fileName = filename;
        // Initialize with filename
    }

    void display() override
    {
        cout << "[Real Image ] Loading Image from Disk: " << this->fileName << endl;
    }
};
class ImageProxy : public IImage
{
private:
    RealImage *realImage;
    string fileName;

public:
    ImageProxy(string filename) : fileName(filename), realImage(nullptr) {}

    void display() override
    {
        if (realImage == nullptr)
        {
            realImage = new RealImage(fileName);
        }
        realImage->display();
    }
};
int main()
{
    IImage * image1=new ImageProxy("image1.jpg");
    image1->display();

    return 0;
}