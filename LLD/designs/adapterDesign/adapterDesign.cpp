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

class Ireports
{
public:
    virtual string getJsonData(const string data) = 0;
    virtual ~Ireports() {}
};
class XmlDataProvider
{
public:
    string getXmlData(const string &data)
    {
        size_t sep = data.find(':');
        string name = data.substr(0, sep);
        string id = data.substr(sep + 1);
        return "<user><name>" + name + "</name><id>" + id + "</id></user>";
    }
};
class XmlDataAdapter : public Ireports
{
public:
    XmlDataProvider *provide;
    XmlDataAdapter(XmlDataProvider *provider) : provide(provider) {}
    string getJsonData(const string data) override
    {
        string xml = provide->getXmlData(data);
        // cout << endl;
        // cout << xml << endl;

        size_t startName = xml.find("<name>") + 6;
        size_t endName = xml.find("</name>");
        string name = xml.substr(startName, endName - startName);
        size_t startId = xml.find("<id>") + 4;
        size_t endId = xml.find("</id>");
        string id = xml.substr(startId, endId - startId);
        return "{ \"name\": \"" + name + "\", \"id\": \"" + id + "\" }";
    }
};
class clint
{
public:
    void getReport(Ireports *reporter, const string &data)
    {
        cout << "Process json : " << reporter->getJsonData(data) << endl;
        // Implementation for getting report
    }
};
int main()
{
    XmlDataProvider *xmlprev = new XmlDataProvider();
    XmlDataAdapter *adapter = new XmlDataAdapter(xmlprev);
    string rawData = "John:123";
    clint client;
    client.getReport(adapter, rawData);

    return 0;
}