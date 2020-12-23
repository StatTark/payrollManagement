#include "../headers/helpers.h"

void printDatas(std::vector<std::vector<std::string>> &vect, int *sizes, int width)
{
    int size = vect.size();
    for (int i = 0; i < size; i++)
    {
        int j = 0;
        std::cout << std::string(width, '-') << "\n";
        for (
            auto it = vect[i].begin();
            it != vect[i].end(); it++)
        {
            std::cout << *it << std::string(*(sizes + j) + 18 - it->length(), ' ');
            j++;
        }
        std::cout << "\n"
                  << std::string(width, '-') << "\n";
    }
}

void showArt()
{
    std::string myText;

    std::ifstream MyReadFile("art.txt");

    while (getline(MyReadFile, myText))
    {
        std::cout << myText << "\n";
    }
    MyReadFile.close();

}