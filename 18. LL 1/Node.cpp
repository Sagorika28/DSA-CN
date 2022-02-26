// Node of an LL 

#include <iostream>
class Node
{
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
};