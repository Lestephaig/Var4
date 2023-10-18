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

            int choice;
            std::cin >> choice;

            if (choice == 0) {
                break;
            }

            switch (choice) {
            case 1: {
                std::cout << "Выберите категорию:\n";
                std::cout << "1. Рыба\n";
                std::cout << "2. Птица\n";
                std::cout << "3. Кошка\n";

                int categoryChoice;
                std::cin >> categoryChoice;

                std::string breed, color, param1, param2;

                std::cout << "Введите породу: ";
                std::cin >> breed;

                std::cout << "Введите цвет: ";
                std::cin >> color;

                if (categoryChoice == 1) {
                    std::cout << "Введите тип питания: ";
                    std::cin >> param1;
                    keeper.addAnimal(std::make_unique<Fish>(breed, color, param1));
                }
                else if (categoryChoice == 2) {
                    std::cout << "Введите место обитания: ";
                    std::cin >> param1;
                    keeper.addAnimal(std::make_unique<Bird>(breed, color, param1));
                }
                else if (categoryChoice == 3) {
                    std::cout << "Введите имя владельца: ";
                    std::cin >> param1;
                    std::cout << "Введите кличку: ";
                    std::cin >> param2;
                    keeper.addAnimal(std::make_unique<Cat>(breed, color, param1, param2));
                }
                else {
                    std::cout << "Некорректный выбор категории\n";
                }
                break;
            }
            case 2: {
                std::cout << "\nВведите индекс животного для удаления: ";
                size_t index;
                std::cin >> index;
                keeper.removeAnimal(index);
                break;
            }
            case 3: {
                std::cout << "\nСписок животных:\n";
                keeper.displayAllAnimals();
                break;
            }
            case 4: {
                std::cout << "\nВведите имя файла для сохранения: ";
                std::string filename;
                std::cin >> filename;
                keeper.saveToFile(filename);
                break;
            }
            case 5: {
                std::cout << "\nВведите имя файла для загрузки: ";
                std::string filename;
                std::cin >> filename;
                keeper.loadFromFile(filename);
                break;
            }
            case 6: {
                std::cout << "\nВведите индекс животного для изменения параметров: ";
                size_t index;
                std::cin >> index;

                if (index < keeper.getAnimalCount()) {
                    keeper.getAnimal(index)->updateInfo();
                }
                else {
                    std::cout << "Некорректный индекс\n\n";
                }
                break;
            }
            default:
                std::cout << "Некорректный выбор\n\n";
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
