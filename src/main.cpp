// Main.cpp
#include "Image.h"

int main() {
    // Test basic functionality
    Image img1(3, 3, WHITE);
    Image img2(3, 3, GRAY);
    Image img5(3, 3, BLACK);

    std::cout << "Image 1:" << std::endl;
    std::cout << img1 << std::endl;

    std::cout << "Image 2:" << std::endl;
    std::cout << img2 << std::endl;

    std::cout << "Image 3:" << std::endl;
    std::cout << img5 << std::endl;

    Image img3 = img1 + img2;
    std::cout << "Image 3 (Image 1 + Image 2):" << std::endl;
    std::cout << img3 << std::endl;

    Image img4 = img2 + img1;
    std::cout << "Image 4 (Image 2 + Image 1):" << std::endl;
    std::cout << img4 << std::endl;

    return 0;
}