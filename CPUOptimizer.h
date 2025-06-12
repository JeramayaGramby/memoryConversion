
#ifndef CONFIG_H
#define CONFIG_H

// Header Imports
#include <string>
#include <vector>
#include <cstdint> 

// Meat and Potatoes

namespace CPUUtilities{
    class CPUOptimizer {
        private:
            uint_fast8_t registerSizeBits;
        
        public:
            uint_fast16_t RegisterDetector() const;
            std::string getRegisterSize() const;

            template<typename T>
            std::vector<uint_least64_t> registerSizeConverter(const std::vector<T>& input) const; 
        };
};

#endif