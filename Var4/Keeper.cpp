#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

Keeper::Keeper() {
    std::cout << "The default Keeper constructor is called." << std::endl;
}

Keeper::~Keeper() {
    std::cout << "The Keeper destructor is called." << std::endl;
}

void Keeper::addAnimal(std::unique_ptr<Animal> animal) {
    animals.push_back(std::move(animal));
}

void Keeper::removeAnimal(size_t index) {
    if (index < animals.size()) {
        animals.erase(animals.begin() + index);
    }
    else {
        throw std::out_of_range("Неверный индекс удаления животных");
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Невозможно открыть файл для записи");
    }

    for (const auto& animal : animals) {
        file << animal->getBreed() << " " << animal->getColor() << " ";

        if (auto fish = dynamic_cast<Fish*>(animal.get())) {
            file << fish->getFeedingType();
        }
        else if (auto bird = dynamic_cast<Bird*>(animal.get())) {
            file << bird->getFeedingHabitat();
        }
        else if (auto cat = dynamic_cast<Cat*>(animal.get())) {
            file << cat->getOwnerName() << "@" << cat->getNickname();
        }

        file << std::endl;
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    clear();
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Невозможно открыть файл для чтения.");
    }

    std::string breed, color, feedingInfo;
    while (file >> breed >> color >> feedingInfo) {
        if (feedingInfo.find('@') != std::string::npos) {
            std::string ownerName = feedingInfo.substr(0, feedingInfo.find('@'));
            std::string nickname = feedingInfo.substr(feedingInfo.find('@') + 1);
            addAnimal(std::make_unique<Cat>(breed, color, ownerName, nickname));
        }
        else if (feedingInfo.find('/') != std::string::npos) {
            std::string feedingHabitat = feedingInfo.substr(feedingInfo.find('/') + 1);
            addAnimal(std::make_unique<Bird>(breed, color, feedingHabitat));
        }
        else {
            addAnimal(std::make_unique<Fish>(breed, color, feedingInfo));
        }
    }
}

Animal* Keeper::getAnimal(size_t index) const {
    if (index < animals.size()) {
        return animals[index].get();
    }
    else {
        return nullptr;
    }
}

void Keeper::updateAnimalInfo(size_t index) {
    if (index < animals.size()) {
        animals[index]->updateInfo();
    }
    else {
        std::cout << "Некорректный индекс\n";
    }
}

size_t Keeper::getAnimalCount() const {
    return animals.size();
}

void Keeper::displayAllAnimals() const {
    for (const auto& animal : animals) {
        animal->displayInfo();
    }
}

void Keeper::clear() {
    animals.clear();
}
