#include <random>

namespace rnd {
    auto rand(const int min, const int max) -> int {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    auto rand(const int max) -> int {
        return rand(0, max);
    }
}