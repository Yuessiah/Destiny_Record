#include<cstdio>

int main()
{
  int N, L, sum = 0, maxi = 0;

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &L);
    sum += L;
    if(L > maxi) maxi = L;
  }

  sum -= maxi;
  puts(sum > maxi? "Yes" : "No");

  return 0;
}
