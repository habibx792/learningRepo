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
class ModelTraniner
{
public:
   const void TrainPipline(const string &dataPath)
    {
        loadData(dataPath);
        PreProcess();
        trainModel();
        evaluateModel();
        saveModel();
        // Implementation for training pipeline
    }
    virtual void loadData(const string &dataPath)
    {
        cout << "[Common] Loading data from: " << dataPath << endl;
    }
    virtual void PreProcess()
    {
        cout << "[Common] Preprocessing data..." << endl;
    }
    virtual void saveModel()
    {
        cout << "[Common] Saving model..." << endl;
    }
    virtual void trainModel() = 0;
    virtual void evaluateModel() = 0;
};
class NeuralNetworkTrainer:public ModelTraniner
{
public:
    void trainModel() override
    {
        cout << "[Neural Network] Training neural network..." << endl;
    }

    void evaluateModel() override
    {
        cout << "[Neural Network] Evaluating neural network..." << endl;
    }
};
class DecisionTreeTrainer:public ModelTraniner
{
public:
    void trainModel() override
    {
        cout << "[Decision Tree] Training decision tree..." << endl;
    }

    void evaluateModel() override
    {
        cout << "[Decision Tree] Evaluating decision tree..." << endl;
    }
};
int main()
{
    NeuralNetworkTrainer trainer;
    trainer.TrainPipline("data/data.csv");

    DecisionTreeTrainer dtTrainer;
    dtTrainer.TrainPipline("data/data.csv");

    return 0;
} 