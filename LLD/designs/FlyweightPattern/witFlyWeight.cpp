#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <string>
#include <list>
using namespace std;

class A
{
};
class AsteroidFlyweight
{
    // intrinsix property

    int length;

    int weight;
    int width;
    string color;
    string texture;
    string material;

public:
    AsteroidFlyweight(int l, int w, int wi, string c, string t, string m) : length(l), weight(w), width(wi), color(c), texture(t), material(m) {}
    void render()
    {
        cout << "Rendering flyweight asteroid with properties: " << length << ", " << weight << ", " << width << ", " << color << ", " << texture << ", " << material << endl;
    }
    string getColor()
    {
        return color;
    }
    string getTexture()
    {
        return texture;
    }
    void render(int x, int y, int velx, int vely)
    {
        cout << "Color: " << color << endl;
        cout << "Texture: " << texture << endl;
        cout << "Material: " << material << endl;
        cout << "Rendering asteroid at (" << x << ", " << y << ") with velocity (" << velx << ", " << vely << ")" << endl;
    }
    string getMaterial()
    {
        return material;
    }
    static size_t getMemoryUsage()
    {
        return sizeof(int) * 3 + sizeof(string) * 3 + 32 * 3;
    }
};
class FlyWeightFactory
{
    static unordered_map<string, AsteroidFlyweight *> flyweights;

public:
    static AsteroidFlyweight *getFlyweight(int length, int weight, int width, const string &color, const string &texture, const string &material)
    {
        string key = to_string(length) + "_" + to_string(weight) + "_" + to_string(width) + "_" + color + "_" + texture + "_" + material;
        if (flyweights.find(key) == flyweights.end())
        {
            flyweights[key] = new AsteroidFlyweight(length, weight, width, color, texture, material);
        }
        return flyweights[key];
    }
    static int getFlyweightCount()
    {
        return flyweights.size();
    }
    void render(int pox, int posY, int velox, int veloy)
    {

        cout << "Rendering asteroid at (" << pox << ", " << posY << ") with velocity (" << velox << ", " << veloy << ")" << endl;
        // Implementation for rendering
    }
    static void cleanUp()
    {
        flyweights.clear();
    }
};
unordered_map<string, AsteroidFlyweight *> FlyWeightFactory::flyweights;
class AsteroidContext
{

private:
    AsteroidFlyweight *flyweight;
    int posx, posy;
    int velociyX, velocityY;

    // extrinsic properties;

public:
    AsteroidContext(AsteroidFlyweight *fw, int x, int y, int vX, int vY) : flyweight(fw), posx(x), posy(y), velociyX(vX), velocityY(vY) {}
    void renderAsteroid()
    {
        cout << "Rendering asteroid at (" << posx << ", " << posy << ")" << endl;
        cout << "Color: " << flyweight->getColor() << endl;
        cout << "Texture: " << flyweight->getTexture() << endl;
        cout << "Material: " << flyweight->getMaterial() << endl;
        // Implementation for rendering the asteroid
    }
    string getColor()
    {
        return flyweight->getColor();
    }
    string getTexture()
    {
        return flyweight->getTexture();
    }
    string getMaterial()
    {
        return flyweight->getMaterial();
    }
    void render()
    {
        flyweight->render(posx, posy, velociyX, velocityY);
    }
    void update(int velox, int veloy, int posx, int posy)
    {
        this->posx = posx;
        this->posy = posy;
        this->velociyX = velox;
        this->velocityY = veloy;
        // Implementation for updating asteroid position and velocity
    }
    static size_t getMemoryUsage()
    {
        return sizeof(flyweight) + sizeof(int) * 4;
    }
};
class spaceGameWithFlyWeight
{
    vector<AsteroidContext *> asteroid;

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
            asteroid.push_back(new AsteroidContext(FlyWeightFactory::getFlyweight(sizes[i % 3],
                                                                                  sizes[i % 3], sizes[type], color[type], texture[type], material[type]),
                                                   190 + i * 50, 100 + i * 30, 5, 3));
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

        return asteroid.size() * AsteroidContext::getMemoryUsage();
    }
};
int main()
{

    const int Asteroid_count = 10000000;
    cout << "Testing  Flyweight Pattern" << endl;
    cout << "Total Flyweights created: " << Asteroid_count << endl;
    spaceGameWithFlyWeight *game = new spaceGameWithFlyWeight();
    // game->renderAll();
    game->spawAsteroid(Asteroid_count);
    cout << "Total memory usage: " << game->calculaterMemoryUsage() << endl;
    cout << "Create " << Asteroid_count << "Arab  asteroids" << endl;
    cout<<"Memory in GB : "<<game->calculaterMemoryUsage()/(1024*1024*1024)<<endl;
    cout << "Memory in Mb : " << game->calculaterMemoryUsage() / (1024 * 1024) << endl;
    cout<<"Memory in Bytes : "<<game->calculaterMemoryUsage()<<endl;

    return 0;
}