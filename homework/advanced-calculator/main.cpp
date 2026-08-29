#include "advancedCalculator.hpp"
#include <iostream>
int main() {
    std::string input1 = "500 +- 280";
    std::string input2 = "1.999-+0.001";
    std::string input3 = "2.7+3.8";
    std::string input4 = ".50 + 20";
    double a = 2.47;
    double* b;


    std::cout<<input1<<"next:"; process(input1, b); std::cout<<"\n";
    std::cout<<input2<<"next:"; process(input2, b); std::cout<<"\n";
     std::cout<<input3<<"next:"; process(input3, b); std::cout<<"\n";
     std::cout<<input4<<"next:"; process(input4, b); std::cout<<"\n";

}
