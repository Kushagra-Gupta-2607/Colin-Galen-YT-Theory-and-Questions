#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll iterative_push_dp(int n){
    if(n<2) return n;
    vector<ll> dp(n+2);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 0; i<n; ++i){
        dp[i+1]+=dp[i];
        dp[i+2]+=dp[i];
    }
    return dp[n];
}

ll iterative_pull_dp(int n){
    if(n<2) return n;
    vector<ll> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i<=n; ++i)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

ll recursive_dp(int n, vector<ll>& dp){
    if(n<2) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = recursive_dp(n-1, dp) + recursive_dp(n-2, dp);
}

void fibonacci(int n){
    if(n<0) return;
    
    vector<ll> dp_rec(n+1, -1);
    cout << "Recursive DP: " << recursive_dp(n, dp_rec) << endl;
    
    cout << "Iterative Pull DP: " << iterative_pull_dp(n) << endl;
    cout << "Iterative Push DP: " << iterative_push_dp(n) << endl;

}

int main() {

    int n;
    cin >> n;
    fibonacci(n);
    
    
    return 0;
}
