#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <utility>

class my_vector_t {
private:
    int* data_m;
    size_t size_m;
    size_t capacity_m;

public:
    static constexpr size_t not_found = static_cast<size_t>(-1);

    explicit my_vector_t(size_t size = 0, int initial = 0);
    my_vector_t(const my_vector_t& other);
    my_vector_t(my_vector_t&& other) noexcept;
    ~my_vector_t();

    my_vector_t& operator=(const my_vector_t& other);
    my_vector_t& operator=(my_vector_t&& other) noexcept;

    size_t size() const noexcept;
    size_t capacity() const noexcept;
    bool empty() const noexcept;
    void clear() noexcept;
    void swap(my_vector_t& other) noexcept;

    void reserve(size_t new_capacity);
    void shrink_to_fit();
    void resize(size_t new_size, int new_value = 0);

    void push_back(int value);
    void insert(size_t idx, int value);
    void insert(size_t idx, const my_vector_t& other);

    void pop_back();
    void erase(size_t begin, size_t size);
    void erase(size_t idx);

    int& operator[](size_t idx);
    const int& operator[](size_t idx) const;
    int& at(size_t idx);
    const int& at(size_t idx) const;
    int& front();
    const int& front() const;
    int& back();
    const int& back() const;

    size_t find(int value, size_t idx = 0) const;

    void sort();
    void reverse();

    friend bool operator<(const my_vector_t& lhs, const my_vector_t& rhs);
    friend bool operator>(const my_vector_t& lhs, const my_vector_t& rhs);
    friend bool operator<=(const my_vector_t& lhs, const my_vector_t& rhs);
    friend bool operator>=(const my_vector_t& lhs, const my_vector_t& rhs);
    friend bool operator==(const my_vector_t& lhs, const my_vector_t& rhs);
    friend std::ostream& operator<<(std::ostream& stream, const my_vector_t& vec);
};

bool operator==(const my_vector_t& lhs, const my_vector_t& rhs);
bool operator!=(const my_vector_t& lhs, const my_vector_t& rhs);
bool operator<(const my_vector_t& lhs, const my_vector_t& rhs);
bool operator>(const my_vector_t& lhs, const my_vector_t& rhs);
bool operator<=(const my_vector_t& lhs, const my_vector_t& rhs);
bool operator>=(const my_vector_t& lhs, const my_vector_t& rhs);

std::ostream& operator<<(std::ostream& stream, const my_vector_t& vec);
std::istream& operator>>(std::istream& stream, my_vector_t& vec);

#endif