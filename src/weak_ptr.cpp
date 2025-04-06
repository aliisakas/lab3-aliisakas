#include <iostream>
#include <memory>

// Использование std::weak_ptr

class Observer {
public:
    void observe(std::weak_ptr<int> w_ptr) {
        if (auto sh_ptr = w_ptr.lock()) {
            std::cout << "Наблюдаемый объект жив: " << *sh_ptr << std::endl;
        } else {
            std::cout << "Объект уже уничтожен." << std::endl;
        }
    }
};

void useWeakPtr() {
    std::weak_ptr<int> weak;
    {
        auto shared = std::make_shared<int>(100);
        weak = shared;

        Observer obs1;
        obs1.observe(weak); // Объект жив
    } 
    // shared_ptr удалён, объект уничтожен

    Observer obs2;
    obs2.observe(weak); // Объект уничтожен
}

int main() {
    useWeakPtr();
    return 0;
}