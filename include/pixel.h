#pragma oncce

#include <iostream>

// Constants for Pixel Colors
const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;
const unsigned char WHITE = (unsigned char)32;

// Pixel Class
class Pixel {
private:
    unsigned char color;

public:
    // Constructor
    Pixel(unsigned char pixel = WHITE);

    // Operators
    bool operator==(const Pixel& other) const;
    bool operator!=(const Pixel& other) const;

    Pixel operator|(const Pixel& other) const;
    Pixel operator&(const Pixel& other) const;

    Pixel& operator|=(const Pixel& other);
    Pixel& operator&=(const Pixel& other);

    friend std::ostream& operator<<(std::ostream& os, const Pixel& pixel);

    unsigned char getColor() const;
};


