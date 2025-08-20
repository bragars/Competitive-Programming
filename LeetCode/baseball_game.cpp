#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int bask(vector<string> &vec)
    {
        vector<int> aux_vec;
        int points = 0;

        for (int i = 0; i < vec.size(); i++)
        {
            string current = vec[i];
            cout << "current " << current << endl;

            if (current == "C")
            {
                aux_vec.erase(aux_vec.begin() + (aux_vec.size() - 1));
            }
            else if (current == "D")
            {
                int aux = aux_vec[aux_vec.size() - 1];
                aux_vec.push_back(aux * 2);
            }
            else if (current == "+")
            {
                int s_aux = aux_vec[aux_vec.size() - 1];
                int f_aux = aux_vec[aux_vec.size() - 2];
                aux_vec.push_back(f_aux + s_aux);
            }
            else
            {
                aux_vec.push_back(stoi(current));
            }
        }

        for (int num : aux_vec)
        {
            cout << "num " << num << endl;
            points += num;
        }

        return points;
    };
};

int main()
{
    Solution solution;
    vector<string> m;
    string line;

    while (getline(cin, line))
    {
        for (char c : line)
        {
            string str(1, c);
            m.push_back(str);
        }
    }

    int result = solution.bask(m);
    cout << "Total points: " << result << endl;
    return 0;
}
