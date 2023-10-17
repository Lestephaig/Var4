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

void Keeper::clear() {
    animals.clear();
}
