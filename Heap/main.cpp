#include <iostream>
#include "binary_max_heap.cpp"

int main()
{
    BinaryMaxHeap heap;
    heap.Insert(8);
    heap.Insert(5);
    heap.Insert(4);
    heap.Insert(3);
    heap.Insert(4);
    heap.Insert(4);
    heap.Insert(3);
    heap.Insert(1);
    heap.Insert(10);

    std::cout << heap.Delete() << std::endl
              << std::endl;

    for (int data : heap.heapArr)
    {
        std::cout << data << std::endl;
    }
}
