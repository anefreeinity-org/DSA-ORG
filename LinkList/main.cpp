#include"singleLinklist.cpp"

int main(){
    SingleLinkList* linklist=new SingleLinkList();

    linklist->Insert(80);
    linklist->Insert(40);
    linklist->Insert(9);
    linklist->Insert(9);
    linklist->Insert(9);
    

    
    // std::cout<<linklist->Delete()<<std::endl<<std::endl;
    // std::cout<<linklist->Delete()<<std::endl<<std::endl;
    // std::cout<<linklist->Delete()<<std::endl<<std::endl;
    // std::cout<<linklist->Delete()<<std::endl<<std::endl;
    // std::cout<<linklist->Delete()<<std::endl<<std::endl;
    // std::cout<<linklist->Delete()<<std::endl<<std::endl;
    // linklist->Delete();
    // linklist->Delete();

    linklist->Display();
    
    std::cout<<"\n"<<linklist->length;
}