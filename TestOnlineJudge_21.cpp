#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
struct players {
	int num;
	players *front, *back;
};
vector<players*> map;

players* addplayer(int x=0)
{
	players* p = (players*)malloc(sizeof(players));
	p->num = x;
	p->front = p->back = NULL;
	return p;
}
void insert(players* p1, players* p2)
{
	p2->back = p1->back; p1->back = p2;
	p2->front = p1; if(p2->back != NULL) p2->back->front = p2;
}
void remove(int id)
{
	map[id]->front->back = map[id]->back;
	if(map[id]->back != NULL) map[id]->back->front = map[id]->front;
	map[id]->front = map[id]->back = NULL;
}
void printall(players* queue)
{
	for(;;) {
		printf("%d", queue->num);
		queue = queue->back;
		if(queue == NULL) break;
		else putchar(' ');
	}
	putchar('\n');
}

int main()
{
	int n, m, i;
	players* leader = addplayer();
	map.push_back(leader);
	scanf("%d%d", &n, &m);

	players* tmp = leader;
	for(i = 1; i <= n; i++) {
		players* p = addplayer(i);
		map.push_back(p);
		insert(tmp, p);
		tmp = tmp->back;
	}

	while(m--) {
		int t, x;
		scanf("%d%d", &t, &x);
		if(t) {
			tmp = map[x]->front->front;
			if(tmp == NULL) continue;
			remove(x);
			insert(tmp, map[x]);
		}else {
			remove(x);
			free(map[x]);
		}
	}
	printall(leader->back); 
	return 0;
}
