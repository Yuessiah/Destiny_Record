#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

int N;
priority_queue<Int, vector<Int>, greater<Int> > PQ;

int main()
{
  while(scanf("%d", &N) && N) {
    while(N--) {
      int num;
      scanf("%d", &num);
      PQ.push(num);
    }

    Int cost = 0;
    while(PQ.size() != 1) {
      Int a = PQ.top(); PQ.pop();
      Int b = PQ.top(); PQ.pop();
      cost += a += b;
      PQ.push(a);
    } PQ.pop();

    printf("%lld\n", cost);
  }

  return 0;
}
