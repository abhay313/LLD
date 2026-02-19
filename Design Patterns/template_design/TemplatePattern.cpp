#include<bits/stdc++.h>
using namespace std;

/*
Use Cases:

where order of execution or pipline used

1. transaction
2. pipeline flow

*/

class ModelTrainer {
    public:
        void trainPipeline(const string& dataPath) {
            loadData(dataPath);
            preProcessData();
            trainModel();
            evaluateModel();
            saveModel();
        }
    protected:
        void loadData(const string &data){
            cout << "[Common] loading data " <<  data << endl;
        }
        void preProcessData(){
            cout << "[Common] Preprocessing data" << endl;
        }
        virtual void trainModel() = 0;
        virtual void evaluateModel() = 0;

        virtual void saveModel(){
            cout << "[Common] Save Model " << endl;
        }
};

class NeuralNetworkTrainer: public ModelTrainer {
    protected:
        void trainModel() override {
            cout << "[Neural Network] training Model " << endl;
        }

        void evaluateModel() override{
            cout << "[Neural Network] Evaluate accuracy " << endl;
        }
        
        void saveModel() override {
            cout << "[Neural Network] Serializing newtork weights .h file " << endl;
        }
};

class DecisionTreeTrainer: public ModelTrainer {
    protected:
        void trainModel() override {
            cout << "[Deciosn Tree] training Model " << endl;
        }

        void evaluateModel() override{
            cout << "[Deciosn Tree] Evaluate accuracy " << endl;
        }
};

int main() {
    
   cout << "======= Neural Network =======" << endl;
   ModelTrainer *nnTrainer = new NeuralNetworkTrainer();
   nnTrainer->trainPipeline("data/images");
   
   cout << "\n======= Decision Tree =======" << endl;
   ModelTrainer *dtTrainer = new DecisionTreeTrainer();
   dtTrainer->trainPipeline("data/iris.csv");
}

