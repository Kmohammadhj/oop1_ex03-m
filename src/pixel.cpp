#include "Pixel.h"

Pixel::Pixel(unsigned char pixel) : color(pixel) {}

bool Pixel::operator==(const Pixel& other) const { return color == other.color; }
bool Pixel::operator!=(const Pixel& other) const { return color != other.color; }

Pixel Pixel::operator|(const Pixel& other) const {
    return Pixel(std::max(color, other.color));
}

Pixel Pixel::operator&(const Pixel& other) const {
    return Pixel(std::min(color, other.color));
}

Pixel& Pixel::operator|=(const Pixel& other) {
    color = std::max(color, other.color);
    return *this;
}

Pixel& Pixel::operator&=(const Pixel& other) {
    color = std::min(color, other.color);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel) {
    os << pixel.color;
    return os;
}

unsigned char Pixel::getColor() const { return color; }

