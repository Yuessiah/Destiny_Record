#include<stdio.h>
#include<vector>
using std::vector;
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

struct heap {
	vector<int> q;
	void push(int n)
	{
		q.push_back(n);
		int fp = (q.size()-1)/2, cp = q.size()-1;

		while(q[fp] > q[cp] && cp) {
			swap(q[fp], q[cp]);
			cp = fp; fp = cp/2;
		}
	}
	void pop()
	{
		q[0] = q[q.size()-1];
		q.resize(q.size()-1);
		int fp = 0, rcp = fp*2+1, lcp = fp*2, nex;

		while(fp*2 < q.size()) {
			nex = fp*2;
			if(fp*2+1 < q.size() && q[fp*2] > q[fp*2+1]) nex = fp*2+1;
			if(q[fp] > q[nex]) {
				swap(q[fp], q[nex]);
				fp = nex;
			} else break;
		}
	}
	int top() { return q[0]; }
	bool empty() { if(q.empty()) return 1; return 0; }
};

int main()
{
	heap h;
	int T;
	scanf("%d", &T);
	while(T--) {
		int op, n;
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d", &n);
			h.push(n);
		} else if(op == 2) {
			if(h.empty()) printf("empty!");
			else { printf("%d", h.top()); h.pop(); }
			putchar('\n');
		}
	}
	return 0;
}
