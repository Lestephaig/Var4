#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public Animal {
public:
    Fish();
    Fish(const std::string& breed, const std::string& color, const std::string& feedingType);
    Fish(const Fish& other);
    ~Fish() override = default;

    const std::string& getFeedingType() const;
    void setFeedingType(const std::string& feedingType);

    void displayInfo() const override;
    void updateInfo() override;

private:
    std::string feedingType;
};

#endif // FISH_H
