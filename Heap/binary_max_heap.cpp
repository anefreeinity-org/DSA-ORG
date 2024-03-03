#include <vector>

class BinaryMaxHeap
{
public:
    std::vector<int> heapArr;
    int length;

    BinaryMaxHeap()
    {
        length = 0;
    }

private:
    int FindLeftChildIndex(int parentIndx)
    {
        return (2 * parentIndx + 1);
    }

    int FindRightChildIndex(int parentIndx)
    {
        return (2 * parentIndx + 2);
    }

    int FindParentIndex(int childIndx)
    {
        return (childIndx - 1) / 2;
    }

    void Swap(int first, int second)
    {
        int temp = heapArr[first];
        heapArr[first] = heapArr[second];
        heapArr[second] = temp;
    }

    void MaintainHeigherArchyAfterInsertation(int index)
    {
        if (index == 0)
        {
            return;
        }

        int currentParentIndex = FindParentIndex(index);

        if (heapArr[currentParentIndex] < heapArr[index])
        {
            Swap(index, currentParentIndex);
            MaintainHeigherArchyAfterInsertation(currentParentIndex);
        }
    }

    void MaintainHeigherArchyAfterDeletion(int index)
    {
        if (index >= length - 1)
        {
            return;
        }

        int leftChildIndex = FindLeftChildIndex(index);
        int rightChildIndex = FindRightChildIndex(index);

        if (heapArr[index] < heapArr[leftChildIndex] && heapArr[leftChildIndex] > heapArr[rightChildIndex])
        {
            Swap(index, leftChildIndex);
            MaintainHeigherArchyAfterDeletion(leftChildIndex);
        }
        else if (heapArr[index] < heapArr[leftChildIndex] && heapArr[leftChildIndex] < heapArr[rightChildIndex])
        {
            Swap(index, rightChildIndex);
            MaintainHeigherArchyAfterDeletion(rightChildIndex);
        }
    }

public:
    void Insert(int data)
    {
        heapArr.push_back(data);
        length++;
        MaintainHeigherArchyAfterInsertation(length - 1);
    }

    int Delete()
    {
        if (length == 0)
        {
            return -1;
        }

        int temp = heapArr[0];
        Swap(0, length - 1);
        heapArr.pop_back();
        length--;
        MaintainHeigherArchyAfterDeletion(0);
        return temp;
    }

    int FindxMax()
    {
        if (length == 0)
        {
            return -1;
        }
        return heapArr[0];
    }
};
