#include<bits/stdc++.h>
using namespace std;

int const maxk = 800;

struct sum {
  int s, i; //sum, index
  bool operator<(sum const &rhs) const
    { return s > rhs.s; }
};

int k, a[maxk], b[maxk];

int main()
{
  while(~scanf("%d", &k)) {
    for(int c = 0; c < k; c++) scanf("%d", &a[c]);

    for(int r = 1; r < k; r++) {
      priority_queue<sum> pq;

      for(int c = 0; c < k; c++) scanf("%d", &b[c]);
      sort(b, b+k);

      for(int c = 0; c < k; c++) pq.push((sum){a[c]+b[0], 0});

      for(int c = 0; c < k; c++) {
        int s = pq.top().s, i = pq.top().i;
        pq.pop();

        pq.push((sum){s-b[i]+b[i+1], i+1});
        a[c] = s;
      }
    }

    for(int c = 0; c < k; c++) printf("%d%c", a[c], (c<k-1)? ' ' : '\n');
  }

  return 0;
}
