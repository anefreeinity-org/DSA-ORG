#include <vector>
#include <iostream>

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
        int l_child = (2 * parentIndx + 1);
        if (l_child < length)
            return l_child;
        else
            return -1;
    }

    int FindRightChildIndex(int parentIndx)
    {
        int r_child = (2 * parentIndx + 2);
        if (r_child < length)
            return r_child;
        else
            return -1;
    }

    int FindParentIndex(int childIndx)
    {
        return (childIndx - 1) / 2;
    }

    int Swap(int first, int second, bool isDeleting = true)
    {
        if (isDeleting)
        {
            if (first > length - 1 || second > length - 1)
                return 0;
        }
        int temp = heapArr[first];
        heapArr[first] = heapArr[second];
        heapArr[second] = temp;
        return 1;
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
            Swap(index, currentParentIndex, false);
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

        if (leftChildIndex == -1 && rightChildIndex == -1)
        {
            return;
        }
        else if (rightChildIndex == -1)
        {
            if (heapArr[index] < heapArr[leftChildIndex])
            {
                if (Swap(index, leftChildIndex))
                    MaintainHeigherArchyAfterDeletion(leftChildIndex);
            }
        }
        else
        {
            if (heapArr[index] < heapArr[leftChildIndex] && heapArr[leftChildIndex] >= heapArr[rightChildIndex])
            {
                if (Swap(index, leftChildIndex))
                    MaintainHeigherArchyAfterDeletion(leftChildIndex);
            }
            else if (heapArr[index] < heapArr[leftChildIndex] && heapArr[leftChildIndex] <= heapArr[rightChildIndex])
            {
                if (Swap(index, rightChildIndex))
                    MaintainHeigherArchyAfterDeletion(rightChildIndex);
            }
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
        length -= 1;
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
