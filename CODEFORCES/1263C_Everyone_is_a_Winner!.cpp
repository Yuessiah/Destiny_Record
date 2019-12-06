#include<bits/stdc++.h>
using namespace std;

int t, n;

int main() {
  scanf("%d", &t);

  while(t--) {
    scanf("%d", &n);

    vector<int> ans(1, 0);
    int pre = 0;
    while(pre != n) {
      int l = 1, r = n+1;
      while(l != r) {
        int k = (l+r)/2, x = n/k;
        if(x <= pre) r = k;
        else l = k + 1;
      }

      ans.push_back(n/(l-1));
      pre = n/(l-1);
    }

    printf("%d\n", ans.size());
    for(int x: ans) printf("%d ", x);
    putchar('\n');
  }

  return 0;
}
