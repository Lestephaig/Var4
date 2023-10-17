#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <fstream>
#include <stdexcept>

class Animal {
public:
    Animal();
    Animal(const std::string& breed, const std::string& color);
    Animal(const Animal& other);
    virtual ~Animal();

    const std::string& getBreed() const;
    void setBreed(const std::string& breed);
    const std::string& getColor() const;
    void setColor(const std::string& color);

    virtual void displayInfo() const = 0;
    virtual void updateInfo() = 0;

    Animal& operator=(const Animal& other) = default;

protected:
    std::string breed;
    std::string color;
};

#endif // ANIMAL_H
