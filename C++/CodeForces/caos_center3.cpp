#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false);
#define ll long long
#define pii pair<int, int>

using namespace std;

struct Client {
  int id, idx, t, p, r;
  Client(int idx, int t, int p, int r) : id(0), idx(idx), t(t), p(p), r(r) {};

  bool operator<(const Client& other) const {
    if (id == 0 and id == other.id)
      return idx > other.idx;
    else
      return id > other.id;
  }
};

int main()
{sws;
  cout.tie(0);
  int n; cin >> n;
  int time = 0;
  priority_queue<Client> f;

  for (size_t i = 0; i < n; i++)
  {
    int t; cin >> t; // tempo que cada cliente pretende utilizar para resolver seu problema
    int p; cin >> p; // a paciência do cliente na fila de espera
    int r; cin >> r; // tempo de espera para que o cliente faça uma nova ligação para o call center após o encerramento da última ligação

    Client client = Client(i, t, p, r);
    f.push(client);
  }

  while(!f.empty()) {
    Client client = f.top();
    f.pop();

    if (client.p + client.id >= time){
      if (time > client.id) {
        time += client.t;
      }
      else {
        time = client.id + client.t;
      }
    }
    else {
      client.id += client.p + client.r;
      f.push(client);
    }
  }

  std::cout << time << endl;
  return 0;
}
