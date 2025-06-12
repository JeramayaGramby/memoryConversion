#include "CPUOptimizer.h"
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <cstdint>

uint_fast16_t CPUUtilities::CPUOptimizer::RegisterDetector() const {
    // Determine the size of the pointer type at compile time
    for (intptr_t i = 0; i < 8; ++i) {
        if (sizeof(intptr_t) == i) {
            return static_cast<uint_fast16_t>(i * 8);
        }
    };

    if (INTPTR_MAX == INT64_MAX)
        return 64;
    else if (INTPTR_MAX == INT32_MAX)
        return 32;
    else if (INTPTR_MAX == INT16_MAX)
        return 16;
    else if (INTPTR_MAX == INT8_MAX)
        return 8;
    else
        throw std::runtime_error("Unknown register size");
};
