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
            std::cout << "\n�������� ��������:\n";
            std::cout << "1. �������� ��������\n";
            std::cout << "2. ������� ��������\n";
            std::cout << "3. ������� ������ ��������\n";
            std::cout << "4. ��������� � ����\n";
            std::cout << "5. ��������� �� �����\n";
            std::cout << "6. �������� ��������� ���������\n";
            std::cout << "0. �����\n";

            int choice;
            std::cin >> choice;

            if (choice == 0) {
                break;
            }

            switch (choice) {
            case 1: {
                std::cout << "�������� ���������:\n";
                std::cout << "1. ����\n";
                std::cout << "2. �����\n";
                std::cout << "3. �����\n";

                int categoryChoice;
                std::cin >> categoryChoice;

                std::string breed, color, param1, param2;

                std::cout << "������� ������: ";
                std::cin >> breed;

                std::cout << "������� ����: ";
                std::cin >> color;

                if (categoryChoice == 1) {
                    std::cout << "������� ��� �������: ";
                    std::cin >> param1;
                    keeper.addAnimal(std::make_unique<Fish>(breed, color, param1));
                }
                else if (categoryChoice == 2) {
                    std::cout << "������� ����� ��������: ";
                    std::cin >> param1;
                    keeper.addAnimal(std::make_unique<Bird>(breed, color, param1));
                }
                else if (categoryChoice == 3) {
                    std::cout << "������� ��� ���������: ";
                    std::cin >> param1;
                    std::cout << "������� ������: ";
                    std::cin >> param2;
                    keeper.addAnimal(std::make_unique<Cat>(breed, color, param1, param2));
                }
                else {
                    std::cout << "������������ ����� ���������\n";
                }
                break;
            }
            case 2: {
                std::cout << "\n������� ������ ��������� ��� ��������: ";
                size_t index;
                std::cin >> index;
                keeper.removeAnimal(index);
                break;
            }
            case 3: {
                std::cout << "\n������ ��������:\n";
                keeper.displayAllAnimals();
                break;
            }
            case 4: {
                std::cout << "\n������� ��� ����� ��� ����������: ";
                std::string filename;
                std::cin >> filename;
                keeper.saveToFile(filename);
                break;
            }
            case 5: {
                std::cout << "\n������� ��� ����� ��� ��������: ";
                std::string filename;
                std::cin >> filename;
                keeper.loadFromFile(filename);
                break;
            }
            case 6: {
                std::cout << "\n������� ������ ��������� ��� ��������� ����������: ";
                size_t index;
                std::cin >> index;

                if (index < keeper.getAnimalCount()) {
                    keeper.getAnimal(index)->updateInfo();
                }
                else {
                    std::cout << "������������ ������\n\n";
                }
                break;
            }
            default:
                std::cout << "������������ �����\n\n";
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "����������: " << e.what() << std::endl;
    }

    return 0;
}
