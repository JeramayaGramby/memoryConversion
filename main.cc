#include <cstdint>
#include <iostream>
#include <vector>
#include "CPUOptimizer.h"



std::vector<int> inputArrayGenerator() {
    std::vector<int> input;
    int value;

    std::cout << "Enter integers (type -1 to stop): ";
    while (std::cin >> value && value != -1) {
        if (value > std::numeric_limits<uint_least16_t>::max()) {
            std::cerr << "Error: value " << value
                      << " exceeds 16-bit representation. Terminating.\n";
            std::exit(EXIT_FAILURE);
        }
        input.push_back(value);
    }

    return input;
}


int main() {
   CPUUtilities::CPUOptimizer optimizer;
   std::vector<int> inputData = inputArrayGenerator();
   
   std::cout << "Register size: " << optimizer.getRegisterSize() << std::endl;

   std::vector<uint_least16_t> optimized = optimizer.registerSizeConverter(inputData);
   
   for (const auto& value : optimized) {
       std::cout << static_cast<int>(value) << " ";
   }
   std::cout << std::endl;
   return 0;
}