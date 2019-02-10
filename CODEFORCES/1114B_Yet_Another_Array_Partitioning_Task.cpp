#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 100;

int n, m, k, a[maxn];
vector<int> idx;

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    idx.push_back(i);
  }

  long long sum = 0;
  sort(idx.begin(), idx.end(), [&](int x, int y) { return a[x] > a[y]; });
  for(int i = 0; i < m*k; i++) sum += a[idx[i]];
  printf("%lld\n", sum);


  sort(idx.begin(), idx.begin() + m*k);
  for(int i = m-1; i < m*(k-1); i+=m) printf("%d ", idx[i]+1);
  putchar('\n');

  return 0;
}
