#include <iostream>
#include <fstream>
#include <sstream>
#include "Perceptron.h"

using namespace std;

/**
 * Read in training data from file and return a vector of float
 * vectors.
 */
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
    } else {
        std::cout << "Couldn't open file: " << fileName << std::endl;
    }
    infile.close();

    return trainingData;
}

/**
 * Create the perceptron and read in its training data then train it.
 */
MLLJET001::Perceptron doTraining(string name, int iterations, float learningRate) {
    MLLJET001::Perceptron perceptron(getTrainingData("training_" + name + ".txt"));
    cout << endl << name << endl;
    perceptron.trainPerceptron(iterations, learningRate);
    cout << "W1: " << perceptron.weights[0] << endl;
    cout << "W2: " << perceptron.weights[1] << endl;
    cout << "W3: " << perceptron.weights[2] << endl;

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

/**
 * Connects the perceptrons correctly to create the XOR network.
 * Gets the output from the network and returns it.
 */
int computeXOR(float x0, float x1, MLLJET001::Perceptron AND, MLLJET001::Perceptron OR, MLLJET001::Perceptron NAND) {
    int NANDout = NAND.compute(x0, x1);
    int ORout = OR.compute(x0, x1);
    return AND.compute(NANDout, ORout);
}

int main() {
    MLLJET001::Perceptron AND = doTraining("AND", 1000, 0.1);
    MLLJET001::Perceptron OR = doTraining("OR", 1000, 0.1);
    MLLJET001::Perceptron NAND = doTraining("NAND", 1000, 0.1);

    cout << "Perceptrons trained!" << endl << endl;

    float x0, x1;

    while (true) {
        cout << "Enter XOR test data" << endl;
        cout << "Enter x0: ";
        cin >> x0;
        cout << "Enter x1: ";
        cin >> x1;

        cout << computeXOR(x0, x1, AND, OR, NAND) << endl;
        char answer;
        cout << "Test again?(y/n) ";
        cin >> answer;
        if (answer == 'n' || answer == 'N') {
            break;
        }
    }

    return 0;
}

