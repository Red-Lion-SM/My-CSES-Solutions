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
    int n; cin >> n;
    string a[n];
    forr(i,0,n) cin >> a[i];
    
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    if(a[n - 1][n - 1] == '.') dp[n - 1][n - 1] = 1;
    
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(a[i][j] == '*') continue;
            if(i + 1 < n) dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
            if(j + 1 < n) dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
        }
    }
    
    cout << dp[0][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}