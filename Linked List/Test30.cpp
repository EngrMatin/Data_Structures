#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int val;
   Node *next;

   Node(int data)
   {
      val = data;
      next = NULL;
   }
};

Node *make_list(vector<int> v)
{
   Node *head = new Node(v[0]);
   for(int i = 1; i<v.size(); i++)
    {
      Node *ptr = head;
      while(ptr->next != NULL)
      {
         ptr = ptr->next;
      }
      ptr->next = new Node(v[i]);
   }
   return head;
}

void print_list(Node *head)
{
   Node *ptr = head;
   cout << "[";
   while(ptr)
   {
      cout << ptr->val << ", ";
      ptr = ptr->next;
   }
   cout << "]" << endl;
}
class Solution
{
   public:
   Node* removeZeroSumSublists(Node* head)
   {
      Node* temp = new Node(0);
      temp->next = head;

      unordered_map <int, Node*> m;

      m[0] = temp;
      int sum = 0;
      while(head)
      {
         sum += head->val;
         m[sum] = head;
         head = head->next;
      }
      head = temp;
      sum = 0;
      while(head)
      {
         sum += head->val;
         Node* temp = m[sum];
         if(temp != head)
         {
            head->next = temp->next;
         }
         head = head->next;
      }
      return temp->next;
   }
};

main(){
   vector<int> v1 = {1,2,-3,3,1};
   Node *head = make_list(v1);
   Solution ob;
   print_list(ob.removeZeroSumSublists(head));
}
