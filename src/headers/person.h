#ifndef PAYROLL_PERSON_H
#define PAYROLL_PERSON_H

#include <string>
class Person
{ //private class
private:
    std::string name;
    std::string dateOfBirth;
    std::string gender;
    std::string phoneNumber;
    std::string address;
    std::string email;

    //CONSTRUCTOR
public:
    Person(std::string nam,
           std::string dateOfBirt,
           std::string gende,
           std::string phoneNumbe,
           std::string addres,
           std::string emai ) {
               name = nam,
               dateOfBirth = dateOfBirt,
               gender = gende,
               phoneNumber = phoneNumbe,
               address = addres;
               email = emai;
           }

    Person() = default;
    //getter - setter
};

#endif //PAYROLL_PERSON_H
