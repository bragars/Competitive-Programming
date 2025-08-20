class Solution
{
public:
  int list_node_size(ListNode *head)
  {
    ListNode *current = head;
    int counter = 0;

    while (current)
    {
      counter++;
      current = current->next;
    }

    return counter;
  }

  ListNode *deleteMiddle(ListNode *head)
  {
    if (!head || head->next == nullptr)
    {
      ListNode *emptyNode = new ListNode();

      return nullptr;
    }

    int size = list_node_size(head);
    int mid = size / 2 - 1;
    int i = 0;

    ListNode *current = head;
    ListNode *new_head = current;
    ListNode *next = (current != nullptr) ? current->next : nullptr;

    while (current && next)
    {
      if (i == mid)
      {
        current->next = next->next;
        next->next = NULL;

        break;
      }

      current = current->next;
      next = current->next;
      i++;
    }
    return new_head;
  }
};
