#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    
    int n, k;
    ll ans = 0;
    string s;
    cin >> n >> k >> s;
    vector<int> v(26, 0);
    while(k--){
        char c;
        cin >> c;
        v[c-'a'] = 1;
    }
    for(int i = 0; i<n; ++i){
        if(v[s[i]-'a']) s[i] = '1';
        else s[i] = '0';
    }
    
    // 2 pointer Approach----------------
    // int i = 0, j = 0;
    // while(j<n){
    //     if(s[j] == '1') ans+=j-i+1;
    //     else i = j+1;
    //     j++;
    // }
    // cout << ans << endl;
    // ----------------------------------
    
    // DP
    // State        => f(i) => No. of substrings ending at i
    // Intuition    =>
    //        a) f(i) = 0         when s[i] == '0';
    //        b) f(i) = f(i-1)+1  when s[i] == '1'; (+1 is for the new single character)
    // 
    // Base Case    => f(0) = 0
    vector<ll> f(n+1);
    f[0] = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '0')
            f[i+1] = 0;
        else
            f[i+1] = f[i]+1;
        ans+=f[i+1];
    }
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
