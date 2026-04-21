#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept>
using namespace std;
template <typename T>
class Iterator
{
public:
    virtual bool hasNext() = 0; 
    virtual T next() = 0;       
    virtual ~Iterator() {}    
};

template <typename T>
class Iterable
{
public:
    virtual Iterator<T> *getIterator() = 0;
    virtual ~Iterable() {}
};

class LinkList : public Iterable<int>
{
public:
    int data;
    LinkList *head;
    LinkList * tail;
    LinkList * next;

public:
    LinkList(int value)
    {
        this->data = value;
        next = nullptr;
    }

    Iterator<int> *getIterator() override;

    void append(int value)
    {
        if (head == nullptr)
        {
            tail = new LinkList(value);
            head = tail;
        }
        else
        {
            tail->next = new LinkList(value);
            tail = tail->next;
        }
    }
};

class LinkListIterator : public Iterator<int>
{
    LinkList *current;

public:
    LinkListIterator(LinkList *head)
    {
        this->current = head;
    }

    bool hasNext() override
    {
        return current != nullptr;
    }

    int next() override
    {
        if (!hasNext())
        {
            throw runtime_error("No more elements");
        }
        int value = current->data;
        current = current->next;
        return value;
    }
};

Iterator<int> *LinkList::getIterator()
{
    return new LinkListIterator(this);
}
class BinaryTree : public Iterable<int>
{
public:
    int data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int value)
    {
        this->data = value;
        left = nullptr;
        right = nullptr;
    }
    Iterator<int> *getIterator() override;
    void insert(int value)
    {
        if (value < data)
        {
            if (left == nullptr)
                left = new BinaryTree(value);
            else
                left->insert(value);
        }
        else
        {
            if (right == nullptr)
                right = new BinaryTree(value);
            else
                right->insert(value);
        }
    }
};

class BinaryTreeIterator : public Iterator<int>
{
    stack<BinaryTree *> stk;

    void pushLeft(BinaryTree *node)
    {
        while (node)
        {
            stk.push(node);
            node = node->left;
        }
    }

public:
    BinaryTreeIterator(BinaryTree *root)
    {
        pushLeft(root);
    }

    bool hasNext() override
    {
        return !stk.empty();
    }

    int next() override
    {
        if (!hasNext())
        {
            throw runtime_error("No more elements");
        }

        BinaryTree *node = stk.top();
        stk.pop();
        int value = node->data;

        if (node->right)
        {
            pushLeft(node->right);
        }

        return value;
    }
};

Iterator<int> *BinaryTree::getIterator()
{
    return new BinaryTreeIterator(this);
}
class Song
{
public:
    string title;
    string artist;

    Song(string title, string artist)
    {
        this->title = title;
        this->artist = artist;
    }

    void display() const
    {
        cout << "\"" << title << "\" by " << artist;
    }
};

class PlayList : public Iterable<Song>
{
public:
    vector<Song> songs;

    PlayList() {}

    void addSong(string title, string artist)
    {
        songs.push_back(Song(title, artist));
    }

    Iterator<Song> *getIterator() override;
};
class PlayListIterator : public Iterator<Song>
{
    vector<Song> vec;
    size_t index;

public:
    PlayListIterator(const vector<Song> &songs) : vec(songs), index(0) {}

    bool hasNext() override
    {
        return index < vec.size();
    }

    Song next() override
    {
        if (!hasNext())
        {
            throw runtime_error("No more elements");
        }
        return vec[index++];
    }
};

Iterator<Song> *PlayList::getIterator()
{
    return new PlayListIterator(songs);
}

int main()
{
    
    LinkList *list = new LinkList(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);

    cout << "Linked List elements: ";
    Iterator<int> *listIter = list->getIterator();
    while (listIter->hasNext())
    {
        cout << listIter->next() << " ";
    }
    cout << endl
         << endl;
    delete listIter;
    BinaryTree *tree = new BinaryTree(5);
    tree->insert(3);
    tree->insert(7);
    tree->insert(1);
    tree->insert(4);
    tree->insert(6);
    tree->insert(8);
    Iterator<int> *treeIter = tree->getIterator();
    while (treeIter->hasNext())
    {
        cout << treeIter->next() << " ";
    }
    cout << endl
         << endl;
    delete treeIter;

    PlayList myPlaylist;
    myPlaylist.addSong("Bohemian Rhapsody", "Queen");
    myPlaylist.addSong("Shape of You", "Ed Sheeran");
    myPlaylist.addSong("Blinding Lights", "The Weeknd");
    myPlaylist.addSong("Imagine", "John Lennon");

    cout << "Playlist songs:" << endl;
    Iterator<Song> *playlistIter = myPlaylist.getIterator();
    int songNumber = 1;
    while (playlistIter->hasNext())
    {
        Song currentSong = playlistIter->next();
        cout << "  " << songNumber++ << ". ";
        currentSong.display();
        cout << endl;
    }
    cout << endl;
    delete playlistIter;

    Iterable<int> *collections[] = {list, tree};

    for (int i = 0; i < 2; i++)
    {
        cout << "Iterating over collection " << (i + 1) << ": ";
        Iterator<int> *iter = collections[i]->getIterator();
        while (iter->hasNext())
        {
            cout << iter->next() << " ";
        }
        cout << endl;
        delete iter;
    }


  

    return 0;
}