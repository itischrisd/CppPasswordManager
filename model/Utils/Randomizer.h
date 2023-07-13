#include <random>

namespace rnd {
    /**
     * Generates random number between lower and upper boundaries <closed compartment>
     * @param min lower boundary
     * @param max upper boundary
     * @return integer from range
     */
    auto rand(int min, int max) -> int;

    /**
     * Generates random number between 0 and upper boundaries <closed compartment>
     * @param max upper boundary
     * @return integer from range
     */
    auto rand(int max) -> int;
}