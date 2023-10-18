#include "Fish.h"

Fish::Fish() : Animal(), feedingType("") {
    std::cout << "���������� ����������� Fish �� ���������." << std::endl;
}

Fish::Fish(const std::string& breed, const std::string& color, const std::string& feedingType)
    : Animal(breed, color), feedingType(feedingType) {
    std::cout << "���������� ����������������� ����������� Fish." << std::endl;
}

Fish::Fish(const Fish& other) : Animal(other), feedingType(other.feedingType) {
    std::cout << "���������� ����������� ����������� ����." << std::endl;
}

const std::string& Fish::getFeedingType() const {
    return feedingType;
}

void Fish::setFeedingType(const std::string& feedingType) {
    this->feedingType = feedingType;
}

void Fish::displayInfo() const {
    std::cout << "���� - ������: " << breed << ", ����: " << color << ", ��� �������: " << feedingType << std::endl;
}

void Fish::updateInfo() {
    std::cout << "������� ����� ��� �������: ";
    std::cin >> feedingType;
}
