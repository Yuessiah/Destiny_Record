#include<cstdio>
#include<cstring>

int d[7];

int main()
{
  memset(d, 0, sizeof d);

  for(int i = 0; i < 6; i++) {
    int t;
    scanf("%d", &t);
    d[t]++;
  }

  int cnt = 0;
  for(int t = 0; t < 6; t++) if(d[t]&1) cnt++;

  puts(cnt<=2? "YES" : "NO");

  return 0;
}
