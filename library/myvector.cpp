#include "myvector.hpp"
#include <algorithm>
#include <utility>

my_vector_t::my_vector_t(size_t size, int initial)
    : data_m(nullptr), size_m(size), capacity_m(size) {
    if (size > 0) {
        data_m = new int[capacity_m];
        std::fill_n(data_m, size_m, initial);
    }
}

my_vector_t::my_vector_t(const my_vector_t& other)
    : size_m(other.size_m), capacity_m(other.capacity_m) {
    if (other.data_m && size_m > 0) {
        data_m = new int[capacity_m];
        std::copy(other.data_m, other.data_m + size_m, data_m);
    } else {
        data_m = nullptr;
    }
}

my_vector_t::my_vector_t(my_vector_t&& other) noexcept
    : data_m(other.data_m), size_m(other.size_m), capacity_m(other.capacity_m) {
    other.data_m = nullptr;
    other.size_m = 0;
    other.capacity_m = 0;
}

my_vector_t::~my_vector_t() {
    delete[] data_m;
}

my_vector_t& my_vector_t::operator=(const my_vector_t& other) {
    if (this != &other) {
        my_vector_t temp(other);
        swap(temp);
    }
    return *this;
}

my_vector_t& my_vector_t::operator=(my_vector_t&& other) noexcept {
    if (this != &other) {
        delete[] data_m;
        data_m = other.data_m;
        size_m = other.size_m;
        capacity_m = other.capacity_m;

        other.data_m = nullptr;
        other.size_m = 0;
        other.capacity_m = 0;
    }
    return *this;
}

size_t my_vector_t::size() const noexcept { return size_m; }
size_t my_vector_t::capacity() const noexcept { return capacity_m; }

bool my_vector_t::empty() const noexcept {
    return size_m == 0;
}

void my_vector_t::clear() noexcept {
    size_m = 0;
}

void my_vector_t::swap(my_vector_t& other) noexcept {
    std::swap(data_m, other.data_m);
    std::swap(size_m, other.size_m);
    std::swap(capacity_m, other.capacity_m);
}

void my_vector_t::reserve(size_t new_capacity) {
    if (new_capacity <= capacity_m) return;

    size_t grown_capacity = std::max(capacity_m * 2, new_capacity);
    grown_capacity = std::max(grown_capacity, static_cast<size_t>(8));

    int* new_data = new int[grown_capacity];

    if (data_m && size_m > 0) {
        std::copy(data_m, data_m + size_m, new_data);
    }

    delete[] data_m;
    data_m = new_data;
    capacity_m = grown_capacity;
}

void my_vector_t::shrink_to_fit() {
    if (size_m == capacity_m) return;

    if (size_m == 0) {
        delete[] data_m;
        data_m = nullptr;
        capacity_m = 0;
        return;
    }

    int* new_data = new int[size_m];
    std::copy(data_m, data_m + size_m, new_data);

    delete[] data_m;
    data_m = new_data;
    capacity_m = size_m;
}

void my_vector_t::resize(size_t new_size, int new_value) {
    if (new_size > capacity_m) {
        reserve(new_size);
    }

    if (new_size > size_m) {
        std::fill(data_m + size_m, data_m + new_size, new_value);
    }

    size_m = new_size;
}

void my_vector_t::push_back(int value) {
    if (size_m >= capacity_m) {
        reserve(capacity_m == 0 ? 8 : capacity_m * 2);
    }
    data_m[size_m++] = value;
}

void my_vector_t::insert(size_t idx, int value) {
    if (idx > size_m) throw std::out_of_range("Index out of range");

    if (size_m + 1 > capacity_m) {
        reserve(std::max(size_m + 1, capacity_m * 2));
    }

    if (idx < size_m) {
        std::move_backward(data_m + idx, data_m + size_m, data_m + size_m + 1);
    }

    data_m[idx] = value;
    size_m++;
}

