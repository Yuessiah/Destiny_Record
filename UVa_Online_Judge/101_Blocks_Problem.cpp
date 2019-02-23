#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int maxn = 26;

int n, pos[maxn]; // pos := position
vector<int> pile[maxn];

int height(int obj) {
  int i = 0, p = pos[obj];
  for(; pile[p][i] != obj; i++);

  return i + 1;
}

void return_above(int obj) {
  int p = pos[obj], h = height(obj);

  for(int i = h; i < pile[p].size(); i++) {
    int w = pile[p][i]; // w := wood
    pile[w].push_back(w);
    pos[w] = w;
  }

  pile[p].resize(h);
}

void move_to(int a, int b) {
  int ap = pos[a], bp = pos[b];
  int ah = height(a);

  for(int i = ah-1; i < pile[ap].size(); i++) {
    int w = pile[ap][i]; // w := wood
    pile[bp].push_back(w);
    pos[w] = bp;
  }

  pile[ap].resize(ah-1);
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    pos[i] = i;
    pile[i].push_back(i);
  }

  int a, b;
  string c1, c2;
  while(cin >> c1 && c1 != "quit") {
    cin >> a >> c2 >> b;

    if(pos[a] == pos[b]) continue;

    if(c1 == "move") return_above(a);
    if(c2 == "onto") return_above(b);
    move_to(a, b);
  }

  // output
  for(int i = 0; i < n; i++) {
    cout << i << ":";
    for(int j = 0; j < pile[i].size(); j++) cout << " " << pile[i][j];
    cout << endl;
  }

  return 0;
}
