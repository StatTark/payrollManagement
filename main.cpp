#include <iostream>
#include <fstream>
#include <string>

#include "src/headers/company.h"
#include "src/headers/departments.h"
#include "src/headers/employee.h"
#include "src/headers/person.h"
#include "src/headers/title.h"
#include "src/headers/junior_worker.h"
#include "src/headers/senior_worker.h"
#include "src/headers/it.h"

int main() {
    //Header paramelerine referans verilecek

    Title *title;
    title = new SeniorWorker(12,"senior",2.0,3.0);

    Department *dep;
    std::list<Employee> kek = {};
    dep = new IT(1,"IT boi",14,kek);

    Person person = Person("Pelin Asude","1090-20-12","female","123123","istanbul","deneme@");

    //Employee emp = Employee(14,&person,title,dep,3000.0,"2020-12-13",20.0,"2020-12-14");

    



    return 0;
}
