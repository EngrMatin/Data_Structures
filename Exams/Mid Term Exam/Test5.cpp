#include <bits/stdc++.h>
using namespace std;
struct Node {
   int data;
   Node *next;
};
void insertNode(Node ** head_ref, int new_data) {
   Node* new_node = new Node();
   new_node->data = new_data;
   new_node->next = (*head_ref);
   *head_ref = new_node;
}
void printLinkedList(Node *head) {
   Node *temp = head;
   while (temp != NULL) {
      cout<< temp->data << " -> ";
      temp = temp->next;
   }
   cout << "Null" << endl;
}
void deleteNNodesAfterMNodes(Node *head, int M, int N) {
   Node *current = head, *temp;
   int count;
   while (current) {
      // skip M nodes
      for (count = 1; count < M && current!= NULL; count++) {
         current = current->next;
      }
      // end of the linked list
      if (current == NULL) {
         return;
      }
      // deleting N nodes after M nodes
      temp = current->next;
      for (count = 1; count <= N && temp != NULL; count++) {
         Node *deletingNode = temp;
         temp = temp->next;
         free(deletingNode);
      }
      current->next = temp;
      current = temp;
   }
}
int main() {
   Node* head = NULL;
   int M = 2, N = 1;
   insertNode(&head, 1);
   insertNode(&head, 2);
   insertNode(&head, 3);
   insertNode(&head, 4);
   insertNode(&head, 5);
   insertNode(&head, 6);
   insertNode(&head, 7);
   insertNode(&head, 8);
   insertNode(&head, 9);
   cout << "Linked list before deletion: ";
   printLinkedList(head);
   deleteNNodesAfterMNodes(head, M, N);
   cout << "Linked list after deletion: ";
   printLinkedList(head);
   return 0;
}
