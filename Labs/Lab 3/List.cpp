#include <iostream> // ostream
#include "List.h"

/*******************************************************************/
/*******************************************************************/
List::List(void)
{
    head_ = 0;
}

List::~List(void)
{
    struct Node * pNode = head_;

    while (pNode != NULL)
    {
        struct Node * temp = pNode->next;
        delete pNode;
        pNode = temp;
    }
}

Node* List::MakeNode(int value)
{
    // The Node constructor sets the value, 
    // and sets next to 0.
    return new Node(value);
}

void List::Display() 
{
    Node *list = head_;

    while (list) {
        std::cout << list->number << "   ";
        list = list->next;
    }
}

int List::Count(void)
{
    int count = 0;
    Node *list = head_;

    while (list) {
        count++;
        list = list->next;
    }
    return count;
}

        // Adds a node to the end of the list
void List::AddToEnd( int value )
{
    struct Node* newNode = MakeNode(value);
    newNode->next = NULL;
    if (head_ == NULL)
    {
        head_ = newNode;
    }
    else
    {
        struct Node * pNode = head_;

        while (pNode->next != NULL)
        {
            pNode = pNode->next;
        }
        pNode->next = newNode;
    }
}

        // Adds a node to the front of the list
void List::AddToFront( int value )
{
    struct Node* newNode = MakeNode(value);
    newNode->next = head_;

    head_ = newNode;
}


        // Finds an item and returns the node that contains it
        // Only finds the first occurrence of value
Node *List::FindItem( int value )
{
    struct Node * pNode = head_;

    while (pNode != NULL)
    {
        if (pNode->number == value)
        {
            return pNode;
        }
        pNode = pNode->next;
    }
    return NULL;
}

        // Inserts a new node at the specified position
void List::Insert( int value, int position )
{
    struct Node * pNode = head_;
    struct Node * pNodeBefore = NULL;
    int i = 0;
    if (position == 0)
    {
        AddToFront(value);
    }
    else if (position == Count())
    {
        AddToEnd(value);
    }
    else
    {   
        while (pNode != NULL)
        {
            if (i != position)
            {
                pNodeBefore = pNode;
                pNode = pNode->next;
            }
            else
            {
                struct Node* newNode = MakeNode(value);  
                pNodeBefore->next = newNode;
                newNode->next = pNode;
            }

            i++;
        }
    }
}

        // Deletes a node with the specified value (first occurrence)
void List::Delete( int value )
{
    struct Node * pNode = head_;
    struct Node * pNodeBefore = NULL;
    if (pNode)
    {
        if (pNode->number == value)
        {
            struct Node* next = head_->next;
            delete head_;
            head_ = next;
        }
        else
        {   
            while (pNode != NULL)
            {
                if (pNode->number != value)
                {
                    pNodeBefore = pNode;
                    pNode = pNode->next;
                }
                else
                { 
                    pNodeBefore->next = pNode->next;
                    delete pNode;
                    break;
                }
            }
        }
    }
}

        // Concatenates two lists
void List::Concat( List const& Source )
{
    const Node* pNode = Source.head_;

    while (pNode)
    {
        AddToEnd(pNode->number);
        pNode = pNode->next;
    }
}

        // Deletes all of the values in the list that are it Items
void List::Delete( List const& Items )
{
    const Node* pNode = Items.head_;

    while (pNode)
    {
        while (FindItem(pNode->number))
        {
            Delete(pNode->number);
        }
        pNode = pNode->next;
    }
}

        // Inserts a new node in the correct position (sorted small to large)
void List::Insert( int value )
{
    struct Node* pNode = head_;
    struct Node* pNodeBefore = NULL;

    if (pNode == NULL)
    {
        AddToFront(value);
    }
    else if (pNode->next == NULL)
    {
           AddToEnd(value);
    }
    else
    {
        pNodeBefore = pNode;
        pNode = pNode;
        int i = 0;
        while (pNode && pNode->number <= value && pNodeBefore->number < value)
        {
            pNodeBefore = pNode;
            pNode = pNode->next;
            i++;
        }
        Insert(value, i);
    }
}


