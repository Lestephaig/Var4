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

            
    }
    catch (const std::exception& e) {
        std::cerr << "����������: " << e.what() << std::endl;
    }

    return 0;
}
