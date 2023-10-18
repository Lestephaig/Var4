#include "Bird.h"

Bird::Bird() : Animal(), feedingHabitat("") {
    std::cout << "���������� ����������� Bird �� ���������." << std::endl;
}

Bird::Bird(const std::string& breed, const std::string& color, const std::string& feedingHabitat)
    : Animal(breed, color), feedingHabitat(feedingHabitat) {
    std::cout << "���������� ����������������� ����������� Bird." << std::endl;
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
    std::cout << "����� - ������: " << breed << ", ���� : " << color << ", �������� ����� : " << feedingHabitat << std::endl;
}

void Bird::updateInfo() {
    std::cout << "������� ����� ����� ��������: ";
    std::cin >> feedingHabitat;
}
