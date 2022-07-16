#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;
    
    // --------------------------------
    // Basic Intuitive Approach
    // if(n%2){ // Odd
    //     cout << "0\n";
    //     return;
    // }  
    // cout << (ll)pow(2, n/2) << endl;
    // --------------------------------
    
    // DP:
    // Intuition -> F(n) = F(n-2) + F(n-2)
    // Base Case -> F(0) = 1, F(1) = 0
    
    vector<ll> func(n+1);
    func[0] = 1, func[1] = 0;
    for(int i = 2; i<=n; ++i)
        func[i] = 2*func[i-2];
    
    cout << func[n] << endl;
    
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
