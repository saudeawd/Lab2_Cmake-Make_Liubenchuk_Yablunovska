#include <iostream>
#include "myvector.hpp"

void demonstrate_constructors() {
    my_vector_t empty;
    std::cout << "Empty vector: " << empty << " (size: " << empty.size()
              << ", capacity: " << empty.capacity() << ")\n";

    my_vector_t sized(5, 42);
    std::cout << "Sized vector: " << sized << "\n";

    my_vector_t copy = sized;
    std::cout << "Copy: " << copy << "\n\n";
}

void demonstrate_basic_operations() {
    my_vector_t vec;
    for (int i = 1; i <= 5; ++i) vec.push_back(i*10);
    std::cout << "After push_back: " << vec << " (capacity: " << vec.capacity() << ")\n";

    vec[1] = 999;
    std::cout << "After modification: " << vec << "\n";

    size_t pos = vec.find(999);
    if (pos != my_vector_t::not_found) std::cout << "Found 999 at pos: " << pos << "\n\n";
}

void demonstrate_memory_management() {
    my_vector_t vec;
    for (int i = 0; i < 20; ++i) vec.push_back(i);
    std::cout << "Vector size: " << vec.size() << ", capacity: " << vec.capacity() << "\n";

    vec.shrink_to_fit();
    std::cout << "After shrink: size=" << vec.size() << ", capacity=" << vec.capacity() << "\n";

    vec.clear();
    std::cout << "After clear: size=" << vec.size() << ", capacity=" << vec.capacity() << "\n\n";
}

void demonstrate_advanced_operations() {
    my_vector_t vec(5);
    vec[0] = 5;
    vec[1] = 2;
    vec[2] = 8;
    vec[3] = 1;
    vec[4] = 9;
    vec.sort();
    std::cout << "Sorted: " << vec << "\n";
    vec.reverse();
    std::cout << "Reversed: " << vec << "\n";
    vec.insert(2, 777);
    std::cout << "After insert: " << vec << "\n";
    vec.erase(2);
    std::cout << "After erase: " << vec << "\n";
    vec.pop_back();
    std::cout << "After pop_back: " << vec << "\n\n";
}

void demonstrate_comparison() {
    my_vector_t v1(3);
    v1[0] = 1; v1[1] = 2; v1[2] = 3;

    my_vector_t v2(3);
    v2[0] = 1; v2[1] = 2; v2[2] = 3;

    my_vector_t v3(2);
    v3[0] = 4; v3[1] = 5;

    std::cout << "v1==v2: " << (v1==v2) << ", v1==v3: " << (v1==v3) << ", v1!=v3: " << (v1!=v3) << "\n";
    std::cout << "v1<v3: " << (v1<v3) << ", v1>v3: " << (v1>v3) << "\n\n";
}

void demonstrate_error_handling() {
    my_vector_t vec{10,20};
    try { vec.at(5); } catch (const std::out_of_range& e) { std::cout << e.what() << "\n"; }
    try { vec.insert(10,100); } catch (const std::out_of_range& e) { std::cout << e.what() << "\n"; }
    std::cout << "\n";
}

int main() {
    try {
        demonstrate_constructors();
        demonstrate_basic_operations();
        demonstrate_memory_management();
        demonstrate_advanced_operations();
        demonstrate_comparison();
        demonstrate_error_handling();
        std::cout << "All demonstrations completed successfully!\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
