#include <iostream>
#include "queue.cpp"
#include "reverse_k_elements.cpp"

int main()
{
    Queue* queue = new Queue();

    queue->Enqueue(1);
    queue->Enqueue(2);
    queue->Enqueue(3);
    queue->Enqueue(4);
    queue->Enqueue(5);

    queue->Display();

    std::cout << queue->Dequeue() << std::endl;
    std::cout << "................................\n";

    std::cout << queue->Dequeue() << std::endl;
    std::cout << "................................\n";

    queue->Display();

    Node* node = queue->Find(5);
    node ? std::cout <<"found " << node->data << std::endl : std::cout << "not found" << std::endl;

    std::cout << "................................\n";

    Node* node2 = queue->Find(51);
    node2 ? std::cout <<"found " << node2->data << std::endl : std::cout << "not found" << std::endl;

    std::cout << "................................\n";
    std::cout << queue->Size() << std::endl;

    /* Given an integer k and a queue of integers, The task is to reverse the order of the first k elements 
    of the queue, leaving the other elements in the same relative order.*/

    ReverseKElements::Reverse(queue, 3);
    queue->Display();
}

//compile: g++ *.cpp -o main  
//run: ./main
