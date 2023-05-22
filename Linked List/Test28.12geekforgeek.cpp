#include <bits/stdc++.h>
using namespace std;

// A Linked List Node
struct Node {
    int val;
    Node* next;

    // Constructor
    Node(int x)
        : val(x)
        , next(NULL)
    {
    }
};

// Function to create Node
Node* getNode(int data)
{
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->val = data;
    temp->next = NULL;
    return temp;
}

// Function to print the Linked List
void printList(Node* head)
{
    while (head->next) {
        cout << head->val << " -> ";
        head = head->next;
    }
    printf("%d", head->val);
}

                                      // Function that removes continuous nodes whose sum is K
Node* removeZeroSum(Node* head, int K)
{
    Node* temp = new Node(0);
    temp->next = head;                     // Append at the front of the given Linked List

    unordered_map<int, Node*> umap;        // Map to store the sum and reference of the Node

    umap[0] = temp;

    int sum = 0;
    while (head != NULL)                      // Traversing the Linked List
    {
        sum += head->val;

        if (umap.find(sum - K) != umap.end())        // If found value with (sum - K)
        {
            Node* prev = umap[sum - K];
            Node* start = prev;

            sum = sum - K;                // Update sum
            int aux = sum;

            while (prev != head)              // Traverse till current head
            {
                prev = prev->next;
                aux += prev->val;
                if (prev != head)
                {
                    umap.erase(aux);
                }
            }
            start->next = head->next;           // Update the start value to the next value of current head
        }

        else if (umap.find(sum) == umap.end())         // If (sum - K) value not found
        {
            umap[sum] = head;
        }

        head = head->next;
    }

    return temp->next;           // Return the value of updated head node
}

int main()
{
    Node* head;

                                     // Create Linked List
    head = getNode(1);
    head->next = getNode(2);
    head->next->next = getNode(-3);
    head->next->next->next = getNode(3);
    head->next->next->next->next = getNode(1);

                                       // Given sum K
    int K = 0;

                                     // Function call to get head node of the updated Linked List
    head = removeZeroSum(head, K);

                                      // Print the updated Linked List
    if (head != NULL)
        printList(head);
    return 0;
}
