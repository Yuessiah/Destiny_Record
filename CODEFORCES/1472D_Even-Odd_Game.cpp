#include<bits/stdc++.h>
using namespace std;

int t, n, a;

int main()
{
  cin >> t;
  while(t--) {
    cin >> n;

    vector<int> bob, ali;
    for(int i = 0; i < n; i++) {
      cin >> a;
      if(a&1) bob.push_back(a);
      else ali.push_back(a);
    }

    sort(bob.begin(), bob.end());
    sort(ali.begin(), ali.end());

    long long sb = 0, sa = 0;
    for(int i = 0; i < n; i++) {
      if(i&1) {
        if(ali.empty() || (bob.size() && bob.back() > ali.back())) sb += bob.back(), bob.pop_back();
        else ali.pop_back();
      } else {
        if(bob.empty() || (ali.size() && bob.back() < ali.back())) sa += ali.back(), ali.pop_back();
        else bob.pop_back();
      }
    }

    if(sa > sb) puts("Alice");
    if(sa < sb) puts("Bob");
    if(sa == sb) puts("Tie");
  }

  return 0;
}
