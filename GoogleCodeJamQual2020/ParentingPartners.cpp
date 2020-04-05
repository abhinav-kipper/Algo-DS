//This is better solution by Asharam Meena
// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool comp(pair<int, pair<bool, int> > p1,
			pair<int, pair<bool, int> > p2) {
	
	if (p1.first==p2.first) return p1.second.first > p2.second.first;
	return p1.first < p2.first;
				
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for (int tt=1; tt<=t; tt++) {
		int  n;
		cin >> n;
		vector<pair<int, pair<bool, int> > > v;
		bool check[n+1], possible = true;
		memset(check, false, sizeof(check));
		for (int i=1; i<=n; i++) {
			int si, ei;
			cin >> si >> ei;
			v.push_back(make_pair(si, make_pair(0, i)));
			v.push_back(make_pair(ei, make_pair(1, i)));
		}
		sort(v.begin(), v.end(), comp);
		bool cameron = false, jamie = false;
		for (auto i : v) {
			if (!i.second.first) {
				if (cameron && jamie) {
					possible = false;
					break;
				}
				if (!cameron) {
					check[i.second.second] = true;
					cameron = true;
				} else if (!jamie) {
					check[i.second.second] = false;
					jamie = true;
				}
			} else {
				if (check[i.second.second]) {
					cameron = false;
				} else {
					jamie = false;
				}
			}
		}
		string ans;
		if (possible) {
			ans = "";
			for (int i=1; i<=n; i++) {
				ans += check[i] ? 'C' : 'J';
			}
		} else {
			ans = "IMPOSSIBLE";
		}
		
		
		cout << "Case #" << tt << ": " << ans << endl;
	}
    
}
