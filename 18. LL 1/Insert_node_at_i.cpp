// Insert a node at ith index in LL 
// T=O(n) , S=O(1)
#include <iostream>
#include "Node.cpp"
using namespace std;
Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }

        cin >> data;
    }
    return head;
}

void print(Node* head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insert(Node* head, int data, int i)
{
    Node *newNode = new Node(data);
    if(i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    int count = 0;
    Node *temp = head;
    while(temp != NULL and count < i-1)
    {
        temp = temp->next;
        count++;
    }

    if(temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    int i, data;
    Node* head = takeInput();        
    cin >> data >> i;
    head = insert(head, data, i);
    print(head);
    return 0;
}