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
    void setID(int i_id) {personID = i_id;};
    void setName(std::string i_name) {name = i_name;};
    void setDateOfBirth(std::string i_dob) {dateOfBirth = i_dob;};
    void setGender(std::string i_gender) {gender = i_gender;};
    void setPhoneNumber(std::string i_num) {phoneNumber = i_num;};
    void setAddress(std::string i_add) {address = i_add;};
    void setEmail(std::string i_em) {email = i_em;};
};

#endif //PAYROLL_PERSON_H
