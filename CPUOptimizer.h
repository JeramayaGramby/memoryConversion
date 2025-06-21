#ifndef CONFIG_H
#define CONFIG_H

// Header Imports
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

// Meat and Potatoes

namespace CPUUtilities{
    class CPUOptimizer {
        private:
            uint_fast8_t registerSizeBits;
        
        public:
            static constexpr uint_fast16_t RegisterDetector() noexcept {
            return sizeof(intptr_t) * 8;
        }

        std::string getRegisterSize() const noexcept;

        template<typename T>
        inline std::vector<uint_least16_t> registerSizeConverter(const std::vector<T>& input) const noexcept {
            std::vector<uint_least16_t> optimizedOutput(input.size());

            std::cout << "Processing vector of size: " << input.size() << std::endl;

    #if defined(__AVX2__)
            std::cout << "Using AVX2 optimization..." << std::endl;
            constexpr size_t SIMD_WIDTH = 8; // 8 x 32-bit ints = 256 bits 
            alignas(32) int temp[SIMD_WIDTH];
            for (size_t i = 0; i + SIMD_WIDTH <= input.size(); i += SIMD_WIDTH) {
                // Storing SIMD values back to the optimized output vector
                //__m256i simdValues = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(&input[i]));
                for (size_t j = 0; j < SIMD_WIDTH; ++j) {
                    temp[j] = static_cast<int>(input[i + j]);
                    optimizedOutput[i + j] = static_cast<uint_least16_t>(temp[j]);
                }
                __m256i simdValues = _mm256_load_si256(reinterpret_cast<const __m256i*>(temp));
                //_mm256_storeu_si256(reinterpret_cast<__m256i*>(&optimizedOutput[i]), simdValues);
            }


    #elif defined(__SSE2__)
            std::cout << "Using SSE2 optimization..." << std::endl;
            constexpr size_t SIMD_WIDTH = 2;
            alignas(16) int temp[SIMD_WIDTH];
            for (size_t i = 0; i + SIMD_WIDTH <= input.size(); i += SIMD_WIDTH) {
                // Loading the input vector into SIMD registers
                for (size_t j = 0; j < SIMD_WIDTH; ++j) {
                    temp[j] = static_cast<int>(input[i + j]);
                    optimizedOutput[i + j] = static_cast<uint_least16_t>(temp[j]);
                }
                __m128i simdValues = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&input[i]));
                //_mm_storeu_si128(reinterpret_cast<__m128i*>(&optimizedOutput[i]), simdValues);
            }

    #else
            std::cout << "Using scalar conversion..." << std::endl;
            // Fallback to scalar conversion if no SIMD support is available
            for (size_t i = 0; i < input.size(); ++i) {
                optimizedOutput[i] = static_cast<uint_least16_t>(input[i]);
                // Debugging Purposes only.
                std::cout << "Original: " << static_cast<int>(input[i]) << ", Converted: " 
                << static_cast<int>(optimizedOutput[i]) << std::endl;
            }
    #endif

            constexpr size_t cache_alignment = std::hardware_destructive_interference_size;
            for (size_t i = 0; i < optimizedOutput.size(); i += cache_alignment / sizeof(uint_least16_t)) {
                std::atomic_thread_fence(std::memory_order_acquire);
            }

            // Tail loop handles the remaining elements not processed above
            for (size_t i = (input.size()/ SIMD_WIDTH) * SIMD_WIDTH; i < input.size(); ++i) {
                optimizedOutput[i] = static_cast<uint_least16_t>(input[i]);
            }

            // Debugging Purposes only.
            std::cout << "Register size detected: " << RegisterDetector() << " bits" << std::endl;

            return optimizedOutput;
        }

    };
}
#endif