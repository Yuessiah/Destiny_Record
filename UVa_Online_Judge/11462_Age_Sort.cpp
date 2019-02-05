#include<cstdio>
#include<cstring>

int const bound = 100 + 10;

int n, c[bound];

int main()
{
  while(scanf("%d", &n) && n) {
    memset(c, 0, sizeof c);

    int age;
    for(int i = 0; i < n; i++) {
      scanf("%d", &age);
      c[age]++;
    }

    for(int i = 1; i < bound; i++) {
      while(c[i]--) printf("%d%c", i, (--n)? ' ' : '\n');
      if(!n) break;
    }
  }

  return 0;
}
