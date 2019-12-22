#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, group[30];
string s[maxn];

int Find(int u) {
  if(group[u] == u) return u;
  return group[u] = Find(group[u]);
}

void Union(int u, int v)
  { group[u] = Find(v); }

int main()
{
  for(int i = 0; i < 30; i++) group[i] = i;
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j+1 < s[i].length(); j++)
      Union(s[i][j]-'a', s[i][j+1]-'a');
  }

  set<int> pw;
  for(int i = 0; i < n; i++) pw.insert(Find(s[i][0] - 'a'));
  printf("%lu\n", pw.size());

  return 0;
}
