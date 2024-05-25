#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data,Node* next=nullptr){
     this->data=data;
     this->next=next;
    }
};

class Linkedlist{
    int size=0;
    Node* head;
    Node* tail;
    // Node* trav=
public:
    Linkedlist(){
        head=tail=NULL;
        size=0;
    }

    void insert_i(int index,int val){
        if(index>size || index<0) throw out_of_range("Index out of bound enter valid index");
        Node* temp=new Node(val);
        Node* itr=head;
        for(int i=1;i<index;i++){
            itr=itr->next;
        }
        temp->next=itr->next;
        itr->next=temp;
        size+=1;
    }

    void remove_i(int index){
        if(index>size || index<0) throw out_of_range("Index out of bound enter valid index");
        if(index==0){
            headremove();
            return;
        }
        Node* itr=head;
        for(int i=1;i<index;i++){
            itr=itr->next;
        }
        Node* itr2=(itr->next)->next;
        itr->next=NULL;
        itr->next=itr2;
        size-=1;
    }


    void insert(int val){
        Node* temp=new Node(val);
        if(this->size==0){
            head=tail=temp;
            size+=1;
        }
        else{
            tail->next=temp;
            tail=temp;
            size+=1;
        }
    }
    void headinsert(int val){
        Node* temp=new Node(val);
        if(this->size==0) {
            insert(val);
            size+=1;
        }
        else{
          temp->next=head;
          head=temp;  
          size+=1;
        }
    }
    Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    Node* temp = head;
    int length = 1;
    while (temp->next) {
        temp = temp->next;
        length += 1;
    }

    temp->next = head;

    k = k % length;
    if (k == 0) {
        temp->next = NULL; 
        return head;
    }

    int steps_to_new_head = length - k;
    temp = head;
    for (int i = 0; i < steps_to_new_head - 1; ++i) {
        temp = temp->next;
    }
    Node* new_head = temp->next;
    temp->next = NULL;

    return new_head;
}
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    int len(){
        int s=0;
        Node* temp=head;
        while(temp!=NULL){
            s+=1;
            temp=temp->next;
        }
        return s;
    }

    void headremove(){
        if(size<1) throw out_of_range("No element in linkedlist");
        Node* temp=head->next;
        head=NULL;
        head=temp;
        size-=1;
    }
    void pop(){
        if(size<1) throw out_of_range("No element in linkedlist");
        
        if(size==1) tail=NULL;
        else{
            Node* temp=head;
            for(int i=1;i<size-1;i++){
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
            size-=1;
        }
    }




};

int main(){
    Linkedlist a;
    a.insert(10);
    a.insert(50);
    a.insert_i(1,45);
    a.insert_i(3,55);
    a.headinsert(20);
    a.insert_i(a.len(),30);
    a.headremove();
    a.pop();
    a.remove_i(2);
    a.remove_i(a.len()-1);
    a.remove_i(0);

    a.display();
    cout<<a.len();
    
    return 0;
}

