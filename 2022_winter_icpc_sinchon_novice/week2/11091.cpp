// 11091번 알파벳 전부 쓰기

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    cin.ignore();
    string str;
    for (int i=0;i<n;i++){
        getline(cin,str);
        
        int alpha[26]={0,};
        for (int j=0;j<str.length();j++){
            if (isalpha(str[j])){
                if (str[j] >= 65 && str[j] <= 90){
                    str[j] = tolower(str[j]);
                }
                alpha[str[j]-97]=1;
            }
        }
        bool flag=true;
        for (int j=0;j<26;j++){
            if (alpha[j]==0) {
                flag = false;
            }
        }
        if (flag){
            cout << "pangram";
        } else {
            cout << "missing ";
            for (int j=0;j<26;j++){
                if (alpha[j]==0){
                    cout << char(j+97);
                }
            }
        }
        cout << '\n';
        
    }
    return 0;
}
