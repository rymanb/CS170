#include <iostream> // cout, endl
#include "List.h"

namespace CS170
{
    namespace ListLab
    {
        namespace 
        {
        /*!******************************************************************
          Construct a node with given integer value

          \param value
          integer

          \return
          pointer to newly constructed node
         ********************************************************************/
            struct Node* MakeNode(int value)
            {
                struct Node *pNode = new Node; // Allocate memory for the node
                pNode->number = value;         // Set data field (number)
                pNode->next = 0;               // Set next (no next yet)

                return pNode;
            }
        }

        void AddToEnd(Node **pList, int value)
        {
            struct Node* newNode = MakeNode(value);
            newNode->next = NULL;
            if (*pList == NULL)
            {
                *pList = newNode;
            }
            else
            {
                struct Node * pNode = *pList;

                while (pNode->next != NULL)
                {
                pNode = pNode->next;
                }
                pNode->next = newNode;
            }
        }

        void AddToFront(Node **pList, int value)
        {
            struct Node* newNode = MakeNode(value);
            newNode->next = *pList;

            *pList = newNode;
        }

        Node *FindItem(Node *list, int value)
        {
            struct Node * pNode = list;

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

        void FreeList(Node *pList)
        {
            struct Node * pNode = pList;

            while (pNode != NULL)
            {
                struct Node * temp = pNode->next;
                delete pNode;
                pNode = temp;
            }
        }

        void Insert(Node **pList, int value, int position)
        {
            struct Node * pNode = *pList;
            struct Node * pNodeBefore = NULL;
            int i = 0;
            if (position == 0)
            {
                AddToFront(pList, value);
            }
            else if (position == Count(pNode))
            {
                AddToEnd(pList, value);
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

        /*!******************************************************************
          Print the list.

          \param list
          The list to count.

          \return
          void
         ********************************************************************/
        void PrintList(struct Node *list)
        {
            while (list)
            {
                std::cout << list->number << "   ";
                list = list->next;
            }
            std::cout << std::endl;
        }

        /*!******************************************************************
          Get the number of nodes in the list.

          \param list
          The list to count.

          \return
          The number of nodes in the list.
         ********************************************************************/
        int Count(struct Node *list)
        {
            int count = 0; // Number of nodes in the list

            while (list)
            {
                count++;
                list = list->next;
            }

            return count;
        }

        // ... your code 

    } // namespace ListLab
} // namespace CS170
