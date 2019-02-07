#include<cstdio>

int b, k, a;

int main()
{
  scanf("%d%d", &b, &k);

  int res = 0;
  while(k--) {
    scanf("%d", &a);
    res = (res + (k? (b&1) : 1)*(a&1)) & 1;
  }

  puts(res? "odd" : "even");

  return 0;
}
