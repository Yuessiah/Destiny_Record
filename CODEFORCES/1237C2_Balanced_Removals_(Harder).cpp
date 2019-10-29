#include<bits/stdc++.h>
using namespace std;

int const D = 3;

int n;
vector<vector<int>> p;

int remove(vector<int> idx, int k) {
  if(k == D) return idx[0];

  map<int, vector<int>> same;
  for(int i: idx) same[p[i][k]].push_back(i);

  vector<int> line;
  for(auto it: same) {
    int rem = remove(it.second, k+1);
    if(~rem) line.push_back(rem);
  }

  for(int i = 0; i+1 < line.size(); i+=2) printf("%d %d\n", line[i]+1, line[i+1]+1);

  return line.size()%2? line.back() : -1;
}

int main()
{
  scanf("%d", &n);
  p.assign(n, vector<int>(D));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < D; j++) scanf("%d", &p[i][j]);

  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  remove(idx, 0);

  return 0;
}
