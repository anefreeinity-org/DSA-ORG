#include <queue>

class Node
{
public:
    std::queue<int> queue;
    int priority;

    Node(int priority)
    {
        this->priority = priority;
    }

    Node(int data, int priority)
    {
        this->priority = priority;
        queue.push(data);
    }
};