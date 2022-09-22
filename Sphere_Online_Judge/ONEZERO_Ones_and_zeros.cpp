#include<bits/stdc++.h>
using namespace std;

int constexpr maxn = 2e5 + 10;

int K, n;

int main()
{
  cin >> K;
  while(K--) {
    cin >> n;

    queue<int> q;
    string d[maxn];
    q.push(1);
    d[1] = '1';

    while(q.size()) {
      int u = q.front(); q.pop();
      if(u == 0) break;

      int v1 = (u*10 + 0) % n;
      int v2 = (u*10 + 1) % n;
      if(d[v1].empty()) d[v1] = d[u]+'0', q.push(v1);
      if(d[v2].empty()) d[v2] = d[u]+'1', q.push(v2);
    }

    cout << d[0] << endl;
  }

  return 0;
}
