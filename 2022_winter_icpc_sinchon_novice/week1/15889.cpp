// 15889번
// 7프로에서 틀림;;

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,x,y;
int location[1000010];
int range[1000010];
vector <pair<int,int>> v;
bool checked[30010]={false,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    // 좌표,사거리 저장
    for (int i=0;i<n;i++){
        cin >> location[i];
    }
    for (int i=0;i<n-1;i++){
        cin >> range[i];
    }
    range[n]=0;
    for (int i=0;i<n;i++){
        v.push_back({location[i],range[i]});
    }
    
    // 좌표 기준 오름차순 정렬
    sort(v.begin(),v.end());
    
    int idx=0;
    checked[0]=true;
    for (int i=1;i<n;i++){
        int distance = v[i].first - v[idx].first;
        if (v[idx].second >= distance){
            idx=i;
            checked[i]=true;
        }
    }
    bool flag=true;
    for (int i=0;i<n;i++){
        if (!checked[i]){
            flag=false;
            break;
        }
    }
    
    if (flag) cout << "권병장님, 중대장님이 찾으십니다";
    else cout << "엄마 나 전역 늦어질 것 같아";
    return 0;
}
