#pragma once
#include <iostream>

class Node
{
public:
    int data;
    Node* next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class Queue
{
public:
    Node* head;
    Node* tail;

    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }

    void Enqueue(int data)
    {
        if(!head && !tail)
        {
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node* newNode = new Node(data);
            tail->next = newNode;
            tail = newNode;
        }
    }

    int Dequeue()
    {
        int retval = -1;

        if(!head && !tail)
        {
            std::cout << "empty queue" << std::endl;
        }
        else if(head == tail)
        {
            Node* temp = head;
            retval = temp->data;
            head = tail = nullptr;
            delete(temp);
        }
        else
        {
            Node* temp = head;
            retval = temp->data;
            head = head->next;
            delete(temp);
        }

        return retval;
    }

    Node* Find(int data)
    {
        Node* temp = head;

        while(temp)
        {
            if(temp->data == data)
                return temp;
            temp = temp->next;
        }

        return nullptr;
    }

    int Size()
    {
        Node* temp = head;
        int count = 0;

        while(temp)
        {
            temp = temp->next;
            count++;
        }

        return count;
    }

    void Display()
    {
        Node* temp = head;

        while(temp)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }

        std::cout << "................................\n";
    }
};
