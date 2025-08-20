#include <vector>
#include <array>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

int main()
{

  // Declaration and Initialization:
  std::vector<int> vec = {1, 2, 3};
  std::array<int, 3> arr = {1, 2, 3};
  std::deque<int> deq = {1, 2, 3};
  std::list<int> lst = {1, 2, 3};
  std::set<int> st = {3, 1, 2};            // Sorted, no duplicates
  std::map<int, int> mp;                   // Sorted keys
  std::unordered_set<int> ust = {3, 1, 2}; // Unsorted, no duplicates
  std::unordered_map<int, int> ump;        // Unsorted keys
  std::queue<int> q;                       // FIFO
  std::stack<int> s;                       // LIFO

  // Common Operations:
  vec.push_back(4);           // Adds at end
  deq.push_front(0);          // Adds at front
  lst.insert(lst.begin(), 0); // Inserts at beginning
  st.insert(4);               // Inserts (logarithmic time)
  mp[4] = 44;                 // Inserts or updates key-value pair
  ust.insert(4);              // Inserts (constant time)
  ump[4] = 44;                // Inserts or updates key-value pair
  q.push(5);                  // Enqueues element
  s.push(6);                  // Pushes element onto stack

  int x = vec.back();  // Access last element
  int y = arr[1];      // Access by index
  int z = *st.begin(); // Access smallest element
  int w = mp[4];       // Access value by key

  vec.pop_back();         // Removes last element
  deq.pop_front();        // Removes first element
  lst.erase(lst.begin()); // Removes element at beginning
  st.erase(3);            // Removes element (logarithmic time)
  mp.erase(4);            // Removes element by key
  ust.erase(4);           // Removes element (constant time)
  ump.erase(4);           // Removes element by key
  q.pop();                // Dequeues element
  s.pop();                // Pops element from stack

  bool emptyVec = vec.empty(); // Checks if empty
  int vecSize = vec.size();    // Gets size
  int setCount = st.count(2);  // Count occurrences (1 if present, 0 if not)
  auto it = st.find(2);        // Returns iterator to element (or end if not found)

  q.empty();              // Checks if queue is empty
  int frontQ = q.front(); // Access front element
  int backQ = q.back();   // Access back element

  int topS = s.top(); // Access top element of stack
}
