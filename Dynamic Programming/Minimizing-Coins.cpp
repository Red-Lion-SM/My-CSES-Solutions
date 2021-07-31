// The ones who fear failure are those who have never tasted it..

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define int long long
#define vec_i vector<int>
#define sz(x) (int)(x.size())
#define all(x) (x).begin(),(x).end()
#define forr(x,a,m) for(int x=a;x<m;x+=1)
const int mod = 1000000007;

void solve() {
    int n, x; cin >> n >> x;
    int a[n]; forr(i, 0, n) cin >> a[i];
    int dp[1000001];
    forr(i, 0, 1000001) dp[i] = 1000001;
    dp[0] = 0;
    forr(i,0,n) {
        dp[a[i]] = 1;
    }
    forr(i, 1, x + 1) {
        forr(j,0,n) {
            if(i - a[j] < 0) continue;
            dp[i] = min(dp[i - a[j]] + 1, dp[i]);
        }
    }
    if(dp[x] == 1000001) dp[x] = -1;
    cout << dp[x] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}