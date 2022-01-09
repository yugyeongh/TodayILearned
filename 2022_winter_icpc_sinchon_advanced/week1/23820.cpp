// 23820번 MEX
// 집합 S에 포함되지 않은 가장 작은 음이 아닌 정수가 mex(S)
// 길이가 n이고, 수열 S = {ai,...,an}이 주어질 때 ai*aj로 표현되지 않는 가장 작은 음이 아닌 정수 x구하기
// S={0,1,2}라면 {0,1,2,4}가 나오므로 3이 구하고자 하는 값 x가 됨

#include <iostream>
#include <vector>
using namespace std;

bool arr[2000010],checked[2000010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long n,a;
    cin >> n;
    
    for (int i=0;i<n;i++){
        cin >> a;
        arr[a]=true;
    }
    for (int i=0;i<=1;i++){
        if (!arr[i]){
            cout << i;
            return 0;
        }
    }
    for (long long i=1;i<2000010;i++){
        if (!arr[i]) continue;
        for (long long j=1;j<2000010;j++){
            if (i*j > 2000010) break;
            if (!arr[j]) continue;
            checked[i*j]=true;
        }
    }
    for (int i=2;i<2000010;i++){
        if (checked[i]) continue;
        else cout << i;
        return 0;
    }
}
