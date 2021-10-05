// 17218 비밀번호 만들기
// 공통으로 존재하는 가장 긴 부분 문자열을 비밀번호로

/* 내가 처음 생각한 풀이임... */
// for i in str1.length()
// for j in str2.length()
// str1[i] == str2[j] 찾으면 j위치 저장해놓고 break
// 다음 i일 때 j위치부터 시작하도록
// i,j의 for문 나오면 dp[k]=temp
// ‼️ 예시는 다 맞게 나오지만 왠지 모르게 틀렸습니다가 뜸 ‼️

// LCS 알고리즘 - 최장 공통 부분수열
// 2차원 배열을 사용해서 두 문자열을 행,열에 매칭해서 같은 문자가 있으면 LCS[i-1][j-1]+1을 해줌

#include <iostream>
using namespace std;

string str1,str2;
int arr[1001][1001]={0,};

void lcs(int x,int y){
    if (x==0 || y==0) return;
    if (str1[x] == str2[y]){
        lcs(x-1,y-1);
        cout << str1[x];
    } else {
        if (arr[x][y-1] == arr[x][y]){
            lcs(x,y-1);
        } else {
            lcs(x-1,y);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> str1 >> str2;
    
    for (int i=1;i<=str1.length();i++){
        for (int j=1;j<=str2.length();j++){
            if (str1[i] == str2[j]){ // 두 문자가 같으면 대각선 위의 숫자+1을 한다.
                arr[i][j] = arr[i-1][j-1]+1;
            } else { // 두 문자가 다르면 위쪽 혹은 오른쪽에 있는 숫자 중 큰 수를 넣는다.
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    lcs(str1.length(),str2.length());
    return 0;
}
