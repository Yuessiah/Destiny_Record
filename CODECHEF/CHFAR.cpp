#include<cstdio>

int N, K, a;

int main()
{
  int T;
  scanf("%d", &T);

  while(T--) {
    scanf("%d%d", &N, &K);

    int cnt = 0;
    for(int i = 0; i < N; i++) {
      scanf("%d", &a);
      if(a != 1) cnt++;
    }

    puts((K-cnt >= 0)? "YES" : "NO");
  }

  return 0;
}
