#ifndef KEEPER_H
#define KEEPER_H

#include "Animal.h"
#include <vector>

class Keeper {
public:
    Keeper();
    ~Keeper();

    void addAnimal(std::unique_ptr<Animal> animal);
    void removeAnimal(size_t index);

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    void displayAllAnimals() const;

    Animal* getAnimal(size_t index) const;
    size_t getAnimalCount() const;

    void updateAnimalInfo(size_t index);

private:
    std::vector<std::unique_ptr<Animal>> animals;

    void clear();
};

#endif // KEEPER_H
