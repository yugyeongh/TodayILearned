// 13250번 주사위 게임
// dp[x]: 현재 가지고 있는 사탕이 x개 일 때, 주사위를 추가로 던져야 하는 횟수의 기댓값
// (그 상태일 때의 기댓값+상태변화cost)*확률

#include <iostream>
using namespace std;

double dp[1000010];

double f(int x){
    if (dp[x]>=0) return dp[x];
    double ans = 0;
    for (int i=1;i<=6;i++){
        ans += (1.00/6.00)*(1+f(x+i));
    }
    return dp[x]=ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        dp[i]=-1.00;
    }
    cout << fixed;
    cout.precision(13);
    cout << f(0);
    return 0;
}
