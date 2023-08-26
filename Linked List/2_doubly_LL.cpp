#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for node with data"<<val<<endl;
    }
};

void print(Node *head)
{
    Node *temp = head;
    

    while (temp != NULL)
    {
        /* code */
        // temp ke data ko age badho or temp ke next ko print karavo
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
};
//gives length og ll
int getLength(Node *head)
{
    int len=0;
    Node *temp = head;

    while (temp != NULL)
    {
        /* code */
        // temp ke data ko age badho or temp ke next ko print karavo
        len++;
        temp = temp->next;
    }
    return len;
};

void insertAtHead(Node* &head,int d){

    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
};

void insertAtTail(Node* &tail,int d){

    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}


void insertAtPosition(Node* &tail,Node* &head,int position,int d){

    if (position==1)
    {
        insertAtHead(head,d);
        return;
    }

    Node* temp=head;
    int cnt=1;


    while (cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToinsert=new Node(d);
    nodeToinsert->next=temp->next;
    temp->next->prev=nodeToinsert;
    temp->next=nodeToinsert;
    nodeToinsert->prev=temp;
}

    void deleteNode(int position,Node* &head){
        if (position==1)
        {
            /* code */
            Node* temp=head;
            temp->next->prev=NULL;
            head=temp->next;
            temp->next=NULL;
            delete temp;
        }
        else
        {
            Node* curr=head;
            Node* prev=NULL;

            int cnt=1;
            while (cnt<position)
            {
                /* code */
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

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail=node1;
    print(head);
    // cout<<getLength(head)<<endl;

    insertAtHead(head,11);
    print(head);

    insertAtHead(head,31);
    print(head);

    insertAtTail(tail,43);
    print(head);

    insertAtPosition(tail,head,2,143);
    print(head);

     insertAtPosition(tail,head,1,51);
    print(head);

deleteNode(3,head);
print(head);
cout<<"head:"<<head->data<<endl;
cout<<"tail:"<<tail->data<<endl;


    return 0;
};