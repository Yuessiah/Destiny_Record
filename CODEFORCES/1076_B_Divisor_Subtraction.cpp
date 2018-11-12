#include<cstdio>

int main()
{
  long long int n;
  scanf("%lld", &n);

  for(long long int d = 2; d*d <= n; d++) if(n%d == 0) {
    printf("%lld\n", (n-d)/2 + 1);
    return 0;
  }

  puts("1");
}
