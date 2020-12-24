#include<bits/stdc++.h>
using namespace std;

int t;
long long A, B;

int main()
{
  cin >> t;
  while(t--) {
    cin >> A >> B;
    cout << A * (int)log10(B+1) << endl;
  }

  return 0;
}
