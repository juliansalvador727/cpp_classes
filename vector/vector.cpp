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
        std::size_t length_, capacity_;
        int* array_;
        void resize(std::size_t new_capacity);
}