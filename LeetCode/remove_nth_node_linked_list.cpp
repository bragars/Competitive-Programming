#include <iostream>
#include <vector>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *aux = new ListNode();
    aux->next = head;

    ListNode *tail = aux;
    ListNode *slow = aux;

    for (int i = 0; i <= n; ++i)
    {
      if (tail == nullptr) // there is no sufficient nodes
      {
        delete aux;
        return nullptr;
      }
      tail = tail->next;
    }

    while (tail != nullptr)
    {
      tail = tail->next;
      slow = slow->next;
    }

    ListNode *to_delete = slow->next;
    slow->next = slow->next->next;
    delete to_delete;

    ListNode* new_head = aux->next;

    delete aux;
    return new_head;
  }
};

int main()
{
  Solution solution = Solution();
  ListNode *ln1 = new ListNode(1);
  // ListNode *ln2 = new ListNode(2);
  // ListNode *ln3 = new ListNode(3);
  // ListNode *ln4 = new ListNode(4);
  // ListNode *ln5 = new ListNode(5);
  // ListNode *ln6 = new ListNode(6);
  // ListNode *ln7 = new ListNode(7);
  // ListNode *ln8 = new ListNode(8);
  // ListNode *ln9 = new ListNode(9);
  // ListNode *ln10 = new ListNode(10);

  // ln1->next = ln2;
  // ln2->next = ln3;
  // ln3->next = ln4;
  // ln4->next = ln5;
  // ln5->next = ln6;
  // ln6->next = ln7;
  // ln7->next = ln8;
  // ln8->next = ln9;
  // ln9->next = ln10;

  ListNode *head = ln1;
  // int n = 1;
  int n = 1;

  while (head != nullptr)
  {
    std::cout << "before->val: " << head->val << std::endl;
    head = head->next;
  }

  head = ln1;
  head = solution.removeNthFromEnd(head, n);
  ListNode *current = head;

  if (current == nullptr)
  {
    std::cout << "[]" << std::endl;
  }

  while (current != nullptr)
  {
    std::cout << "current->val: " << current->val << std::endl;
    current = current->next;
  }

  // Memory delete
  while (head != nullptr)
  {
    ListNode *to_delete = head;
    head = head->next;
    delete to_delete;
  }

  return 0;
}
