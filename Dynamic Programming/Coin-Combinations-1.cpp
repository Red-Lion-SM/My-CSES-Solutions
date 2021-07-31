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
    int a[n]; forr(i,0,n) cin >> a[i];
    int dp[1000001] = {0};
    dp[0] = 1;
    sort(a, a + n);
    forr(i, 0, x + 1) {
        forr(j, 0, n) {
            if(i - a[j] < 0) break;
            dp[i] = (dp[i] + dp[i - a[j]]) % mod;
        }
    }
    cout << dp[x] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tin = 1; // cin >> tin;
    while (tin--) solve();
    return 0;
}