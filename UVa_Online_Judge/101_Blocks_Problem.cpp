#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int maxn = 26;

int n, pos[maxn];
vector<int> pile[maxn];

int find_height(int obj, int p)
{
	int i = 0;
	for(; i < pile[p].size() && pile[p][i] != obj; i++);
	return i + 1;
}

void restore_above(int p, int h)
{
	int top = pile[p].size();
	for(int i = h; i < top; i++) {
		int blc = pile[p][i];
		pos[blc] = blc;
		pile[blc].push_back(blc);
	}
	pile[p].resize(h);
}

void move_to(int ap, int ah, int bp, int bh)
{
	int top = pile[ap].size();
	for(int i = ah-1; i < top; i++) {
		int blc = pile[ap][i];
		pile[bp].push_back(blc);
		pos[blc] = bp;
	}
	pile[ap].resize(ah-1);
}

void output()
{
	for(int i = 0; i < n; i++) {
		cout << i << ":";
		int len = pile[i].size();
		if(len) for(int j = 0; j < len; j++)
			cout << " " << pile[i][j];
		cout << endl;
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) {
		pos[i] = i;
		pile[i].push_back(i);
	}

	string c1, c2;
	int a, b;
	while(cin >> c1 >> a >> c2 >> b) {
		if(pos[a] == pos[b]) continue;

		int ah = find_height(a, pos[a]);
		int bh = find_height(b, pos[b]);
		if(c1 == "move") restore_above(pos[a], ah);
		if(c2 == "onto") restore_above(pos[b], bh);
		move_to(pos[a], ah, pos[b], bh);
	}

	output();

	return 0;
}
