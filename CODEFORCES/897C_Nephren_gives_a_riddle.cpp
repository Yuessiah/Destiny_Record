// This solution is to imitate dotorya's code.
#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;

int const maxn = 1e5 + 100;
long long const INF = 0x3f3f3f3f3f3f3f3f;

char const f0[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char const f[]  = "What are you doing while sending \"@\"? Are you busy? Will you send \"@\"?";
int const f_len = strlen(f);

int q, N;
long long K, f_l[maxn]; //length of f_i

char dfs(int n, long long k) {
  if(n == 0 && k < f_l[0]) return f0[k];

  for(int c = 0; c < f_len; c++) {
    if(f[c] == '@') {
      if(k < f_l[n-1]) return dfs(n-1, k);
      k -= f_l[n-1];
    } else {
      if(k == 0) return f[c];
      k--;
    }
  }

  return '.';
}

int main()
{
  //init
  f_l[0] = strlen(f0);
  for(int i = 1; i < maxn; i++) f_l[i] = min(INF, 2*f_l[i-1] + f_len - 2);

  scanf("%d", &q);

  while(q--) {
    scanf("%d%lld", &N, &K);
    putchar(dfs(N, K-1));
  }

  return 0;
}
