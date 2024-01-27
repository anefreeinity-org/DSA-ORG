#include "n_array_tree.cpp"

int main()
{
    NArrayTree parent("lev 1");

    NArrayTree *child1 = parent.Insert("lev 2.1");
    child1->Insert("lev 3.2.1");
    child1->Insert("lev 3.2.2");

    parent.Insert("lev 2.2")->Insert("lev 3.2.2");
    parent.Insert("lev 2.3");

    parent.Display();
}