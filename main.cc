#include <cstdint>
#include <iostream>
#include <vector>
#include "CPUOptimizer.h"



std::vector<int> inputArrayGenerator() {
    std::vector<int> input;
    int value;

    std::cout << "Enter integers (type -1 to stop): ";
    while (std::cin >> value && value != -1) {
        input.push_back(value);
    }

    return input;
}


int main() {
   CPUUtilities::CPUOptimizer optimizer;
   std::vector<int> inputData = inputArrayGenerator();
   optimizer.registerSizeConverter(inputData);
   std::cout << "Register size: " << optimizer.getRegisterSize() << std::endl;

   std::vector<uint_least8_t> optimized = optimizer.registerSizeConverter(inputData);
   
   for (const auto& value : optimized) {
       std::cout << static_cast<int>(value) << " ";
   }
   std::cout << std::endl;
   return 0;
}