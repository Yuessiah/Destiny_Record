#include<bits/stdc++.h>
using namespace std;

int T, kase = 0, N;
string P;

int main()
{
  scanf("%d", &T);

  while(T--) {
    cin >> N >> P;

    string M;
    for(int i = 0; i < P.size(); i++)
      M.push_back((P[i] == 'E')? 'S' : 'E');

    cout << "Case #" << ++kase << ": " << M << '\n';
  }

  return 0;
}
