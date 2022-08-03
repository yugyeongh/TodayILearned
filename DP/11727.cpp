/* 11727 2xn 타일 2 */
/*
 점화식: dp[n] = dp[n-1] + dp[n-2]*2
 dp[0]=0, dp[1]=1, dp[2]=3
 */

#include <iostream>
using namespace std;

int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    dp[0]=0; dp[1]=1; dp[2]=3;
    
    for (int i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;
    }
    cout << dp[n] << '\n';
    
    return 0;
}
