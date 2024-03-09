#include <iostream>
#include "binary_max_heap.cpp"

int main()
{
    BinaryMaxHeap heap;
    heap.Insert(100);
    heap.Insert(90);
    heap.Insert(28);
    heap.Insert(40);
    heap.Insert(19);
    heap.Insert(40);
    heap.Insert(36);

    std::cout << heap.Delete() << std::endl
              << std::endl;

    std::cout << heap.Delete() << std::endl
              << std::endl;

    std::cout << heap.Delete() << std::endl
              << std::endl;

    std::cout << heap.Delete() << std::endl
              << std::endl;

    std::cout << heap.Delete() << std::endl
              << std::endl;

    std::cout << heap.Delete() << std::endl
              << std::endl;

    std::cout << heap.Delete() << std::endl
              << std::endl;

    std::cout << heap.Delete() << std::endl
              << std::endl;

    // std::cout << heap.Delete() << std::endl
    //           << std::endl;

    for (int data : heap.heapArr)
    {
        std::cout << data << std::endl;
    }
}
