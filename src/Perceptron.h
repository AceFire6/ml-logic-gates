#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>

namespace MLLJET001 {
    class Perceptron {
        private:
            std::vector<std::vector<float>> trainingData;
            int threshold;
        public:
            Perceptron(std::vector<std::vector<float>> trainingData) : threshold(1), weights(3, 0.0F) {
                this->trainingData.resize(trainingData.size());
                for (int i = 0; i < trainingData.size(); ++i) {
                    this->trainingData[i] = std::move(trainingData[i]);
                }
            }

            ~Perceptron() {
                for (int i = 0; i < trainingData.size(); ++i) {
                    trainingData[i].clear();
                }
                trainingData.clear();
            }
            // Initialized with 3 weights. 2 inputs and 1 bias
            std::vector<float> weights;

           /**
             * Using the training data the perceptron was initialized with
             * it trains it. It does iterations passes over the training data.
             */
            void trainPerceptron(int iterations, float learningRate);
           /**
             * Computes the output of the perceptron with the
             * given inputs.
             */
            int compute(float in1, float in2);
    };
}

#endif
