#include<bits/stdc++.h>
using namespace std;

string grid, ans;
unordered_map<string, int> d;
bool vis[987654322];
queue<string> q;

int main()
{
  for(int i = 1, a; i <= 9; i++) {
    cin >> a;
    grid.push_back('0'+a);
    ans.push_back('0'+i);
  }

  d[grid] = 0;
  vis[stoi(grid)] = true;
  q.push(grid);

  while(q.size()) {
    auto u = q.front(); q.pop();
    if(u == ans) break;

    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++) {
        auto v1 = u, v2 = u;
        if(i < 2) swap(v1[3*i+j], v1[3*(i+1)+j]);
        if(j < 2) swap(v2[3*i+j], v2[3*i+(j+1)]);

        if(!vis[stoi(v1)])
          vis[stoi(v1)] = true, q.push(v1), d[v1] = d[u]+1;
        if(!vis[stoi(v2)])
          vis[stoi(v2)] = true, q.push(v2), d[v2] = d[u]+1;
      }
  }

  cout << d[ans] << endl;

  return 0;
}
