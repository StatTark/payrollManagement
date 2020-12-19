#include "../headers/database.h"

std::vector<std::vector<std::string>> DatabaseWorker::exec_query(std::string query)
{
    std::vector<std::vector<std::string>> result;
    std::string myText;

    std::ofstream MyFile("databaseCollaborator.txt");
    MyFile << query;
    MyFile.close();

    std::string cmd = "python ./database.py";
    system(cmd.c_str());

    std::ifstream MyReadFile("databaseCollaborator.txt");

    while (getline(MyReadFile, myText))
    {
        std::vector<std::string> temp;
        std::string word;

        for (auto ch : myText)
        {
            if (ch == ',')
            {
                temp.push_back(word);
                word = "";
            }
            else
            {
                word += ch;
            }
        }
        result.push_back(temp);
    }
    MyReadFile.close();

    return result;
}
