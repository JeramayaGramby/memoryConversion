
#ifndef CONFIG_H
#define CONFIG_H

// Header Imports
#include <string>
#include <vector>
#include <cstdint> 

// Meat and Potatoes

class CPUOptimizer {
    private:
        uint8_t registerSizeBits;
    
    public:
        uint_fast16_t RegisterDetector() const;
        std::string getRegisterSize() const;

        template<typename T>
        std::vector 



};

#endif