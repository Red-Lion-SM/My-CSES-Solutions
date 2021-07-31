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
    int n; cin >> n;
    int dp[n + 1] = {0};
    dp[0] = 1;
    forr(i, 1, n +1) {
        for(int j = i - 1; j >= max(0ll, i - 6); j--) {
            dp[i] = ((dp[i] % mod) + (dp[j] % mod)) % mod;
        }
    }
    cout << dp[n] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}
