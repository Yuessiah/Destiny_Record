#include<cstdio>
#include<vector>
#include<cmath>
using std::vector;
int k;

bool check_block(const int& x, const int&y)
{
	int a = (x+k)/k, b = y/k;
	if(b-a >= 1) return 1;
	return 0;
}

int main()
{
	int T, n, z;
	scanf("%d%d", &T, &n);
	vector<int> arr, team;

	for(int i = 0; i < n; i++) {
		scanf("%d", &z);
		arr.push_back(z);
	}
	k = pow(n, 0.5); int min;
	for(int i = 0; i < n; i+=k) {
		min = 1000001;
		for(int j = i; j < i+k && j < n; j++) if(min > arr[j]) min = arr[j];
		team.push_back(min);
	}

	int op, x, y;
	while(T--) {
		scanf("%d%d%d", &op, &x, &y);
		min = 1000001;
		if(op == 1) {
			int a = (x+k)/k*k, b = y/k*k;
			if(check_block(x, y)) {
				for(int i = (x+k)/k; i < y/k; i++) if(min > team[i]) min = team[i];
				for(int i = x; i <  a; i++) if(min > arr[i]) min = arr[i];
				for(int i = b; i <= y; i++) if(min > arr[i]) min = arr[i];
			} else for(int i = x; i <= y; i++) if(min > arr[i]) min = arr[i];
			printf("%d\n", min);
		} else if(op == 2) {
			arr[x] = y;
			for(int i = x/k*k; i < x/k*k+k; i++) if(min > arr[i]) min = arr[i];
			team[x/k] = min;
		}
	}
	return 0;
}
