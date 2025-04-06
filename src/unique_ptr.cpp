#include <iostream>
#include <memory>
#include <fstream>

// Использование std::unique_ptr 

class FileHandler {
    public:
        FileHandler(const std::string& filename) {
            // Создаём std::unique_ptr, который управляет объектом ofstream
            file = std::make_unique<std::ofstream>(filename);
    
            if (file->is_open()) {
                *file << "RAII работает!" << std::endl; 
            }
        }
    
        // Деструктор вызывается автоматически при уничтожении объекта FileHandler
        ~FileHandler() {
            std::cout << "Файл закрыт автоматически." << std::endl;
            // Не нужно вызывать file->close(), std::ofstream сделает это сам
            // std::unique_ptr автоматически освободит память
        }
    
    private:
        // Умный указатель unique_ptr управляет указателем на std::ofstream
        std::unique_ptr<std::ofstream> file;
    };
    

void useUniquePtr() {
    for (int i = 0; i < 10; ++i) {
        // Выделяем память
        std::unique_ptr<int[]> ptr(new int[100]);
        // std::unique_ptr сам вызовет delete[] при выходе из области видимости
    }

    // Создаём объект FileHandler, файл откроется
    FileHandler fh("example.txt");

    // Когда fh выйдет из области видимости — файл автоматически закроется
}
    

int main() {
    useUniquePtr();
    return 0;
}