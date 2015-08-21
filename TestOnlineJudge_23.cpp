int s1[5000], s2[5000], t1 = -1, t2 = -1, ord_pos = 0;
bool ok = 0;

bool is_order(const int& w)
{
	if(s2[t2] == w) {
		ord_pos++; t2--; pop_train();
		if(t2 == -1) ok = 0;
		return 1;
	} return 0;
}
void solve(int N, int order[])
{
	for(int i = 1; i <= N; i++) { s1[++t1] = i; push_train(); }

	for(;;) {
		if(t1 == -1 && t2 == -1) break;
		if(!ok) {
			s2[++t2] = s1[t1--];
			move_station_1_to_2();
			if(t1 == -1) ok = 1;
		}
		if(!is_order(order[ord_pos]) && ok) {
			s1[++t1] = s2[t2--];
			move_station_2_to_1();
			if(t2 == -1) ok = 0;
		}
	}
}
