#pragma once 
#include "Pixel.h"

class Image {
private:
    int height, width;
    Pixel** pixels;

    void allocateMemory();
    void deallocateMemory();

public:
    // Constructors
    Image();
    Image(int h, int w, Pixel pixel = WHITE);

    // Copy Constructor
    Image(const Image& other);

    // Destructor
    ~Image();

    // Assignment Operator
    Image& operator=(const Image& other);

    // Operators
    bool operator==(const Image& other) const;
    bool operator!=(const Image& other) const;

    Image operator+(const Image& other) const;
    Image& operator+=(const Image& other);

    friend std::ostream& operator<<(std::ostream& os, const Image& image);

    // Getters
    int getHeight() const;
    int getWidth() const;

    // Pixel Access
    Pixel& operator()(int x, int y);
    const Pixel& operator()(int x, int y) const;
};