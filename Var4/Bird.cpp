#include "Bird.h"

Bird::Bird() : Animal(), feedingHabitat("") {
    std::cout << "Вызывается конструктор Bird по умолчанию." << std::endl;
}

Bird::Bird(const std::string& breed, const std::string& color, const std::string& feedingHabitat)
    : Animal(breed, color), feedingHabitat(feedingHabitat) {
    std::cout << "Вызывается параметризованный конструктор Bird." << std::endl;
}

Bird::Bird(const Bird& other) : Animal(other), feedingHabitat(other.feedingHabitat) {
    std::cout << "Bird copy constructor called." << std::endl;
}

const std::string& Bird::getFeedingHabitat() const {
    return feedingHabitat;
}

void Bird::setFeedingHabitat(const std::string& feedingHabitat) {
    this->feedingHabitat = feedingHabitat;
}

void Bird::displayInfo() const {
    std::cout << "Птица - Порода: " << breed << ", Цвет : " << color << ", Кормовая среда : " << feedingHabitat << std::endl;
}

void Bird::updateInfo() {
    std::cout << "Введите новое место обитания: ";
    std::cin >> feedingHabitat;
}
