#include "Cat.h"

Cat::Cat() : Animal(), ownerName(""), nickname("") {
    std::cout << "���������� ����������� Cat �� ���������." << std::endl;
}

Cat::Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& nickname)
    : Animal(breed, color), ownerName(ownerName), nickname(nickname) {
    std::cout << "���������� ����������������� ����������� Cat." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), ownerName(other.ownerName), nickname(other.nickname) {
    std::cout << "���������� ����������� ����������� Cat." << std::endl;
}

const std::string& Cat::getOwnerName() const {
    return ownerName;
}

void Cat::setOwnerName(const std::string& ownerName) {
    this->ownerName = ownerName;
}

const std::string& Cat::getNickname() const {
    return nickname;
}

void Cat::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}

void Cat::displayInfo() const {
    std::cout << "����� - ������: " << breed << ", ����: " << color << ", ��������: " << ownerName << ", ������: " << nickname << std::endl;
}

void Cat::updateInfo() {
    std::cout << "������� ����� ��� ���������: ";
    std::cin >> ownerName;
    std::cout << "������� ����� ������: ";
    std::cin >> nickname;
}
