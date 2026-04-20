from abc import ABC, abstractmethod


class ModelTrainer(ABC):

    def LoadData(self, path):
        print(f"Loading data from {path}")
        return "Loaded Data"
    @abstractmethod
    def processData(self, data):
        pass
    @abstractmethod
    def saveData(self, data):
        pass

    def trainModel(self, data):
        print("Training generic model")

    def trainPipeline(self, path):
        data = self.LoadData(path)
        data = self.processData(data)
        model = self.trainModel(data)
        self.saveData(model)


class NeuralNetworkTrainer(ModelTrainer):

    def processData(self, data):
        print("Processing data for neural network")
        return f"NN Processed {data}"

    def trainModel(self, data):
        print("Training neural network")
        return "Neural Network Model"

    def saveData(self, data):
        print(f"Saving {data}")


class DecisionTreeTrainer(ModelTrainer):

    def processData(self, data):
        print("Processing data for decision tree")
        return f"DT Processed {data}"

    def trainModel(self, data):
        print("Training decision tree")
        return "Decision Tree Model"

    def saveData(self, data):
        print(f"Saving {data}")


def main():
    dt = DecisionTreeTrainer()
    nn = NeuralNetworkTrainer()

    dt.trainPipeline("dt_data.csv")
    print("------")
    nn.trainPipeline("nn_data.csv")
if __name__ == "__main__":
    main()
