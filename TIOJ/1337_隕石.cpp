#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

struct line { int L, R; };
int N, K;
vector<line> A; // astroid
vector<int> CK;

bool safe(int d) {
  priority_queue<int> ls; // shoot target list
  int cnt_x = 0, cnt_r[maxn] = {}; // count astroid at x and r

  int i = 0, k = K;
  for(int x = 0; x < CK.size(); x++) {
    for(; i < N && A[i].L == x; i++) {
      cnt_x++, cnt_r[A[i].R]++;
      ls.push(A[i].R);
    }
    cnt_x -= cnt_r[x];

    while(cnt_x > d && k--) {
      cnt_x--, cnt_r[ls.top()]--;
      ls.pop();
    }

    if(cnt_x > d) return false;
  }

  return true;
}

int main()
{
  scanf("%d%d", &N, &K);

  A.resize(N);
  for(int i = 0; i < N; i++) {
    scanf("%d%d", &A[i].L, &A[i].R);
    CK.push_back(A[i].L);
    CK.push_back(A[i].R);
  }

  // discretization
  sort(CK.begin(), CK.end());
  CK.resize(unique(CK.begin(), CK.end()) - CK.begin());
  for(int i = 0; i < N; i++) {
    A[i].L = lower_bound(CK.begin(), CK.end(), A[i].L) - CK.begin();
    A[i].R = lower_bound(CK.begin(), CK.end(), A[i].R) - CK.begin();
  }

  sort(A.begin(), A.end(), [&](line i, line j) { return i.L < j.L; });

  // find answer
  int l = 0, r = N+1;
  while(l != r) {
    int m = l + (r-l)/2;
    if(safe(m)) r = m;
    else l = m + 1;
  }

  printf("%d\n", l);

  return 0;
}
