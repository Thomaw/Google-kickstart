#include<cstdio>
long long int g;
int main() {
	int tcn;
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%lld", &g);
		int ans = 0;
		for (long long int i = 1;; i++) {
			long long int r = i * (i + 1) / 2;
			if (r > g)break;
			if ((g - r) % i == 0)ans++;
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}
