// 23888번 등차수열과 쿼리
// 모든 항의 합을 구할 땐 dp이용하고
// 모든 항들의 최대공약수를 구할 땐 gcd함수 사용

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll gcd(ll x,ll y){
    if (!y) return x;
    return gcd(y,x%y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll a,d,q;
    cin >> a >> d >> q;
    
    // 벡터에 앞의 항+현재 항 형태로 합 저장하기
    vector <ll> v(1000010);
    v[1]=a;
    for (ll i=2;i<1000010;i++){
        v[i]=v[i-1]+a+(i-1)*d;
    }
    
    for (ll i=0;i<q;i++){
        ll calculation, l, r;
        ll sum=0;
        cin >> calculation >> l >> r;
        
        if (calculation==1){ // 모든 항의 합
            sum=v[r]-v[l-1];
        } else if (calculation==2){ // 최대공약수
            if (l==r) sum = a+(l-1)*d; // 항이 하나이므로 자기 자신 출력
            else sum = gcd(a,d); // 초항과 공차의 최대공약수
        }
        cout << sum << "\n";
    }
    return 0;
}
