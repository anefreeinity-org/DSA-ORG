#include <iostream>

class Node
{
public:
    char data;
    Node *next;

    Node(char data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack
{
public:
    Node *top;
    int size;

    Stack()
    {
        top = nullptr;
        size = 0;
    }

    void Push(char data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;

        size++;
    }

    char Pop()
    {
        char retval = '\0';
        if (!top)
        {
            std::cout << "Stack is empty" << std::endl;
        }
        else
        {
            Node *temp = top;
            retval = temp->data;

            top = top->next;
            delete (temp);
        }

        size--;
        return retval;
    }

    int Size()
    {
        return size;
    }

    Node *Find(char data)
    {
        Node *temp = top;

        while (temp)
        {
            if (temp->data == data)
                return temp;
            temp = temp->next;
        }

        return nullptr;
    }

    void Display()
    {
        Node *temp = top;

        while (temp)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
        std::cout << "................................\n";
    }
};
