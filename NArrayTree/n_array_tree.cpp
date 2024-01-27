#include <vector>
#include <string>
#include <iostream>

class NArrayTree
{
public:
    std::string message;
    std::vector<NArrayTree *> children;
    int levCount;

    NArrayTree(std::string message)
    {
        this->message = message;
        levCount = 0;
    }

    NArrayTree(std::string message, int levCount)
    {
        this->message = message;
        this->levCount = levCount;
    }

    NArrayTree *Insert(std::string message)
    {
        NArrayTree *temp = new NArrayTree(message, levCount + 1);
        children.push_back(temp);
        return temp;
    }

    void Display()
    {
        for (int i = 0; i < levCount; i++)
        {
            std::cout << "--";
        }
        std::cout << message << std::endl;

        for (NArrayTree *child : children)
        {
            child->Display();
        }
    }
};
