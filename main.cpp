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
    Employee slave = Employee();
    slave.setName("yolo brah");
    std::cout << slave.getName() << "\n";
    // DatabaseWorker sorgu = DatabaseWorker("INSERT INTO `users`( `name`, `username`) VALUES ('deneme','deneme2')"); //Insert
    // DatabaseWorker sorgu2 = DatabaseWorker("UPDATE `users` SET `name`='rauf' WHERE id=1");                         //Update
    // DatabaseWorker sorgu3 = DatabaseWorker("DELETE FROM `users` WHERE id=2");       
    // DatabaseWorker sorgu4 = DatabaseWorker("SELECT * FROM users;");                               //delete
    // std::vector<std::vector<std::string>> database = sorgu4.doAnything();

    // for (int i = 0; i < database.max_size(); i++)
    // {
    //     std::cout << "id :"<<database[i][0] <<" date: " << database[i][3]<<"\n";
    //     // '<' isaretini gorunce 2. satira gecmis demektir.
    // }

    return 0;
}
