/*
** Version 1
*/

int main()
{
	initialize();
	long long h = 0x7fffffff, l = 1, m;
	if(throw_egg(h)) answer(h);
	else while(l != h) {
		m = (h+l)/2;
		if(throw_egg(m)) l = m+1; else h = m;
	} answer(l-1);
}


/*
** Version 2
*/

#define ceil(a, b) (a-1)/b + 1

int main()
{
	initialize();
	long long h = 0x7fffffff, l = 1, m;
	if(throw_egg(h)) answer(h);
	else while(l != h) {
		m = ceil(l+h, 2);
		if(throw_egg(m)) l = m; else h = m-1;
	} answer(l);
}
