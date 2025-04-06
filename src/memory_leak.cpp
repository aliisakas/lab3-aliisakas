#include <iostream>

// Демонстрация утечки памяти

void memoryLeak() {
    for (int i = 0; i < 10; ++i) {
        int* ptr = new int[100]; // Выделяем память

        // Присваиваем значения массиву и выводим их
        for (int j = 0; j < 10; ++j) { // Выведем только первые 10 элементов 
            ptr[j] = j + i; // Присваиваем значения
            std::cout << "Массив " << i << ", элемент " << j << ": " << ptr[j] << std::endl;
        }

        // Нет delete[] — утечка памяти
    }
}

int main() {
    std::cout << "Программа начинается..." << std::endl;
    memoryLeak();
    std::cout << "Программа завершена." << std::endl;
    return 0;
}
