#include <iostream>
#include <memory>

// Использование std::shared_ptr

class Data {
public:
    Data(int v) : value(v) {
        std::cout << "Data создана: " << value << std::endl;
    }
    ~Data() {
        std::cout << "Data удалена: " << value << std::endl;
    }
    int value;
};

void useSharedPtr() {
    std::shared_ptr<Data> ptr1 = std::make_shared<Data>(52);
    {
        std::shared_ptr<Data> ptr2 = ptr1; // ptr1 и ptr2 владеют объектом
        std::cout << "Счётчик: " << ptr1.use_count() << std::endl;
    } // ptr2 удаляется, ptr1 всё ещё жив
    std::cout << "Счётчик: " << ptr1.use_count() << std::endl;
}

int main() {
    useSharedPtr();
    return 0;
}
