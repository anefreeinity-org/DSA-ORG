#include <vector>
#include <string>
#include <iostream>

class NArrayTree
{
public:
    std::string message;
    std::vector<NArrayTree *> children;
    int levCount;
    bool isDeleted;

    NArrayTree(std::string message)
    {
        this->message = message;
        levCount = 0;
        isDeleted = false;
    }

    NArrayTree(std::string message, int levCount)
    {
        this->message = message;
        this->levCount = levCount;
        isDeleted = false;
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

    void Delete(std::string message)
    {
        if (this->message == message)
        {
            DeleteAllChildren(this);
        }

        int pos = -1;
        for (int i = 0; i < children.size(); i++)
        {
            if (children[i]->message == message)
            {
                pos = i;
            }
            children[i]->Delete(message);
            if (pos != -1 && pos < children.size() && children[pos]->message == message)
            {
                delete children[pos];
                children.erase(children.begin() + pos);
            }
        }
    }

    void DeleteAllChildren(NArrayTree *node)
    {
        for (NArrayTree *child : node->children)
        {
            DeleteAllChildren(child);
            delete child;
        }
        children.clear();
    }

    ~NArrayTree()
    {
        std::cout << "deleted: " << message << std::endl;
    }
};
