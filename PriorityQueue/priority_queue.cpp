#include <map>
#include "./max_heap.cpp"

class PriorityQueue
{
public:
    MaxHeap heap;
    std::map<int, Node *> map;

    void Enqueue(int data, int priority)
    {
        if (map[priority] == nullptr)
        {
            map[priority] = heap.Insert(data, priority);
        }
        else
        {
            map[priority]->queue.push(data);
        }
    }

    int Dequeue()
    {
        Node *temp = heap.GetTop();
        int retval = temp->queue.front();
        temp->queue.pop();
        if (temp->queue.size() == 0)
        {
            map.erase(temp->priority);
            heap.Delete();
        }
        return retval;
    }
};