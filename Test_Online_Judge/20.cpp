#include<cstdio>
#include<cstring>
const int max = 200000, maxp = 1000000;

struct queue {
	int data;
	queue *prev, *next;
};
queue* addpeople(int x=0)
{
	queue* u = new queue;
	u->data = x;
	u->prev = u->next = u;
	return u;
}
void insert(queue* a, queue* b)
{
	b->next = a->next; a->next = b;
	b->prev = a; b->next->prev = b;
}
void remove(queue* u)
{
	u->next->prev = u->prev;
	u->prev->next = u->next;
	u->prev = u->next = NULL;
	delete u;
}
bool empty(queue* u)
{
	if(u->prev == u && u->next == u) return 1;
	return 0;
}

int main()
{
	int n, k, x, cnt = 0;
	while(~scanf("%d", &n)) {
		queue *q1 = addpeople(), *q2[max];
		int map[maxp];
		char cmd[8];
		memset(map, 0, sizeof(map));

		for(int i = 1; i <= n; i++) {
			q2[i] = addpeople();
			scanf("%d", &k);
			while(k--) { scanf("%d", &x); map[x] = i;}
		}

		printf("Line #%d\n", ++cnt);
		for(;;) {
			scanf("%s", cmd);
			if(cmd[0] == 'S') break;
			else if(cmd[0] == 'D') {
				int t = q1->prev->data;
				printf("%d\n", q2[t]->prev->data); remove(q2[t]->prev);
				if(empty(q2[t])) remove(q1->prev);
			} else if(cmd[0] == 'E') {
				scanf("%d", &x);
				int t = map[x];
				if(!t) {
					insert(q1, addpeople(++n));
					q2[n] = addpeople(); insert(q2[n], addpeople(x));	
				} else {
					if(empty(q2[t])) insert(q1, addpeople(t));
					insert(q2[t], addpeople(x));
				}
			}
		}
	}
	return 0;
}
