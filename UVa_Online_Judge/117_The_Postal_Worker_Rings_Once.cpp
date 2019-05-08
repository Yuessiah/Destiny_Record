#include<bits/stdc++.h>
using namespace std;

int const maxn = 27;

string s;
int G[maxn][maxn], deg[maxn];

int main()
{
  while(1) {
    memset(deg, 0, sizeof deg);
    memset(G, 0x3f, sizeof G);
    for(int u = 0; u < maxn; u++) G[u][u] = 0;
    int dist = 0;

    while(cin >> s && s != "deadend") {
      int u = s.front() - 'a', v = s.back()  - 'a';

      dist += s.length();
      G[u][v] = G[v][u] = min(G[v][u], (int)s.length());
      deg[u]++, deg[v]++;
    }
    if(cin.eof()) return 0;

    vector<int> odd;
    for(int u = 0; u < maxn; u++)
      if(deg[u] & 1) odd.push_back(u);

    if(!odd.empty()) {
      for(int k = 0; k < maxn; k++)
        for(int u = 0; u < maxn; u++)
          for(int v = 0; v < maxn; v++)
            G[u][v] = min(G[u][v], G[u][k] + G[k][v]);

      dist += G[odd[0]][odd[1]];
    }

    cout << dist << endl;
  }

  return 0;
}
