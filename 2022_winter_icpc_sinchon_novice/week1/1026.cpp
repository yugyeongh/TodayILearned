// 1026번
// 이건 진짜 생각할 게 없을 정도임
// 그냐 하나는 오름차순, 하나는 내림차순해서 곱해서 더하면 됨

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int A[51],B[51];

bool cmp(int x,int y){
    return x > y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i=0;i<n;i++) cin >> A[i];
    for (int i=0;i<n;i++) cin >> B[i];
    
    sort(A,A+n);
    sort(B,B+n,cmp);
    
    int sum=0;
    for (int i=0;i<n;i++){
        sum += A[i]*B[i];
    }
    cout << sum;
    
    return 0;
}
