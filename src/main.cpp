#include <iostream>
#include <fstream>
#include <sstream>
#include "Perceptron.h"

using namespace std;


std::vector<std::vector<float>> getTrainingData(string fileName) {
    std::ifstream infile(fileName);
    std::vector<std::vector<float>> trainingData;
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            stringstream inputLine(line);
            std::vector<float> data;
            for (int i = 0; i < 3; ++i) {
                float input;
                inputLine >> input;
                data.push_back(input);
            }
            trainingData.push_back(data);
        }
        cout << "TD SIZE: " << trainingData.size() << endl;
    } else {
        std::cout << "Couldn't open file: " << fileName << std::endl;
    }
    infile.close();

    return trainingData;
}

MLLJET001::Perceptron doTraining(string name, int iterations, float learningRate) {
    MLLJET001::Perceptron perceptron(getTrainingData("training_" + name + ".txt"));
    perceptron.trainPerceptron(iterations, learningRate);
    cout << "\n\n" << name << endl;
    cout << "W1: " << perceptron.weights[0] << endl;
    cout << "W2: " << perceptron.weights[1] << endl;

    int in1 = 0;
    int in2 = 0;
    cout << "Compute(" << in1 << ", " << in2 << "): " << perceptron.compute(in1, in2) << endl;
    in1 = 1;
    in2 = 0;
    cout << "Compute(" << in1 << ", " << in2 << "): " << perceptron.compute(in1, in2) << endl;
    in1 = 0;
    in2 = 1;
    cout << "Compute(" << in1 << ", " << in2 << "): " << perceptron.compute(in1, in2) << endl;
    in1 = 1;
    in2 = 1;
    cout << "Compute(" << in1 << ", " << in2 << "): " << perceptron.compute(in1, in2) << endl;

    return perceptron;
}

int main() {
    //doTraining("AND");
    //doTraining("OR");
    doTraining("NAND", 1000, 0.1);

    return 0;
}

