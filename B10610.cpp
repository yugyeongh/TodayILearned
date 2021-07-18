// 10610번 30 실버5

/*
 1. cin >> str
 2. 숫자 합이 3의 배수이면 정렬해주고 3의 배수가 아니거나 숫자에 0이 포함되지 않으면 -1 출력
 3. 내림차순 정렬하기
 */

#include <iostream>
#include <algorithm>
using namespace std;

bool cmp (int a, int b){
    if (a>b) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string str;
    cin >> str;
    
    int sum=0;
    bool flag = false;
    for (int i=0;i<str.size();i++){
        int n = str[i]-'0';
        if (!n) flag = true;
        sum += n;
    }
    
    if (sum%3 != 0 || !flag){
        cout << -1;
    } else {
        sort(str.begin(),str.end(),cmp);
        cout << str;
    }
    return 0;
}
