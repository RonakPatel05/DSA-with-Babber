#include <iostream>
#include<map>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int d)
    {

        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node wirh data" << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list
        Node *curr = tail;

        while (curr->data != element)
        {
            /* code */
            curr = curr->next;
        }

        // element found
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    Node *temp = tail;
    // empty linked list
    if (tail == NULL)
    {
        /* code */
        cout << "list is empty" << endl;
        return;
    }

    do
    {
        /* code */
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        /* code */
        cout << "list is empty,check again" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        // 1 node linked list
        if (curr == prev)
        {
            tail = NULL;
        }
        // 2 node linked list

        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

// circular list che ke nathi te check karva mate

bool iscircularlist(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}


//loop kese nikalna he ll ke andar se
bool detectloop(Node* head){
    if(head == NULL){
        return false;

        map<Node*,bool>visited;

        Node* temp =head;

        while (temp != NULL)
        {
            if(visited[temp]==true){
                return true;
            }

            visited[temp]=true;
            temp=temp->next;
        }

        return false;
        
    }
}

int main()
{
    Node *tail = NULL;
    // empty list ma insert
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    if (iscircularlist(tail))
    {
        cout << "linked list is circular in nature" << endl;
    }
    else
    {
        cout << "linked list is not circular" << endl;
    }
    return 0;
}