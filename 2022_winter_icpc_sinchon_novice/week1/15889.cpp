// 15889번
// 생각보다 너무 간단하게 풀림..
// 전우가 바뀔 때마다 어느 좌표까지 움직일 수 있는지 max함수로 계속 갱신해주고,
// 만약 움직일 수 있는 좌표가 더 작으면 false

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,x,y;
int location[30010];
int range[30010];
vector <pair<int,int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    // 좌표,사거리 저장
    for (int i=0;i<n;i++) cin >> location[i];
    for (int i=0;i<n-1;i++) cin >> range[i];
    range[n-1]=0;
    for (int i=0;i<n;i++) v.push_back({location[i],range[i]});
    
    // 좌표 기준 오름차순 정렬
    sort(v.begin(),v.end());
    
    if (n == 1){
        cout << "권병장님, 중대장님이 찾으십니다";
        return 0;
    }
    
    int can=0;
    for (int i=0;i<n-1;i++){
        can = max(can,v[i].first+v[i].second);
        if (can < v[i+1].first){
            cout << "엄마 나 전역 늦어질 것 같아";
            return 0;
        }
    }
    cout << "권병장님, 중대장님이 찾으십니다";
    return 0;
}

