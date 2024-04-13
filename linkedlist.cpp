#include<iostream>
using namespace std;
class node{
    public:
  int data;
  node *next;
    node(){
    int data=0;   //default constructor
    node* next =NULL;
    }
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    void print(node* &head){
        node* temp=head;
        while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
        }
        cout<<endl;
    }
    void insertAtFront(node* &head,int data){
       if(head==NULL){
        node* newnode=new node(data);
        head=newnode;
       }
       else{
        node* temp=head;
        node* newnode=new node(data);
        newnode->next=head;
        head=newnode;
       }
    }
    int getlen(node* &head){
        int len=0;
        node* temp= head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }
    void insertAtEnd(node* &head,int data){
        if(head==NULL){
            node* newnode=new node(data);
            head=newnode;
        }
        else{
        node* newnode=new node(data);
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        }
    }

void insertAtPos(int data,node* &head,int potion){
    node* newnode=new node(data);
    int pos=potion;
    node* prev=NULL;
    node* curr=head;
    while(pos!=1){
        pos--;
        prev=curr;
        curr=curr->next;
    }
prev->next=newnode;
newnode->next=curr;
}
node* reverse_LL(node* &head){
    node*prev=NULL;
    node* curr=head;
    while(curr!=NULL){
    node* nextnode=curr->next;
        curr->next = prev;
        prev=curr;
        curr=nextnode;
    }
    head = prev;
    return head;
}
void midterm_ll(node* head,int len){
if(len%2!=0){ 
    len=(len/2)+1;
    cout<<"len="<<len<<endl;
}else{
    len=len/2;
    cout<<"len="<<len<<endl;
}
node* temp=head;
int i=0;
   while(i<len){
        temp=temp->next;
        i++;
   }
   cout<<temp->data;

}

void deleteAtfront(node* &head){
    if(head==NULL) return;
    else{
        node* temp=head;
        head=head->next;
        free(temp);
    }
}
void deleteAtback(node* &head){
    if(head==NULL) return;
        else{
            node*temp=head;
            node*prev=NULL;
            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
            }
           prev->next=NULL;
           free(temp);
        }
}
void deleteAtpos(node* &head,int pos,int len){
    node* temp=head;
    node*prev=  NULL; 
    if(pos==1) deleteAtfront(head);
    else if(pos==len) deleteAtback(head);
    else{
while(pos>0){
    prev=temp;
temp=temp->next;
pos--;
}
prev->next=temp->next;
temp->next=NULL;
free(temp);
}
}
void delete_the_middle_one(node* &head){



    
}
};

int main(){
// node* n1=new node(10);
int data;
cin>>data;
node*n1=new node(data);
// node* n2=new node(23);
// node* n3=new node(66);
// node* n4=new node(39);
node* head=n1;
// n1->next=n2;
// n2->next=n3;
// n3->next=n4;
// n1->print();
n1->insertAtEnd(head,45);
// int l=n1->getlen(head);
cout<<"printing after insert at end"<<endl;
n1->print(head);
n1->insertAtFront(head,46);
cout<<"printing after insert at front"<<endl;
n1->print(head);
cout<<"printing after insert at pos"<<endl;
n1->insertAtPos(38,head,3);
n1->insertAtFront(head,90);
n1->print(head);
cout<<"printing after reverse"<<endl;
int l=n1->getlen(head);
n1->reverse_LL(head);
n1->print(head);
cout<<"finding mid term"<<endl;
n1->midterm_ll(head,l);
cout<<"deleting from back"<<endl;
n1->deleteAtback(head);
n1->print(head);
cout<<"deleting from front"<<endl;
n1->deleteAtfront(head);
n1->print(head);
cout<<"delete"<<endl;
n1->deleteAtpos(head,2,l);
n1->print(head);
cout<<"delete"<<endl;
n1->deleteAtpos(head,1,l);
n1->print(head);
cout<<"delete"<<endl;
n1->deleteAtpos(head,0,l);
n1->print(head);    
    return 0;
}