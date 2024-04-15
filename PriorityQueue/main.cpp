#include <iostream>
#include "./priority_queue.cpp"

int main()
{
    PriorityQueue pq;

    pq.Enqueue(12, 2);
    pq.Enqueue(13, 1);
    pq.Enqueue(14, 3);
    pq.Enqueue(15, 0);
    pq.Enqueue(16, 1);
    pq.Enqueue(110, 3);
    pq.Enqueue(113, 3);

    std::cout << pq.Dequeue() << std::endl;
    std::cout << pq.Dequeue() << std::endl;
    std::cout << pq.Dequeue() << std::endl;
    std::cout << pq.Dequeue() << std::endl;
    std::cout << pq.Dequeue() << std::endl;
    std::cout << pq.Dequeue() << std::endl;
    std::cout << pq.Dequeue() << std::endl;
    return 0;
}

// g++ *.cpp -o main -std=c++11