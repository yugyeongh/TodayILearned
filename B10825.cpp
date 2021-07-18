// 10825 국영수 실버4

/*
조작된 사람들은 거짓말을 함 -> 진짜 피실험자도 짧은 줄을 길다고 말함
 1. cin >> N
 2. 반복문으로 학생 이름, 국어, 영어, 수학 점수 입력받기 (구조체로 저장)
 3. 벡터 sort (cmp 함수 사용) - 국어 점수 내림차순, 국어 점수 같으면 영어 점수 오름차순, 국영 점수 같으면 수학점수 내림차순, 다 같으면 이름 사전 순
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct STUDENT {
    string name;
    int k;
    int e;
    int m;
}s;

bool cmp(const STUDENT &a, const STUDENT &b){
    if (a.k > b.k) return true;
    else if (a.k == b.k){
        if (a.e < b.e) return true;
        else if (a.e == b.e){
            if (a.m > b.m) return true;
            else if (a.m == b.m){
                if (a.name < b.name) return true;
            }
        }
    }
    return false;
}

vector <STUDENT> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    while (N--){
        cin >> s.name >> s.k >> s.e >> s.m;
        v.push_back(s);
    }
    
    sort(v.begin(),v.end(),cmp);
    
    for (int i=0;i<v.size();i++){
        cout << v[i].name << '\n';
    }
    
    return 0;
}
