#include<bits/stdc++.h>
using namespace std;

int const maxN = 2e5 + 10;

int N, A, Q;

int main()
{
  cin >> N;

  vector<int> idx[maxN];
  for(int i = 1; i <= N; i++) {
    cin >> A;
    idx[A].push_back(i);
  }

  cin >> Q;
  while(Q--) {
    int L, R, X;
    cin >> L >> R >> X;

    auto cntR = lower_bound(idx[X].begin(), idx[X].end(), R+1);
    auto cntL = lower_bound(idx[X].begin(), idx[X].end(), L);
    cout << cntR - cntL << endl;
  }

  return 0;
}
