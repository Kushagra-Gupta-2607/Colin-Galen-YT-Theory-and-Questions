#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    
    // f(x) -> A(0, 1), B(0, 1), C(0, 1) => using bitmasking ABC
    //                                   => A = 2^2, B = 2^1, C = 2^0
    // DP
    // State        => f(n, mask) => lowest cost to satisfy mask when only used first n strings
    // Intuition    => f(i, mask) => min(cost+f(i+1, new_mask), f(i+1, mask));
    // Base Case    => f(0, 0) = 0;
    
    int n;
    cin >> n;
    
    const ll inf = 1e17;
    vector<vector<ll>> f(n+1, vector<ll>(8, inf));
    
    f[0][0] = 0;
    
    for(int i = 0; i<n; i++){
        ll cost;
        string s;
        cin >> cost >> s;
        int string_mask = 0;
        for(int pos = 0; pos<3; pos++){
            char c = 'C' - pos;
            bool found = 0;
            for(char curr: s){
                if(c == curr) found = 1;
            }
            if(found) string_mask+= (1<<pos);
        }
        for(int mask = 0; mask<8; mask++){
            f[i+1][mask] = min(f[i+1][mask], f[i][mask]);
            f[i+1][mask | string_mask] = min(f[i+1][mask | string_mask] , f[i][mask] + cost);
        }
    }
    
    ll ans = f[n][7];
    if(ans == inf) ans = -1;
    cout << ans << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int testcases = 1;
    //cin >> testcases;
    while(testcases--){
        solve();
    }
    
    
    return 0;
}
