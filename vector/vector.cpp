#include <iostream>

class Vector{
    public:
        // constructor
        Vector(std::size_t cap = 100);
        // deconstructor
        ~Vector();
        
        std::size_t length() const;
        void operator+=( int elem );
        int& operator[](std::size_t index);
    private:
        std::size_t length_; // number of valid items in the vector
        std::size_t capacity_; // amount of memory allocated
        int* array_;
        void resize(std::size_t new_capacity);
};

// public functions
Vector::Vector(std::size_t cap): length_{ 0 }, capacity_{ cap }, array_{ new int [capacity_]{}} {};

Vector::~Vector() { delete[] array_; array_ = nullptr; };

std::size_t Vector::length() const { return length_; };

void Vector::operator+=( int elem ) { 
    // resize if not enough capacity.
    if ( length_ == capacity_ ) resize(capacity_ + 50);

    // capacity_-th
    array_[length_] = elem;
    ++length_;
};

// private functions