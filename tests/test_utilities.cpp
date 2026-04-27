#include <iostream>
#include <cstdint>
#include <cstdlib>

// Forward declaration of the extracted function
uint8_t getRandom();

// Mock the Arduino random function
long random(long max) {
    return std::rand() % max;
}

int main() {
    bool passed = true;

    // Test that values are within expected bounds
    // Since it's returning uint8_t, it's inherently <= 255.
    // However, random(0xFF) returns [0, 254], so let's check that.
    for (int i = 0; i < 1000; ++i) {
        uint8_t result = getRandom();
        if (result >= 0xFF) {
            std::cerr << "Test failed: value " << (int)result << " >= 255" << std::endl;
            passed = false;
        }
    }

    // Test that the function is actually generating random values (not constant)
    uint8_t first_val = getRandom();
    bool all_same = true;
    for (int i = 0; i < 100; ++i) {
        if (getRandom() != first_val) {
            all_same = false;
            break;
        }
    }
    if (all_same) {
        std::cerr << "Test failed: values are all the same" << std::endl;
        passed = false;
    }

    if (passed) {
        std::cout << "All tests passed for getRandom()" << std::endl;
        return 0;
    }
    return 1;
}
