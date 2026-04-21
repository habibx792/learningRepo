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
class Asteroid
{
private:
    int length;
    int weight;
    int width;
    string color;
    string texture;
    string material;

    // extrinsic properties;
    int posx, posy;
    int velociyX, velocityY;

public:
    Asteroid(int l, int w, int wi, string c, string t, string m, int x, int y, int vX, int vY) : length(l), weight(w), width(wi), color(c), texture(t), material(m), posx(x), posy(y), velociyX(vX), velocityY(vY) {}
    void renderAsteroid()
    {
        cout << "Rendering asteroid at (" << posx << ", " << posy << ")" << endl;
        cout << "Color: " << color << endl;
        cout << "Texture: " << texture << endl;
        cout << "Material: " << material << endl;
        // Implementation for rendering the asteroid
    }
    static size_t calculateMemoryUsage()
    {
        size_t total = sizeof(Asteroid);
        return total;
        // Implementation for calculating total memory of objects
    }
};
class spaceGame
{
    vector<Asteroid *> asteroid;

public:
    void spawAsteroid(int count)
    {
        vector<string> color = {"red", "blue", "green"};
        vector<string> texture = {"rough", "smooth", "jagged"};
        vector<string> material = {"rock", "metal", "ice"};
        int sizes[] = {10, 5, 3};
        for (int i = 0; i < count; i++)
        {
            int type = i % 3;
            asteroid.push_back(new Asteroid(sizes[i % 3],
                                            sizes[i % 3], sizes[type], color[type], texture[type], material[type], 190 + i * 50, 100 + i * 30, 5, 3));
        }
        cout << "Asteroids spawned!" << endl;
        cout << "Total size : " << sizeof(asteroid) * asteroid.size() << endl;
    }
    void renderAll()
    {
        for (auto &a : asteroid)
        {
            a->renderAsteroid();
        }
    }
    int getAsteroidCount()
    {
        return asteroid.size();
    }
    size_t calculaterMemoryUsage()
    {

        return asteroid.size() * Asteroid::calculateMemoryUsage();
    }
};
int main()
{

    const int Asteroid_count = 10000000;
    cout << "Testing without Flyweight Pattern" << endl;
    cout << "Total Objecs created without desing  created: " << Asteroid_count << endl;
    spaceGame *game = new spaceGame();
    // game->renderAll();
    game->spawAsteroid(Asteroid_count);
    cout << "Total memory usage: " << game->calculaterMemoryUsage() << endl;
    cout << "Create " << Asteroid_count << "Arab  asteroids" << endl;
    cout << "Size in GBS : " << game->calculaterMemoryUsage() / (1024 * 1024 * 1024) << endl;
    cout << "Memory in Mb : " << game->calculaterMemoryUsage() / (1024 * 1024) << endl;
    cout << "Memory In bytes : " << game->calculaterMemoryUsage() << endl;

    return 0;
}