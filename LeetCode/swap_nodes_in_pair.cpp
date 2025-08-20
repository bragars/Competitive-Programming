class Solution
{
public:
  ListNode *swapPairs(ListNode *head)
  {
    if (!head || head->next == nullptr)
      return head;

    ListNode *cur = head;
    ListNode *prev = nullptr;
    ListNode *next = (cur != nullptr) ? cur->next : nullptr;
    ListNode *new_head = next;

    while (cur && next)
    {
      cur->next = next->next;
      next->next = cur;

      if (prev)
        prev->next = next;
      prev = cur;
      cur = cur->next;

      if (cur)
        next = cur->next;
    }

    return new_head;
  }
};
