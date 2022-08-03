/* 1720 타일 코드 */
/*
 > 전체 타일의 개수: dp[n] = dp[n-1] + dp[n-2]*2
 dp[0]=0, dp[1]=1, dp[2]=3
 > 좌우 대칭인 타일의 개수
     - 홀수일 떄: dp[n/2]
     - 짝수일 때: dp[n/2-1]*2 + dp[n/2]
 */

#include <iostream>
using namespace std;

int dp[31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    dp[0]=0; dp[1]=1; dp[2]=3;
    
    for (int i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]*2);
    }
    
    if (n<=2) cout << dp[n] << '\n';
    else {
        if (n%2==0) cout << (dp[n] + dp[n/2] + dp[n/2-1]*2) / 2 << '\n';
        else cout << (dp[n] + dp[n/2]) / 2 << '\n';
    }
    
    return 0;
}
