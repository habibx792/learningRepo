#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FileSystem
{
public:
    virtual void ls(int indent = 0) = 0;
    virtual void openAll(int indent = 0) = 0;
    virtual int getSize() = 0;
    virtual FileSystem *cd(const string &dirName) = 0;
    virtual string getName() = 0;
    virtual bool isFolder() = 0;

    virtual ~FileSystem() {} 
};

class File : public FileSystem
{
    string name;
    int size;

public:
    File(const string &name, int size) : name(name), size(size) {}

    void ls(int indent = 0) override
    {
        cout << string(indent, ' ') << name << " (" << size << " bytes)" << endl;
    }

    void openAll(int indent = 0) override
    {
        ls(indent);
    }

    int getSize() override
    {
        return size;
    }

    FileSystem *cd(const string &dirName) override
    {
        return nullptr;
    }

    string getName() override
    {
        return name;
    }

    bool isFolder() override
    {
        return false;
    }
};

class Folder : public FileSystem
{
    string name;
    vector<FileSystem *> children;

public:
    Folder(const string &name) : name(name) {}

    ~Folder()
    {
        for (auto child : children)
        {
            delete child;
        }
    }

    void add(FileSystem *child)
    {
        children.push_back(child);
    }

    void ls(int indent = 0) override
    {
        cout << string(indent, ' ') << name << "/" << endl;

        for (auto child : children)
        {
            child->ls(indent + 4); // 
        }
    }

    void openAll(int indent = 0) override
    {
        cout << string(indent, ' ') << name << "/" << endl;
        for (auto child : children)
        {
            child->openAll(indent + 4); 
        }
    }

    int getSize() override
    {
        int totalSize = 0;
        for (auto child : children)
        {
            totalSize += child->getSize();
        }
        return totalSize;
    }

    FileSystem *cd(const string &dirName) override
    {
        for (auto child : children)
        {
            if (child->isFolder() && child->getName() == dirName)
            {
                return child;
            }
        }

        cout << "Directory not found: " << dirName << endl; 
        return nullptr;
    }

    string getName() override
    {
        return name;
    }

    bool isFolder() override
    {
        return true;
    }
};

int main()
{
    Folder *root = new Folder("root");
    root->add(new File("file1.txt", 1024));
    root->add(new File("file2.txt", 2048));
    Folder *Docs = new Folder("subfolder");
    Docs->add(new File("file3.txt", 4096));
    root->add(Docs);
    Folder *images = new Folder("images");
    images->add(new File("image1.jpg", 8192));
    root->add(images);
    root->openAll();
    FileSystem * docs=root->cd("subfolder");
    docs->openAll();
    cout<<docs->getSize()<<endl;

    delete root; 
    return 0;
}