#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

const int maxn = 15 + 5;

int n, sz;
set<vector<int> > his;
vector<int> seq;


void input()
{
	int in;
	for(int i = 0; i < n; i++) {
		scanf("%d", &in);
		seq.push_back(in);
	}
	sz = seq.size();
	his.insert(seq);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		his.clear();
		seq.resize(0);

		scanf("%d", &n);
		input();

		int steps = 1010;
		while(steps--) {
			vector<int> nxt;
			for(int i = 0; i < sz-1; i++) {
				int num = abs(seq[i]-seq[i+1]);
				nxt.push_back(num);
			} nxt.push_back(abs(seq[sz-1]-seq[0]));

			//ZERO check
			bool zero = 1;
			for(int i = 0; i < sz-1; i++) if(nxt[i+1] != nxt[i]) zero = 0;
			if(zero) { puts("ZERO"); break; }

			//LOOP check
			if(his.count(nxt)) { puts("LOOP"); break; }

			seq = nxt; his.insert(nxt);
		}
	}

	return 0;
}
