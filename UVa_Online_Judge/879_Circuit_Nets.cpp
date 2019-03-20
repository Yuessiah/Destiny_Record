#include<bits/stdc++.h>
using namespace std;

const int maxn = 65535;

int N, group[maxn];

int Find(int u) { return (u == group[u])? u : group[u] = Find(group[u]); }
void Union(int u, int v) { group[Find(u)] = Find(v); }

int main()
{
  /*
  ios::sync_with_stdio(false);
  cin.tie(0);
  */

  int T;
  cin >> T;

  while(T--) {
    cin >> N;
    for(int i = 1; i <= N; i++) group[i] = i;

    int u, v;
    string pins;

    cin.ignore();
    while(getline(cin, pins)) {
      if(pins.empty()) break;

      stringstream sin(pins);
      while(sin >> u >> v) Union(u, v);
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++) if(Find(i) == i) cnt++;

    cout << cnt << '\n';
    if(T) cout << endl;
  }

  return 0;
}
