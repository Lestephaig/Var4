#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include <iostream>
#include <memory>

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        Keeper keeper;

        while (true) {
            std::cout << "\nВыберите действие:\n";
            std::cout << "1. Добавить животное\n";
            std::cout << "2. Удалить животное\n";
            std::cout << "3. Вывести список животных\n";
            std::cout << "4. Сохранить в файл\n";
            std::cout << "5. Загрузить из файла\n";
            std::cout << "6. Изменить параметры животного\n";
            std::cout << "0. Выйти\n";

            
    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
