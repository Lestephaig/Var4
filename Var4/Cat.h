#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
    Cat();
    Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& nickname);
    Cat(const Cat& other);
    ~Cat() override = default;

    const std::string& getOwnerName() const;
    void setOwnerName(const std::string& ownerName);
    const std::string& getNickname() const;
    void setNickname(const std::string& nickname);

    void displayInfo() const override;
    void updateInfo() override;

private:
    std::string ownerName;
    std::string nickname;
};

#endif // CAT_H
