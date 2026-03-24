#include <cstring>
#include <iostream>
#include <utility>

class Buffer {
public:
    explicit Buffer(std::size_t size)
        : size_(size), data_(new int[size] {}) {
        std::cout << "[ctor] Buffer(" << size_ << ") at " << this << '\n';
    }

    ~Buffer() {
        std::cout << "[dtor] Buffer at " << this << " frees data " << data_ << '\n';
        delete[] data_;
    }

    Buffer(const Buffer& other)
        : size_(other.size_), data_(new int[other.size_]) {
        std::memcpy(data_, other.data_, size_ * sizeof(int));
        std::cout << "[copy ctor] from " << &other << " -> " << this << '\n';
    }

    Buffer& operator=(const Buffer& other) {
        std::cout << "[copy assign] from " << &other << " -> " << this << '\n';
        if (this == &other) {
            return *this;
        }

        int* new_data = new int[other.size_];
        std::memcpy(new_data, other.data_, other.size_ * sizeof(int));

        delete[] data_;
        data_ = new_data;
        size_ = other.size_;
        return *this;
    }

    Buffer(Buffer&& other) noexcept
        : size_(other.size_), data_(other.data_) {
        other.size_ = 0;
        other.data_ = nullptr;
        std::cout << "[move ctor] from " << &other << " -> " << this << '\n';
    }

    Buffer& operator=(Buffer&& other) noexcept {
        std::cout << "[move assign] from " << &other << " -> " << this << '\n';
        if (this == &other) {
            return *this;
        }

        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;

        other.data_ = nullptr;
        other.size_ = 0;
        return *this;
    }

    void set(std::size_t index, int value) {
        if (index < size_) {
            data_[index] = value;
        }
    }

    int get(std::size_t index) const {
        return (index < size_) ? data_[index] : -1;
    }

private:
    std::size_t size_;
    int* data_;
};

int main() {
    std::cout << "=== 1) Construction ===\n";
    Buffer a(4);
    a.set(0, 42);

    std::cout << "\n=== 2) Copy constructor ===\n";
    Buffer b = a;
    std::cout << "a[0]=" << a.get(0) << ", b[0]=" << b.get(0) << '\n';

    std::cout << "\n=== 3) Copy assignment ===\n";
    Buffer c(2);
    c = b;
    std::cout << "c[0]=" << c.get(0) << '\n';

    std::cout << "\n=== 4) Move constructor ===\n";
    Buffer d = std::move(c);
    std::cout << "d[0]=" << d.get(0) << '\n';

    std::cout << "\n=== 5) Move assignment ===\n";
    Buffer e(1);
    e = std::move(d);
    std::cout << "e[0]=" << e.get(0) << '\n';

    std::cout << "\n=== End of main: destructors will run ===\n";
    return 0;
}
