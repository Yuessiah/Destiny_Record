#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5 + 10;

int n, A[maxn], B[maxn];

int cmp(int x, int y) {
  return x > y;
}

int main()
{
  scanf("%d", &n);

  for(int i = 0; i < n; i++) scanf("%d", &A[i]);
  for(int i = 0; i < n; i++) scanf("%d", &B[i]);

  sort(A, A+n, cmp);
  sort(B, B+n, cmp);

  int a = 0, b = 0;
  long long int A_score = 0, B_score = 0;
  for(int i = 0; i < n; i++) {
    if(b != n && (a == n || A[a] < B[b])) b++;
    else A_score += A[a++];

    if(a != n && (b == n || B[b] < A[a])) a++;
    else B_score += B[b++];
  }

  printf("%lld\n", A_score - B_score);

  return 0;
}
