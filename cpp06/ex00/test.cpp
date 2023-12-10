#include <iostream>
#include <cmath>

int main() {
    float negativeInfinity = -INFINITY;
    float positiveInfinity = +INFINITY;
	int pi = static_cast<int>(negativeInfinity);

    std::cout << "Negative Infinity: " << negativeInfinity << std::endl;
    std::cout << "Positive Infinity: " << positiveInfinity << std::endl;
    std::cout << "Pi: " << pi << std::endl;
	
    return 0;
}
