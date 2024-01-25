#include "balanced_brackets.cpp"

int main()
{
    Stack *stack = new Stack();

    stack->Push('2');
    stack->Push('3');
    stack->Push('5');

    stack->Display();
    std::cout << "size = " << stack->Size() << std::endl;

    std::cout << stack->Pop() << std::endl;
    std::cout << stack->Pop() << std::endl;

    stack->Display();

    std::cout << stack->Pop() << std::endl;
    std::cout << stack->Pop() << std::endl;

    stack->Push('8');

    Node* res1 = stack->Find('8');
    res1? std::cout << "found " << res1->data << std::endl : std::cout << "not found" << std::endl;

    Node* res2 = stack->Find('2');
    res2? std::cout << "found " << res2->data << std::endl : std::cout << "not found" << std::endl;

    bool status = BalancedBrackets::IsBalanced("[()]{}{[()()]()}");
    status? std::cout << "balanced" << std::endl : std::cout << "not balanced" << std::endl;
}
