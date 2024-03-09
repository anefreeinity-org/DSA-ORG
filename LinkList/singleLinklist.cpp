#include<iostream>
class Node{
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data=data;
        next=nullptr;
    }
};
class SingleLinkList{
    
    public:
        Node* head;
        int length;
        SingleLinkList(){
            head=nullptr;
            length=0;
        }

        void Insert(int data)
        {
           if(!head)
           {
            head=new Node(data);
            length++;
            return;
           }
           Node* temp = head; 
           while(temp->next)
           {
            temp=temp->next;
           }
           temp->next=new Node(data);
           length++;
        }

        // void Insert(int data)
        // {
        //    head=Insert(head,data);
        // }

        // Node* Insert(Node* node,int data)
        // {          
        //     if(!node)
        //     {
        //         node=new Node(data);
        //     }
        //     else
        //     {
        //         node->next=Insert(node->next,data);
        //     }
        //     return node;
        // }

        int Delete(){
            if(!head){
                return -1;
            }
            Node* temp=head;
            if(!temp->next){
                int data=temp->data;
                delete(temp->next);
                temp=nullptr;
                return data;
            }
            while(temp->next->next){
                temp=temp->next;
            }
            int data=temp->next->data;
            delete(temp->next->next);
            temp->next=nullptr;
            length--;
            return data;
        }

        void Display(){
            Node* temp = head; 
            if (head == NULL) { 
                std::cout << "List empty" << std::endl; 
                return; 
            } 
            while (temp != NULL) { 
                std::cout << temp->data << " "; 
                temp = temp->next; 
            } 
        }
};