#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 100;

int n, a[maxn];
vector<int> ans;

int main()
{
  scanf("%d", &n);

  long long int sum = 0;
  int m1 = 0, m2 = 0;

  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if(m1 < a[i]) m2 = m1, m1 = a[i];
    else if(m2 < a[i]) m2 = a[i];
    sum += a[i];
  }

  for(int i = 1; i <= n; i++) {
    long long int aft = sum - a[i]; // aft := after remove a[i]

    if(a[i] == m1 && aft == 2*m2) ans.push_back(i);
    if(a[i] != m1 && aft == 2*m1) ans.push_back(i);
  }

  printf("%d\n", ans.size());
  for(auto it: ans) printf("%d ", it);
  putchar('\n');

  return 0;
}
