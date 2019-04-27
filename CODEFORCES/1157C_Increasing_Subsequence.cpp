#include<bits/stdc++.h>
using namespace std;

int const maxn = 2e5 + 10;

int n, a[maxn];
string s;

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  int last = 0, L = 0, R = n-1;
  for(int i = 0; i < n; i++) {
    if(last < a[L] && last < a[R]) {
      if(a[L] == a[R]) {
        string s_R, s_L;

        int rast = last;
        while(R >= 0 && rast < a[R]) s_R += 'R', rast = a[R--];
        while(L <  n && last < a[L]) s_L += 'L', last = a[L++];
        s += s_R.size() > s_L.size()? s_R : s_L;

        break;
      }

      if(a[L] < a[R])
        last = a[L++], s += 'L';
      else
        last = a[R--], s += 'R';
    }
    else if(last < a[L])
      last = a[L++], s += 'L';
    else if(last < a[R])
      last = a[R--], s += 'R';
    else break;
  }

  cout << s.size() << endl;
  cout << s << endl;

  return 0;
}
