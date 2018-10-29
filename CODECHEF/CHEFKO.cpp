#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int N, K;
pair<int, int> S[maxn];

int main()
{
  int T;
  scanf("%d", &T);

  while(T--) {
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++) scanf("%d%d", &S[i].first, &S[i].second);

    int ans = 0;
    priority_queue<int, vector<int>, greater<int> > PQ; // sort the right
    sort(S, S+N); // sort the left

    for(int i = 0; i < N; i++) {
      PQ.push(S[i].second);
      if(PQ.size() == K) {
        ans = max(ans, PQ.top() - S[i].first);
        PQ.pop();
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
