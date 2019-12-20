#include<bits/stdc++.h>
using namespace std;

int n;
string y;

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    cin >> y;

    int sum = 0;
    bool zero = false, even = false;
    for(int j = 0; j < y.length(); j++) {
      if(!zero && y[j] == '0') zero = true;
      else if((y[j]-'0')%2 == 0) even = true;
      sum += y[j] - '0';
    }

    if(zero && even && (sum%3 == 0)) puts("red");
    else puts("cyan");
  }

  return 0;
}
