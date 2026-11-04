#ifndef DINORUNNER_RANDOM_NUM_H
#define DINORUNNER_RANDOM_NUM_H
#include <random>

namespace RandomNum {
    inline float getRandomFloat(const float min, const float max)
    {
        thread_local std::random_device rd;
        thread_local std::mt19937 gen(rd());
        std::uniform_real_distribution<float> distribution(min, max);

        return distribution(gen);
    }
}

#endif //DINORUNNER_RANDOM_NUM_H
