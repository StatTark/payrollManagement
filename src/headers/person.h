#ifndef PAYROLL_PERSON_H
#define PAYROLL_PERSON_H

#include <string>
class Person
{ //private class
private:
    int personID;
    std::string name;
    std::string dateOfBirth;
    std::string gender;
    std::string phoneNumber;
    std::string address;
    std::string email;

    //CONSTRUCTOR
public:
    Person()=default;
    Person(int perID,
        std::string nam,
           std::string dateOfBirt,
           std::string gende,
           std::string phoneNumbe,
           std::string addres,
           std::string emai ) {
               personID = perID;
               name = nam;
               dateOfBirth = dateOfBirt;
               gender = gende;
               phoneNumber = phoneNumbe;
               address = addres;
               email = emai;
           }
    // getters
    int getPersonID() {return personID;};
    std::string getName() {return name;};
    std::string getDateOfBirth() {return dateOfBirth;};
    std::string getGender() {return gender;};
    std::string getPhoneNumber (){return phoneNumber;};
    std::string getAddress(){return address;};
    std::string getEmail(){return email;};
    // setters
    void setName(std::string i_name) {name = i_name;};
};

#endif //PAYROLL_PERSON_H
