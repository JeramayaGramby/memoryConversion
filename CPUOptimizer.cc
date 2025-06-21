#include "CPUOptimizer.h"
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <cstdint>
#include <immintrin.h>  // AVX/SSE SIMD instructions
#include <vector>
#include <new>  // For aligned memory allocation
#include <iostream>
#include <vector>
#include <atomic>  // Required for interference size

// Method to input array of unsigned integer vectors



// Convert register size to a human-readable format
std::string CPUUtilities::CPUOptimizer::getRegisterSize() const noexcept {
    uint_fast16_t registerBits = RegisterDetector();

    switch (registerBits) {
        case 64: return "64-bit architecture";
        case 32: return "32-bit architecture";
        case 16: return "16-bit architecture";
        case 8:  return "8-bit architecture";
        default: throw std::runtime_error("Unknown register size");
    }
}

template std::vector<uint_least16_t> CPUUtilities::CPUOptimizer::registerSizeConverter<int>(const std::vector<int>&) const noexcept;

