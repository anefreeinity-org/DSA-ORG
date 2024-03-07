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
    Node* head;
    public:
        SingleLinkList(){
            head=nullptr;
        }

        void Insert(int data){
           if(!head){
            head=new Node(data);
            return;
           }
           if(!head->next){
            head->next=new Node(data);
            return;
           }
            Insert(data);
        }

        // void Display(){
        //     while(head->next){
        //         std::cout<<head->data<<std::endl;
        //         head=head->next;
        //     }
        // }
};