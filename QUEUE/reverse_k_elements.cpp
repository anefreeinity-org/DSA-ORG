#include "queue.cpp"

class ReverseKElements
{
public:
    static void ReverseUtill(Queue *queue, int k)
    {
        if (k == 0)
        {
            return;
        }

        int data = queue->Dequeue();
        ReverseUtill(queue, --k);
        return queue->Enqueue(data);
    }

    static void Reverse(Queue *queue, int k)
    {
        ReverseUtill(queue, k);

        int size = queue->Size();

        while (size - k > 0)
        {
            int data = queue->Dequeue();
            queue->Enqueue(data);
            size--;
        }
    }
};
