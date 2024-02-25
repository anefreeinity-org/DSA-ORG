#include "n_array_tree.cpp"

int main()
{
    NArrayTree parent("lev 1");

    NArrayTree *child1 = parent.Insert("lev 1-2.1");
    child1->Insert("lev 1-2.1-3.1");
    child1->Insert("lev 1-2.1-3.2");

    parent.Insert("lev 1-2.2")->Insert("lev 1-2.2-3.1");
    parent.Insert("lev 1-2.3");

    parent.Display();
    std::cout << std::endl;

    parent.Delete("lev 1-2.1");
    std::cout << std::endl;

    parent.Display();
    std::cout << std::endl;
}
