#include<cstdio>
#include<algorithm>
using std::max;

int const maxn = 5e3 + 10;

int n, k, a[maxn];
double ans = 0;

int main()
{
  scanf("%d%d", &n, &k);

  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  for(int i = 0; i < n; i++) {
    double sum = 0;
    for(int j = i; j < n; j++) {
      sum += a[j];
      if(j-i+1 >= k) ans = max(ans, sum/(j-i+1));
    }
  }

  printf("%lf\n", ans);

  return 0;
}
