/*
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.
Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10
 Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90
*/
// T=O(n log n) , S=O(1)
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

void mid(Node *head, Node **a, Node **b)
{
    Node *slow = head, *fast = head->next;
    if (fast == NULL)
        return;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *a = head;
    *b = slow->next;
    slow->next = NULL;
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

Node *merge(Node *head1, Node *head2)
{
    Node *head = NULL, *tail = NULL, *h1 = head1, *h2 = head2;

    if (head == NULL)
    {
        if (h1->data <= h2->data)
        {
            head = h1;
            tail = h1;
            h1 = h1->next;
        }
        else
        {
            head = h2;
            tail = h2;
            h2 = h2->next;
        }
    }

    while (h1 != NULL and h2 != NULL)
    {
        if (h1->data <= h2->data)
        {
            tail->next = h1;
            tail = h1;
            h1 = h1->next;
        }
        else
        {
            tail->next = h2;
            tail = h2;
            h2 = h2->next;
        }
    }

    if (h1 != NULL)
        tail->next = h1;

    if (h2 != NULL)
        tail->next = h2;

    return head;
}

Node *mergeSort(Node *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    // 1. find the midpoint and divide list into 2 halves
    Node *a = NULL, *b = NULL;
    mid(head, &a, &b);

    // 2. Call mergeSort on 2 halves
    Node *left = mergeSort(a);
    Node *right = mergeSort(b);

    // 3. Merge the 2 sorted halves
    return merge(left, right);
}

int main(int argc, char const *argv[])
{
    int i, t;
    cin >> t;
    while (t--)
    {
        Node *head = takeInput();
        head = mergeSort(head);
        print(head);
    }
    return 0;
}