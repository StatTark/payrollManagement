#include "../headers/database.h"

std::vector<std::string> DatabaseWorker::pullAnything() {
    std::vector<std::string> result;
    std::string myText;
    std::string myText2;
    std::string myText3;

    std::ofstream MyFile("databaseCollaborator.txt");
    MyFile << query;
    MyFile.close();

    std::string cmd = "python C:/Users/StatTark/CLionProjects/payroll/database.py";
    system(cmd.c_str());

    std::ifstream MyReadFile("databaseCollaborator.txt");


    while (getline (MyReadFile, myText)) {
            myText2 += myText;
    }
    MyReadFile.close();

    for (auto  x : myText2){
        if (x == ' '){
            result.push_back(myText3);
            myText3 = "";
        }
        else{
            myText3 += x;
        }
    }
    /*for(int i =0;i<result.max_size();i++){
        std::cout<<result[i]<<std::endl; // '<' isaretini gorunce 2. satira gecmis demektir.
    }*/

    return result;

    }


