
#include "Image.h"

Image::Image() : height(0), width(0), pixels(nullptr) {}

Image::Image(int h, int w, Pixel pixel) : height(h), width(w) {
    allocateMemory();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pixels[i][j] = pixel;
        }
    }
}

Image::Image(const Image& other) : height(other.height), width(other.width) {
    allocateMemory();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pixels[i][j] = other.pixels[i][j];
        }
    }
}

Image::~Image() {
    if (pixels) {
        deallocateMemory();
    }
}

Image& Image::operator=(const Image& other) {
    if (this != &other) {
        deallocateMemory();
        height = other.height;
        width = other.width;
        allocateMemory();
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                pixels[i][j] = other.pixels[i][j];
            }
        }
    }
    return *this;
}

bool Image::operator==(const Image& other) const {
    if (height != other.height || width != other.width) return false;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (pixels[i][j] != other.pixels[i][j]) return false;
        }
    }
    return true;
}

bool Image::operator!=(const Image& other) const {
    return !(*this == other);
}

Image Image::operator+(const Image& other) const {
    int newHeight = std::max(height, other.height);
    int newWidth = width + other.width;
    Image result(newHeight, newWidth, WHITE);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            result.pixels[i][j] = pixels[i][j];
        }
    }

    for (int i = 0; i < other.height; ++i) {
        for (int j = 0; j < other.width; ++j) {
            result.pixels[i][j + width] = other.pixels[i][j];
        }
    }

    return result;
}

Image& Image::operator+=(const Image& other) {
    *this = *this + other;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Image& image) {
    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            os << image.pixels[i][j];
        }
        os << '\n';
    }
    return os;
}

int Image::getHeight() const { return height; }
int Image::getWidth() const { return width; }

Pixel& Image::operator()(int x, int y) {
    return pixels[x][y];
}

const Pixel& Image::operator()(int x, int y) const {
    return pixels[x][y];
}

void Image::allocateMemory() {
    pixels = new Pixel * [height];
    for (int i = 0; i < height; ++i) {
        pixels[i] = new Pixel[width];
    }
}

void Image::deallocateMemory() {
    for (int i = 0; i < height; ++i) {
        delete[] pixels[i];
    }
    delete[] pixels;
}