#include <iostream>
#include "Perceptron.h"

namespace MLLJET001 {
    /**
     * Using the training data the perceptron was initialized with
     * it trains it. It does iterations passes over the training data.
     */
    void Perceptron::trainPerceptron(int iterations, float learningRate) {
        for (int i = 0; i < iterations; ++i) {
            int errors = 0;
            for (auto data : trainingData) {
                float in1 = data[0];
                float in2 = data[1];
                int target = (int)data[2];
                int output = 0;

//                std::cout << "Inputs:" << std::endl;
//                std::cout << "In1: " << in1 << std::endl;
//                std::cout << "In2: " << in2 << std::endl;
//                std::cout << "Target: " << target << std::endl;

                float input_sum = (in1 * weights[0]) + (in2 * weights[1]) + (1 * weights[2]);

                if (input_sum > threshold) {
                    output = 1;
                }

//                std::cout << "Old Weights:" << std::endl;
//                std::cout << "W1: " << weights[0] << std::endl;
//                std::cout << "W2: " << weights[1] << std::endl;
//                std::cout << "W3: " << weights[2] << std::endl;

                if (output != target) {
                    errors += 1;
                    weights[0] += learningRate * (target - output) * in1;
                    weights[1] += learningRate * (target - output) * in2;
                    weights[2] += learningRate * (target - output) * 1;
                }

//                std::cout << "New Weights:" << std::endl;
//                std::cout << "W1: " << weights[0] << std::endl;
//                std::cout << "W2: " << weights[1] << std::endl;
//                std::cout << "W3: " << weights[2] << std::endl;
            }
//            std::cout << "Errors: " << errors << std::endl;
            if (errors == 0) {
                std::cout << "Iterations: " << i+1 << std::endl;
                break;
            }
        }
    }

    /**
     * Computes the output of the perceptron with the
     * given inputs.
     */
    int Perceptron::compute(float in1, float in2) {
        float input_sum = (in1 * weights[0]) + (in2 * weights[1]) + weights[2];
        return ((input_sum > threshold) ? 1 : 0);
    }
};
