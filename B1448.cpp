// 1448번 삼각형 만들기 실버3

/*
 1. cin >> N
 2. 반복문으로 길이 입력받기
 3. sort - cmp이용해서 내림차순 정리
 4. 반복시키면서 line값을 변화시키며 조건문에 만족하는지 확인
 5. flag 변수둬서 삼각형 만들기 불가능이면 flag=false고,
 6. 반복문을 나와서 조건문을 실행하도록
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
    if (a>b) return true;
    return false;
}
int line1,line2,line3,sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector <int> v(N);
    for (int i=0;i<N;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end(),cmp);
    
    bool flag=false;
    for (int i=0;i<v.size()-2;i++){
        line1=v[i];
        line2=v[i+1]; line3=v[i+2];
        sum = line2+line3;
        
        if (line1 < sum){
            cout << sum+line1 << '\n';
            flag=true;
            break;
        }
    }
    if (!flag){
        cout << -1;
    }
    return 0;
}
