#include <iomanip>
#include <iostream>
#include <memory>

int main() {
    int stack_value = 5;
    int stack_array[4] = {1, 2, 3, 4};

    auto heap_value = std::make_unique<int>(5);
    auto heap_array = std::make_unique<int[]>(4);
    for (int i = 0; i < 4; ++i) {
        heap_array[i] = (i + 1) * 10;
    }

    std::cout << "stack_value address: " << &stack_value << ", value: " << stack_value << '\n';
    std::cout << "heap_value ptr addr: " << heap_value.get() << ", value: " << *heap_value << '\n';
    std::cout << "stack_array base   : " << static_cast<void*>(stack_array)
              << ", next: " << static_cast<void*>(&stack_array[1]) << '\n';
    std::cout << "heap_array base    : " << heap_array.get() << ", next: " << &heap_array[1] << '\n';

    std::cout << "\nElements from heap_array:\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << "  [" << i << "] addr=" << &heap_array[i] << ", value=" << heap_array[i] << '\n';
    }

    std::cout << "\nObservation: stack and heap addresses come from different memory regions.\n";
    return 0;
}
