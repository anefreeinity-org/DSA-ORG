#include <iostream>
#include "binary_max_heap.cpp"
#include "binary_min_heap.cpp"

int main()
{
    BinaryMaxHeapMin heap;
    heap.Insert(0);
    heap.Insert(1);
    heap.Insert(8);
    heap.Insert(4);
    heap.Insert(19);
    heap.Insert(4);
    heap.Insert(6);

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
