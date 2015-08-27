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
            std::vector<float> weights;

            void trainPerceptron(int iterations, float learningRate);
            int compute(float in1, float in2);
    };
}

#endif
