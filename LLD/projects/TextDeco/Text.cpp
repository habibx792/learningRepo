#include <iostream>
using namespace std;

class IText
{
public:
    virtual string GetAbility() = 0;
    virtual ~IText() = 0;
};

IText::~IText() {} 

class Text : public IText
{
public:
    string GetAbility() override
    {
        return "Text Ability";
    }
};

class TextDecoRater : public IText
{
public:
    TextDecoRater(IText *text) : tex(text) {}

    virtual string GetAbility() = 0;

protected:
    IText *tex;
};

class BoldDeco : public TextDecoRater
{
public:
    BoldDeco(IText *text) : TextDecoRater(text) {}

    string GetAbility() override
    {
        return tex->GetAbility() + " (Bold)";
    }
};

class ColorDeco : public TextDecoRater
{
public:
    ColorDeco(IText *text) : TextDecoRater(text) {}

    string GetAbility() override
    {
        return tex->GetAbility() + " (Color)";
    }
};

int main()
{
    IText *t = new Text();
    IText *bold = new BoldDeco(t);
    IText *colorBold = new ColorDeco(bold);

    cout << colorBold->GetAbility() << endl;

    return 0;
}