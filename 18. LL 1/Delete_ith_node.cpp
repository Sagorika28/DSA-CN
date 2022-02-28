// Delete the node at ith index in LL 
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
}

Node* del(Node* head, int i)
{
    if(head == NULL or i < 0)
        return head;
        
    Node *temp = head;
    if(i == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;
    while(temp != NULL and count < i-1)
    {
        temp = temp->next;
        count++;
    }

    if(temp != NULL and temp->next != NULL)
    {
        Node *ptr = temp->next;
        temp->next = temp->next->next;
        delete ptr;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    int i;
    Node* head = takeInput();        
    cin >> i;
    head = del(head, i);
    print(head);
    return 0;
}