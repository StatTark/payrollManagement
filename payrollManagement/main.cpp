#include <iostream>
#include <fstream>
#include <string>

#include "src/headers/company.h"
#include "src/headers/departments.h"
#include "src/headers/employee.h"
#include "src/headers/person.h"
#include "src/headers/title.h"
#include "src/headers/junior_worker.h"

int main() {
    //Header paramelerine referans verilecek
    Title *title;
    title = new JuniorWorker(12,"senior",2.0,3.0);
    
    return 0;
}
