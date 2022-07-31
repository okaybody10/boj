#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M;
int A[150009], V[150009];
pii dp1[150009];
pii dp2[150009];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i] >> V[i];
	}

	for (int i = 1; i <= N; i++) {
		dp1[i] = {-2000000000, -1};
		dp2[i] = {-2000000000, -1};
	}
	dp1[1] = make_pair(V[1], A[1]);
	dp2[1] = make_pair(0, -1);

	for (int i = 2; i <= N; i++) {
		vector<pair<int, int>> vec;
		if (dp1[i - 1].second != A[i]) vec.push_back({dp1[i - 1].first + V[i], A[i]});
		if (dp2[i - 1].second != A[i]) vec.push_back({dp2[i - 1].first + V[i], A[i]});
		vec.push_back({dp1[i - 1].first, dp1[i - 1].second});
		vec.push_back({dp2[i - 1].first, dp2[i - 1].second});
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		
		dp1[i] = vec[0];
        int t = vec.size();
		for (int j = 1; j < t; j++) {
			if (vec[j].second == vec[0].second) continue;
			dp2[i] = vec[j];
			break;
		}
	}

	cout << dp1[N].first << endl;
	return 0;
}