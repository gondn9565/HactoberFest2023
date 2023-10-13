#include<iostream>
using namespace std;
    class node{
        public:
        int val;
        node* prev;
        node* next;
        node(int data){
            val=data;
            prev=NULL;
            next=NULL;
        }
            node(){
                int val=this->val;
                if(next!=NULL){
                    delete next;
                    next=NULL;
                }

            }

    };
    void insertathead(node* &tail,node* &head,int val){
        //empty list
        if(head==NULL){
            node* temp=new node(val);
            head=temp;
            tail=temp;
        }else{
        node* temp=new node(val);
            temp->next=head;
            head->prev=temp;

        head=temp;
        }
    }
    void insertatend(node* &tail,node* &head,int val){
         if(tail==NULL){
            node* temp=new node(val);
            head=temp;
            tail=temp;
           // head=temp;
        }else{
        node* temp=new node(val);
        tail->next=temp;
        temp->prev=tail;
       tail=temp;
        }
    }
    void insertatpos(node* &tail,node* &head,int pos,int val){
        if(pos==1){
           insertathead(tail,head,val);
           return; 
        }
        node* temp=head;
        int cnt=1;
        while(cnt<pos-1){
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL){
            insertatend(tail,head,val);
            return;
        }
        node* nodetoinsert=new node(val);
        nodetoinsert->next=temp->next;
        temp->next->prev=nodetoinsert;
        temp->next=nodetoinsert;
        nodetoinsert->prev=temp;
    }
    
    void deletenode(node* &head,int pos){
        //Delete at head
        if(pos==1){
            node* temp=head;
           temp->next->prev=NULL;
            head=temp->next;
             temp->next=NULL;
            free(temp);
        //delete at middle
        }else{
            node* curr=head;
            node* prev=NULL;
            int cnt=1;
            while(cnt<=pos){
                prev=curr;
                curr=curr->next;
                cnt++;
            }
           curr->prev=NULL;
           prev->next=curr->next;
            curr->next=NULL;
            delete curr;
            
        }
    }
    void display(node* head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
           temp= temp->next;
        }cout<<endl;
    }
     int getlength(node* head){
        int len=0;
        node* temp=head;
        while(temp!=NULL){
            len++;
           temp= temp->next;
        }
        return len;
    }
int main(){
    node* node1=NULL;
    node* tail=NULL;
    display(node1);
    getlength(node1);
    insertathead(tail,node1,23);
    insertathead(tail,node1,30);
    insertathead(tail,node1,40);
    display(node1);
     deletenode(node1,1);
         display(node1);
return 0;
}
