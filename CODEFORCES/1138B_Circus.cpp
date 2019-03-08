#include<bits/stdc++.h>
using namespace std;

int const maxn = 5e3 + 10;

struct artist { int a, c; };

int n;
string a, c;
vector<artist> V;

int main() {
  cin >> n;
  V.resize(n);

  cin >> c >> a;
  for(int i = 0; i < n; i++) V[i].c = c[i]-'0';
  for(int i = 0; i < n; i++) V[i].a = a[i]-'0';


  for(int s = n/2; s >= 0; s--) {
    int idx[maxn];
    memset(idx, 0, sizeof idx);
    int nc1 = s, na1 = s, nc0 = n/2-s, na0 = n/2-s;

    //(1, 0)
    for(int i = 0; i < n; i++) {
      if(idx[i]) continue;
      if(!nc1) break;
      if(V[i].c == 1 && V[i].a == 0) nc1--, idx[i] = 1;
    }
    //(1, 1)
    for(int i = 0; i < n; i++) {
      if(idx[i]) continue;
      if(!nc1) break;
      if(V[i].c == 1 && V[i].a == 1) nc1--, idx[i] = 1;
    }

    //(1, 1)
    for(int i = 0; i < n; i++) {
      if(idx[i]) continue;
      if(!na1) break;
      if(V[i].c == 1 && V[i].a == 1) na1--, idx[i] = 2;
    }

    //(0, 1)
    for(int i = 0; i < n; i++) {
      if(idx[i]) continue;
      if(!na1) break;
      if(V[i].c == 0 && V[i].a == 1) na1--, idx[i] = 2;
    }

    //(0, 1)
    for(int i = 0; i < n; i++) {
      if(idx[i]) continue;
      if(!nc0) break;
      if(V[i].c == 0 && V[i].a == 1) nc0--, idx[i] = 1;
    }

    //(0, 0)
    for(int i = 0; i < n; i++) {
      if(idx[i]) continue;
      if(!nc0) break;
      if(V[i].c == 0 && V[i].a == 0) nc0--, idx[i] = 1;
    }

    //(0, 0)
    for(int i = 0; i < n; i++) {
      if(idx[i]) continue;
      if(!na0) break;
      if(V[i].c == 0 && V[i].a == 0) na0--, idx[i] = 2;
    }

    //(1, 0)
    for(int i = 0; i < n; i++) {
      if(idx[i]) continue;
      if(!na0) break;
      if(V[i].c == 1 && V[i].a == 0) na0--, idx[i] = 2;
    }

    if(!nc1 && !na1 && !nc0 && !na0) {
      for(int i = 0; i < n; i++) if(idx[i] == 1) printf("%d ", i+1);
      putchar('\n');
      return 0;
    }
  }

  puts("-1");
  return 0;
}
