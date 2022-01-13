// 18870번

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,a,cnt=0;
    cin >> n;
    
    vector <pair<int,int>> v,res;
    
    for (int i=0;i<n;i++){
        cin >> a;
        v.push_back({a,i});
    }
    sort(v.begin(),v.end());
    res.push_back({v[0].second,0});
    
    for (int i=1;i<n;i++){
        if (v[i-1].first != v[i].first){
            res.push_back({v[i].second,++cnt});
        } else {
            res.push_back({v[i].second,cnt});
        }
    }
    sort(res.begin(),res.end());
    
    for (int i=0;i<n;i++){
        cout << res[i].second << ' ';
    }
    return 0;
}
