#include "Animal.h"

Animal::Animal() : breed(""), color("") {
    std::cout << "\n���������� ����������� �� ��������� ��� ��������." << std::endl;
}

Animal::Animal(const std::string& breed, const std::string& color)
    : breed(breed), color(color) {
    std::cout << "\n���������� ����������������� ����������� ��������." << std::endl;
}

Animal::Animal(const Animal& other)
    : breed(other.breed), color(other.color) {
    std::cout << "\n���������� ����������� ����������� ��������." << std::endl;
}

Animal::~Animal() {
    std::cout << "\n���������� ���������� ��������." << std::endl;
}

const std::string& Animal::getBreed() const {
    return breed;
}

void Animal::setBreed(const std::string& breed) {
    this->breed = breed;
}

const std::string& Animal::getColor() const {
    return color;
}

void Animal::setColor(const std::string& color) {
    this->color = color;
}

void Animal::updateInfo() {
    std::cout << "���� ��� ��������� �� ������������ ���������� ����������." << std::endl;
}
