#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

class Employee
{
public:
  Employee(int id, int time_spent, int flag) : id(id), time_spent(time_spent), flag(flag) {}
  int get_id() const
  {
    return id;
  }

  int get_time_spent() const
  {
    return time_spent;
  }

  int get_needed_time_spent() const
  {
    return needed_time_spent;
  }

  int get_flag() const
  {
    return flag;
  }

  void set_id(int new_id)
  {
    id = new_id;
  }

  void set_time_spent(int new_time_spent)
  {
    time_spent = new_time_spent;
  }

  void set_needed_time_spent(int new_needed_time_spent)
  {
    needed_time_spent = new_needed_time_spent;
  }

  void set_flag(int new_flag)
  {
    flag = new_flag;
  }

  void assign_client(int client_num_items)
  {
    int time_spent = get_time_spent() * client_num_items;

    set_flag(1);
    set_needed_time_spent(time_spent);
  }

private:
  int id;
  int time_spent;
  int needed_time_spent;
  int flag;
};

int32_t main()
{
  sws;
  int n, m;
  cin >> n >> m;

  vector<Employee> employees;
  queue<int> f;

  for (size_t i = 0; i < n; i++)
  {
    int employee_time_spent;
    cin >> employee_time_spent;
    Employee employee = Employee(i, employee_time_spent, 0);
    employees.push_back(employee);
  }

  for (size_t i = 0; i < m; i++)
  {
    int basket_num_items;
    cin >> basket_num_items;
    f.push(basket_num_items);
  }

  while (!f.empty())
  {
    for (size_t i = 0; i < employees.size(); i++)
    {
      Employee current_employee = employees.at(i);

      if (current_employee.get_flag() == 0)
      {
        current_employee.assign_client(f.front());
        f.pop();
      }
      else
      {
        if (current_employee.get_needed_time_spent())
        {
          current_employee.assign_client(f.front());
          f.pop();
        }
      }
    }

    return 0;
  }
