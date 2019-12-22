#include<bits/stdc++.h>
using namespace std;

long long A, B;

int main()
{
  cin >> A >> B;
  cout << A*B/__gcd(A, B) << endl;
}
