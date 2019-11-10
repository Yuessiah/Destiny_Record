#include<bits/stdc++.h>
using namespace std;

int q, a, b, n, S;

int main(){
  scanf("%d", &q);
  while(q--) {
    scanf("%d%d%d%d", &a, &b, &n, &S);

    puts((b >= S-min(S/n, a)*n)? "YES" : "NO");
  }

  return 0;
}
