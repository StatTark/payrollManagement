#include <iostream>
#include <fstream>
#include <string>

#include "src/headers/accountant.h"
#include "src/headers/company.h"
#include "src/headers/departments.h"
#include "src/headers/employee.h"
#include "src/headers/person.h"
#include "src/headers/title.h"
#include "src/headers/it.h"
#include "src/headers/database.h"

int main()
{   
    Accountant acc = Accountant();

    acc.showDepartmentsEmployees(1);


    return 0;
}
