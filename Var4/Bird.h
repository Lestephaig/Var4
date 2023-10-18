#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
public:
    Bird();
    Bird(const std::string& breed, const std::string& color, const std::string& feedingHabitat);
    Bird(const Bird& other);
    ~Bird() override = default;

    const std::string& getFeedingHabitat() const;
    void setFeedingHabitat(const std::string& feedingHabitat);

    void displayInfo() const override;
    void updateInfo() override;

private:
    std::string feedingHabitat;
};

#endif // BIRD_H
