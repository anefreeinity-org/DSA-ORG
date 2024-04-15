#include <vector>
#include "./node.cpp"

class MaxHeap
{
public:
    std::vector<Node *> heapArr;

    int length;

    MaxHeap()
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
        Node *temp = heapArr[first];
        heapArr[first] = heapArr[second];
        heapArr[second] = temp;
        return 1;
    }

    void MaintainHierArchyAfterInsertion(int index)
    {
        if (index == 0)
        {
            return;
        }

        int currentParentIndex = FindParentIndex(index);

        if (heapArr[currentParentIndex]->priority < heapArr[index]->priority)
        {
            Swap(index, currentParentIndex, false);
            MaintainHierArchyAfterInsertion(currentParentIndex);
        }
    }

    void MaintainHierArchyAfterDeletion(int index)
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
            if (heapArr[index]->priority < heapArr[leftChildIndex]->priority)
            {
                if (Swap(index, leftChildIndex))
                    MaintainHierArchyAfterDeletion(leftChildIndex);
            }
        }
        else
        {
            if (heapArr[index]->priority < heapArr[leftChildIndex]->priority && heapArr[leftChildIndex]->priority >= heapArr[rightChildIndex]->priority)
            {
                if (Swap(index, leftChildIndex))
                    MaintainHierArchyAfterDeletion(leftChildIndex);
            }
            else if (heapArr[index]->priority < heapArr[leftChildIndex]->priority && heapArr[leftChildIndex]->priority <= heapArr[rightChildIndex]->priority)
            {
                if (Swap(index, rightChildIndex))
                    MaintainHierArchyAfterDeletion(rightChildIndex);
            }
        }
    }

public:
    Node *Insert(int data, int priority)
    {
        Node *temp = new Node(data, priority);
        heapArr.push_back(temp);
        length++;
        MaintainHierArchyAfterInsertion(length - 1);
        return temp;
    }

    int Delete()
    {
        if (length == 0)
        {
            return -1;
        }

        Node *temp = heapArr[0];
        Swap(0, length - 1);
        heapArr.pop_back();
        length -= 1;
        MaintainHierArchyAfterDeletion(0);
        return temp->priority;
    }

    Node *GetTop()
    {
        if (length == 0)
        {
            return nullptr;
        }
        return heapArr[0];
    }
};
