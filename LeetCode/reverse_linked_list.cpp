#include <iostream>

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
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    ListNode* aux = new ListNode();
    aux->next = head;

    ListNode* prev_left  = aux;

    for (int i = 0; i < left; i++)
    {
      if(prev_left == nullptr) {
        delete aux;
        return head;
      }
      prev_left = prev_left->next;
    }

    for (int j = left; j <= right; j++)
    {
      cout
    }
    

  }
};

int main()
{
  Solution solution = Solution();
  ListNode *ln1 = new ListNode(1);
  ListNode *ln2 = new ListNode(2);
  ListNode *ln3 = new ListNode(3);
  ListNode *ln4 = new ListNode(4);
  ListNode *ln5 = new ListNode(5);

  ln1->next = ln2;
  ln2->next = ln3;
  ln3->next = ln4;
  ln4->next = ln5;

  ListNode *head = ln1;
  int left = 2;
  int right = 4;

  while (head != nullptr)
  {
    std::cout << "before->val: " << head->val << std::endl;
    head = head->next;
  }

  head = ln1;
  head = solution.reverseBetween(head, left, right);
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
