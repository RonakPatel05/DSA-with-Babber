#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constrture
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node{
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is delete" << value << endl;
    }
};

void insertathead(Node *&head, int d)
{
    // new node create
    //NOde *temp=new node(d)     temo->next=head;    head=temp
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtail(Node *&tail, int d)
{
    // Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

// travesere
void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        /* code */
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    if (position == 1)
    {
        insertathead(head, d);
        return;
    }

    if (temp->next == Null)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        /* code */
        temp = temp->next;
        cnt++;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head)
{

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free from start node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node prev = NULL;

        int cnt = 1;
        while (cnt <= position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = current->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    // create new node
    Node *node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertathead(head, 12);
    print(head);

    insertathead(head, 15);
    print(head);

    insertAtTail(tail, 16);
    print(head);

    insertAtPosition(tail, head, 4, 22);
    print(head);

    deleteNode(1, head);
    print(head);

    return 0;
}