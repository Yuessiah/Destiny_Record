#include<bits/stdc++.h>
using namespace std;

struct query {
  int Q_num, Peri, time;
  bool operator<(query const &rhs) const {
    if(time == rhs.time) return Q_num > rhs.Q_num;
    return time > rhs.time;
  }
};

int Q_num, Peri, K;
char s[strlen("Register")];
priority_queue<query> argus;

int main()
{
  while(scanf("%s", s) && s[0] != '#') {
    scanf("%d%d", &Q_num, &Peri);
    argus.push((query){Q_num, Peri, Peri});
  }

  scanf("%d", &K);
  while(K--) {
    query res = argus.top(); argus.pop();
    printf("%d\n", res.Q_num);

    res.time += res.Peri;
    argus.push(res);
  }

  return 0;
}
