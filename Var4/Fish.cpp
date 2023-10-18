#include "Fish.h"

Fish::Fish() : Animal(), feedingType("") {
    std::cout << "Вызывается конструктор Fish по умолчанию." << std::endl;
}

Fish::Fish(const std::string& breed, const std::string& color, const std::string& feedingType)
    : Animal(breed, color), feedingType(feedingType) {
    std::cout << "Вызывается параметризованный конструктор Fish." << std::endl;
}

Fish::Fish(const Fish& other) : Animal(other), feedingType(other.feedingType) {
    std::cout << "Вызывается конструктор копирования рыбы." << std::endl;
}

const std::string& Fish::getFeedingType() const {
    return feedingType;
}

void Fish::setFeedingType(const std::string& feedingType) {
    this->feedingType = feedingType;
}

void Fish::displayInfo() const {
    std::cout << "Рыба - Порода: " << breed << ", Цвет: " << color << ", Тип питания: " << feedingType << std::endl;
}

void Fish::updateInfo() {
    std::cout << "Введите новый тип питания: ";
    std::cin >> feedingType;
}
