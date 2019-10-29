#include<bits/stdc++.h>
using namespace std;

int t;
string a;

int main()
{
  scanf("%d", &t);

  while(t--) {
    cin >> a;

    vector<int> od, ev; // odd, even
    for(char c: a) {
      int d = c-'0';

      if(d&1) od.push_back(d);
      else ev.push_back(d);
    }

    int i = 0, j = 0;
    while(i < od.size() || j < ev.size()) {
      if(j >= ev.size() || (i < od.size() && od[i] < ev[j])) printf("%d", od[i++]);
      else printf("%d", ev[j++]);
    }
    putchar('\n');
  }

  return 0;
}
