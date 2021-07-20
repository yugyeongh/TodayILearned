// 2437번 저울 골드3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N,a;
    cin >> N;
    
    for (int i=0;i<N;i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    
    int sum=0;
    for (int i=0;i<v.size();i++){
        if (v[i] > sum+1) break;
        sum += v[i];
    }
    cout << sum+1;
}
