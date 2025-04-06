#include <iostream>

// Демонстрация утечки памяти

void memoryLeak() {
    for (int i = 0; i < 10; ++i) {
        int* ptr = new int[100]; // Выделяем память
        // Нет delete[] — утечка памяти
    }
}

int main() {
    memoryLeak();
    return 0;
}
