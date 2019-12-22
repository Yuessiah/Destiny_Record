#include<bits/stdc++.h>
using namespace std;

int N;
string S, T;

int main()
{
  scanf("%d", &N);
  cin >> S >> T;

  string P;
  for(int i = 0; i < N; i++) P += S[i], P += T[i];

  cout << P << endl;
}
