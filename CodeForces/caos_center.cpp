#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false);
#define ll long long
#define pii pair<int, int>

using namespace std;

struct Client {
  int id, t, p, r, tp;
  Client(int id, int t, int p, int r) : id(id), t(t), p(p), r(r), tp(0) {};
};

int main()
{sws;
  int n; cin >> n;
  int opt = 0;
  int time = 0;
  queue<Client> f;

  for (size_t i = 0; i < n; i++)
  {
    int t; cin >> t; // tempo que cada cliente pretende utilizar para resolver seu problema
    int p; cin >> p; // a paciência do cliente na fila de espera
    int r; cin >> r; // tempo de espera para que o cliente faça uma nova ligação para o call center após o encerramento da última ligação

    Client client = Client(i, t, p, r);
    f.push(client);
  }

  while(!f.empty()) {
    Client client = f.front();

    if(!opt) {
      time += client.t;
      opt = 1;
      f.pop();
    } else {
      if (client.p >= time) {
        time += client.t;
      }
      else if(client.tp >= time) {
        time += abs(client.tp-time);
        time += client.t;
      }
      else if(client.tp + client.p >= time) {
        time += client.t;
      }
      else {
        client.tp += client.r + client.p;
        f.push(client);
      }
      f.pop();
    }
  }

  std::cout << "time: " << time << endl;
  return 0;
}
