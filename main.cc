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
   optimizer.registerSizeConverter(inputArrayGenerator());
   std::cout << "Register size: " << optimizer.getRegisterSize() << std::endl;

   for (const auto& value : optimizer.registerSizeConverter(inputArrayGenerator())) {
       std::cout << static_cast<int>(value) << " ";
   }
   std::cout << std::endl;
   return 0;
}