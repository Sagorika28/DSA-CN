// Reverse given LL recursively
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverse(Node *head)
{
    // base case
    if (head == NULL or head->next == NULL)
        return head;

    // rec call - reverse the rest of the LL
    Node *headNxt = reverse(head->next);

    // small calc to join the rec half to the head
    Node *temp = headNxt;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head;
    head->next = NULL;
    return headNxt;
}

int main(int argc, char const *argv[])
{
    Node *head = takeInput();
    head = reverse(head);
    print(head);
    return 0;
}