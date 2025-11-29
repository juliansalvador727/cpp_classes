#include <iostream>

class Vector{
    public:
        // constructor
        Vector(std::size_t cap = 100);
        // copy constructor
        Vector (const Vector &original);
        // copy assignment operator
        Vector& operator=(const Vector &other);

        // move constructor
        Vector (Vector &&original);
        // move assignment operator
        Vector& operator=(const Vector &&other);

        // deconstructor
        ~Vector();
        
        std::size_t length() const;
        std::size_t capacity() const;
        void operator+=( int elem );
        void operator-=( int elem );
        int& operator[](std::size_t index);
        void reverse();
        void sort();
        bool is_sorted();
    private:
        std::size_t length_; // number of valid items in the vector
        std::size_t capacity_; // amount of memory allocated
        int* array_;
        void resize(std::size_t new_capacity);

};

// public functions

// constructor
Vector::Vector(std::size_t cap): length_{ 0 }, capacity_{ cap }, array_{ new int [capacity_]{}} {};

// copy constructor
Vector::Vector( const Vector &original ): length_(original.length_ ), capacity_(original.capacity_), array_{ new int [capacity_]{}}{
    for (std::size_t i { 0 }; i < length_; ++i) array_[i] = original.array_[i];
}

// copy assignment operator
Vector& Vector::operator=(const Vector &other) {

    if (this == &other) return *this;
    if (this->capacity_ != other.capacity_) { delete[] this->array_; array_ = new int[other.capacity_]; capacity_ = other.capacity_ ;};
    
    length_ = other.length_;

    for (std::size_t i{ 0 }; i < length_; ++i) array_[i] = other.array_[i];

    return *this;
}

// move constructor
Vector::Vector ( Vector &&original): length_(original.length_), capacity_(original.capacity_), array_{ original.array_} {
    original.array_ = nullptr;
    original.length_ = 0;
    original.capacity_ = 0;
}

// deconstructor
Vector::~Vector() { delete[] array_; array_ = nullptr; };

std::size_t Vector::length() const { return length_; };

std::size_t Vector::capacity() const { return capacity_; };

void Vector::operator+=( int elem ) { 
    // resize if not enough capacity.
    if ( length_ == capacity_ ) resize(capacity_ + 50);

    // set length_-th index to elem 
    array_[length_] = elem;
    ++length_;
};

void Vector::operator-=( int elem ) {
    if ( length_ == capacity_ ) resize(capacity_ + 50);
    array_[length_] = -elem;
    ++length_;
}

int& Vector::operator[]( std::size_t index ) {
    if (index >= capacity_) resize(index + 50);
    if (index >= length_) length_ = index + 1;
    return array_[index];
};

// private functions

void Vector::resize( std::size_t new_capacity ) {
    int* new_array_{ new int [new_capacity ] {} };
    for (std::size_t i{ 0 }; i < length_ && i < new_capacity; ++i) new_array_[i] = array_[i];
    delete[] array_;
    array_ = new_array_;
    capacity_ = new_capacity;
    if (length_ > capacity_) length_ = capacity_;

}

bool Vector::is_sorted() {
    for (std::size_t i { 0 }; i < length_ -1 ; ++i) if (array_[ i ] > array_[ i+1 ]) return false;
    return true;
}

void Vector::reverse() {
    std::size_t end { length_ - 1 };
    std::size_t start { 0 };
    // case odd
    if ( length_ % 2 ) {
        while ( start <= end ) {
            int temp = array_[start];
            array_[start] = array_[end];
            array_[end] = temp;
            start++; end--;
        }
    } else
    {
        while ( start <= end ) {
            if ( start == end ) return;
            else {
                int temp = array_[start];
                array_[start] = array_[end];
                array_[end] = temp;
                start++; end--;
            }
        }
    }
}

void Vector::sort() {
    if (length_ < 2) return;
    for ( std::size_t i { length_ - 1 }; i > 0; --i ) {
        std::size_t max_index{0};

        for (std::size_t j { 1 }; j <= i; ++j) {
            if ( array_[j] > array_[max_index]) {
                max_index = j;
            }
        }

        int temp{array_[max_index]};
        array_[max_index] = array_[i];
        array_[i] = temp;
    } 
}




int main() {
    Vector a{100};
    for ( std::size_t i { 0 }; i < 51; ++i ) {
        if (i % 2) a+=i;
        else a-=i;
    }
    std::cout << a.length() << std::endl;
    a+= 100;
    for ( std::size_t i { 0 }; i < a.length(); ++i ) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl << a.length() << " " << a.capacity() << std::endl;
    a.reverse();
    for ( std::size_t i { 0 }; i < a.length(); ++i ) {
        std::cout << a[i] << " ";
    }
    a.sort();
    std::cout << std::endl;
    for ( std::size_t i { 0 }; i < a.length(); ++i ) {
        std::cout << a[i] << " ";
    }   
}