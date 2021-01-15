#include<cstdio>
#include<stack>
using namespace std;
typedef long long Int;

int const maxN = 8e4 + 5;

int N, h[maxN];

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", &h[i]);

  Int ans = 0;
  stack<pair<int, Int> > s;
  for(int i = N-1; i >= 0; i--) {
    Int cnt = 0;
    while(s.size() && s.top().first < h[i])
      cnt += s.top().second, s.pop();

    s.push({h[i], 1 + cnt}); // 1 for self
    ans += cnt;
  }

  printf("%lld\n", ans);

  return 0;
}
