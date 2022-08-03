#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int strength[100];

int main()
{
    strength[2] = 1;
	ll A, B, ans = 0, lcm = 1;
	scanf("%lld %lld", &A, &B);
	for (int K = 2; K < 100; K++)
	{
		for (int i = 2; i < K; i++) {
			if (K % i != 0) {
				strength[K] = strength[i] + 1;
				break;
			}
		}
		ll now_lcm = lcm;
		vector<int> is_prime;
		for (int p = 2, k = K; k > 1; p++) {
			if (k % p == 0) {
				is_prime.push_back(p);
				while (k % p == 0) {
					k /= p;
				}
			}
		}
		if (is_prime.size() == 1) now_lcm *= is_prime[0];
		ans += (strength[K] + 1) * (B/lcm - (A-1)/lcm);
		if (now_lcm > B) break;
		ans -= (strength[K] + 1) * (B/now_lcm - (A-1)/now_lcm);
		lcm = now_lcm;
	}
	return !printf("%lld", ans);
}
