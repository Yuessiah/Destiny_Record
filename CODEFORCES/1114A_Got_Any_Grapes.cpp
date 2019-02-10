#include<cstdio>

int x[4], a[4];

int main()
{
  for(int i = 1; i <= 3; i++) scanf("%d", &x[i]);
  for(int i = 1; i <= 3; i++) scanf("%d", &a[i]);

  for(int i = 1; i <= 3; i++) {
    a[i] += a[i-1];
    if(a[i] < x[i]) { puts("NO"); return 0; }
    a[i] -= x[i];
  }

  puts("YES"); return 0;
}
