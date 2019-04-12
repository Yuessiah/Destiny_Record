// bouns: O(n log n)
#include<bits/stdc++.h>
using namespace std;

int n, h;
vector<int> a, idx;

bool chk(int k) {
  vector<int> s; // sorted a[0..k]
  for(auto &i: idx) if(i <= k) s.push_back(a[i]);

  int th = h; // copy from h
  for(int i = 0; i < s.size(); i+=2) {
    th -= s[i];
    if(th < 0) return false;
  }

  return true;
}

int main() {
  scanf("%d%d", &n, &h);

  a.resize(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    idx.push_back(i);
  }

  sort(idx.begin(), idx.end(), [&](int x, int y) { return a[x] > a[y]; });

  int l = 0, r = n;
  while(l != r) {
    int m = (l+r)/2;
    if(!chk(m)) r = m;
    else l = m+1;
  }

  printf("%d\n", l);

  return 0;
}
