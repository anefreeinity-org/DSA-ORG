#pragma once
#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = nullptr;
    }

    void Insert(int data)
    {
        root = Insert(root, data);
    }

    void Preorder()
    {
        if (root)
            Preorder(root);
        std::cout << "----------------------\n";
    }

    void Delete(int data)
    {
        root = Delete(root, data);
    }

private:
    Node *Insert(Node *node, int data)
    {
        if (!node)
            node = new Node(data);
        else if (node->data > data)
            node->left = Insert(node->left, data);
        else if (node->data < data)
            node->right = Insert(node->right, data);

        return node;
    }

    Node *FindMinNode(Node *node)
    {
        while (node->left)
        {
            node = node->left;
        }

        return node;
    }

    Node *Delete(Node *node, int data)
    {
        if (!node)
            return node;

        if (node->data > data)
            node->left = Delete(node->left, data);
        else if (node->data < data)
            node->right = Delete(node->right, data);
        else
        {
            if (!node->left && !node->right)
            {
                delete (node);
                return nullptr;
            }
            else if (node->right)
            {
                Node *temp = node->right;
                delete (node);
                return temp;
            }
            else if (node->left)
            {
                Node *temp = node->left;
                delete (node);
                return temp;
            }
            else
            {
                Node *temp = FindMinNode(node->right);
                node->data = temp->data;
                node->right = Delete(node->right, node->data);
            }
        }

        return node;
    }

    void Preorder(Node *node)
    {
        if (!node)
            return;
        std::cout << node->data << std::endl;
        Preorder(node->left);
        Preorder(node->right);
    }
};
