#include<cstdio>

int N, K;

int main()
{
  scanf("%d%d", &N, &K);
  puts((N-1)/2+1 >= K? "YES" : "NO");

  return 0;
}
