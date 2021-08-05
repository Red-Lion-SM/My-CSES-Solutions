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

int n, m;

void solve() {
    cin >> n >> m;
    int a[n + 1];
    int dp[n + 2][m + 2];

    forr(i, 1, n + 1) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    
    int ans = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int x = 1; x <= m; x++) {
            if(i == 1) {
                if(a[i] != 0 && a[i] != x) dp[i][x] = 0;
                else dp[i][x] = 1;
            }
            else {
                if(a[i] != 0 && a[i] != x) dp[i][x] = 0;
                else dp[i][x] = ((dp[i - 1][x - 1] + dp[i - 1][x]) % mod + dp[i - 1][x + 1]) % mod;
            }
            if(i == n) ans = (ans + dp[i][x]) % mod;
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}