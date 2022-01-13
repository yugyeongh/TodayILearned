#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string str;
    cin >> str;
    
    vector <string> v;
    
    for (int i=0;i<str.length();i++){
        v.push_back(str.substr(i,str.length()));
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++){
        cout << v[i] << '\n';
    }
    return 0;
}
