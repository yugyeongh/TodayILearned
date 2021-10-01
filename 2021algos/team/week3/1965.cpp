// 1965번 상자 넣기
// 알고리즘: LIS(최장 증가 부분 수열)

// 📍최장 증가 부분 수열이란?
// 배열에서 숫자가 증가하는 순서대로 숫자를 고르고, 부분 수열의 길이가 최대 길이가 되도록 숫자를 선택해야 함!!
// 최장 증가 부분 수열의 길이가 얼마인지 푸는 간단한 방법은 DP를 이용하는 것이다! -> 시간복잡도가 O(n^2)이 됨
// LIS를 구하는 문제의 답은 한 수열에서 주어지는 LIS의 길이가 됨 -> 즉, 그 수열에 존재하는 모든 부분 증가 수열 중 길이가 최대인 수열의 길이가 답이 됨
// dp[i]: i번쨰 수를 마지막 원소로 가지는 LIS의 길이

// 값이 매우 커지면 이분 탐색 이용하기


#include <iostream>
using namespace std;

int N;
int arr[1001]={0,};
int dp[1001]={0,};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    /* 입력 */
    cin >> N;
    for (int i=0;i<N;i++) cin >> arr[i];

    /* LIS 알고리즘 (dp이용) */
    int res=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<i;j++){
            if (arr[i] > arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
                res = max(dp[i],res);
            }
        }
    }
    cout << res+1;
    return 0;
}
