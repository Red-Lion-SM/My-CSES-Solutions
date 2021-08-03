// The ones who fear failure are those who have never tasted it..

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define vec_i vector<int>
#define sz(x) (int)(x.size())
#define all(x) (x).begin(),(x).end()
#define forr(x,a,m) for(int x=a;x<m;x+=1)
const int mod = 1000000007;

void solve() {
    int n, x; cin >> n >> x;
    int h[n]; forr(i,0,n) cin >> h[i];
    int s[n]; forr(i,0,n) cin >> s[i];
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    forr(i, 1, n + 1) {
        forr(j, 1, x + 1) {
            dp[i][j] = max(dp[i - 1][j], j - h[i - 1] >= 0 ? dp[i - 1][j - h[i - 1]] + s[i - 1] : 0);
        }
    }
    cout << dp[n][x] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}