void my_vector_t::insert(size_t idx, const my_vector_t& other) {
    if (idx > size_m) throw std::out_of_range("Index out of range");

    size_t new_size = size_m + other.size_m;
    if (new_size > capacity_m) {
        reserve(std::max(new_size, capacity_m * 2));
    }

    if (idx < size_m) {
        std::move_backward(data_m + idx, data_m + size_m, data_m + new_size);
    }

    std::copy(other.data_m, other.data_m + other.size_m, data_m + idx);
    size_m = new_size;
}

void my_vector_t::pop_back() {
    if (size_m > 0) {
        size_m--;
    }
}

void my_vector_t::erase(size_t begin, size_t size) {
    if (begin > size_m) throw std::out_of_range("Index out of range");

    size_t end = std::min(begin + size, size_m);
    size_t erase_size = end - begin;

    if (erase_size == 0) return;

    if (end < size_m) {
        std::move(data_m + end, data_m + size_m, data_m + begin);
    }

    size_m -= erase_size;
}

void my_vector_t::erase(size_t idx) {
    erase(idx, 1);
}

int& my_vector_t::operator[](size_t idx) {
    return data_m[idx];
}

const int& my_vector_t::operator[](size_t idx) const {
    return data_m[idx];
}

int& my_vector_t::at(size_t idx) {
    if (idx >= size_m) throw std::out_of_range("Index out of range");
    return data_m[idx];
}

const int& my_vector_t::at(size_t idx) const {
    if (idx >= size_m) throw std::out_of_range("Index out of range");
    return data_m[idx];
}

int& my_vector_t::front() {
    if (empty()) throw std::out_of_range("Vector is empty");
    return data_m[0];
}

const int& my_vector_t::front() const {
    if (empty()) throw std::out_of_range("Vector is empty");
    return data_m[0];
}

int& my_vector_t::back() {
    if (empty()) throw std::out_of_range("Vector is empty");
    return data_m[size_m - 1];
}

const int& my_vector_t::back() const {
    if (empty()) throw std::out_of_range("Vector is empty");
    return data_m[size_m - 1];
}

size_t my_vector_t::find(int value, size_t idx) const {
    if (idx > size_m) throw std::out_of_range("Index out of range");

    for (size_t i = idx; i < size_m; ++i) {
        if (data_m[i] == value) return i;
    }
    return not_found;
}

void my_vector_t::sort() {
    std::sort(data_m, data_m + size_m);
}

void my_vector_t::reverse() {
    std::reverse(data_m, data_m + size_m);
}

bool operator==(const my_vector_t& lhs, const my_vector_t& rhs) {
    if (lhs.size_m != rhs.size_m) return false;

    return std::equal(lhs.data_m, lhs.data_m + lhs.size_m, rhs.data_m);
}

bool operator!=(const my_vector_t& lhs, const my_vector_t& rhs) {
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& stream, const my_vector_t& vec) {
    stream << "[";
    for (size_t i = 0; i < vec.size_m; ++i) {
        stream << vec.data_m[i];
        if (i < vec.size_m - 1) stream << ", ";
    }
    stream << "]";
    return stream;
}

std::istream& operator>>(std::istream& stream, my_vector_t& vec) {
    vec.clear();
    int value;
    while (stream >> value) {
        vec.push_back(value);
    }
    if (stream.eof()) {
        stream.clear();
    }
    return stream;
}
bool operator<(const my_vector_t& lhs, const my_vector_t& rhs) {
    return std::lexicographical_compare(lhs.data_m, lhs.data_m + lhs.size_m,
                                       rhs.data_m, rhs.data_m + rhs.size_m);
}

bool operator>(const my_vector_t& lhs, const my_vector_t& rhs) {
    return rhs < lhs;
}

bool operator<=(const my_vector_t& lhs, const my_vector_t& rhs) {
    return !(rhs < lhs);
}

bool operator>=(const my_vector_t& lhs, const my_vector_t& rhs) {
    return !(lhs < rhs);
}