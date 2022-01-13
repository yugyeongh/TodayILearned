// 1448번

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,arr[1000010];

bool cmp(int x,int y){
    return x > y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n,cmp); // 내림차순 정렬
    
    int line1,line2,line3,sum=0;
    for (int i=0;i<n-2;i++){
        line1=arr[i];
        line2=arr[i+1];
        line3=arr[i+2];
        sum = line2+line3;
        
        if (line1 < sum){
            cout << sum+line1 << '\n';
            return 0;
        }
    }
    cout << -1;
    return 0;
}
