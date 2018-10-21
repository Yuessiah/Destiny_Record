#include<bits/stdc++.h>
using namespace std;

int N;
string S;
set<string> ST;

int compute(string P) {
  int time = 0;
  char pre = 0;

  for(auto &now: P) {
    if(!pre) time += 2;
    else {
      if(pre == 'd' || pre == 'f') {
        if(now == 'd' || now == 'f') time += 4;
        else time += 2;
      } else {
        if(now == 'd' || now == 'f') time += 2;
        else time += 4;
      }
    }

    pre = now;
  }

  return time;
}

int main()
{
  int T;
  cin >> T;

  while(T--) {
    ST.clear();
    int time = 0;

    cin >> N;
    while(N--) {
      cin >> S;

      if(ST.count(S)) {
        time += compute(S)>>1;
      } else {
        ST.insert(S);
        time += compute(S);
      }
    }

    cout << time << '\n';
  }

  return 0;
}
