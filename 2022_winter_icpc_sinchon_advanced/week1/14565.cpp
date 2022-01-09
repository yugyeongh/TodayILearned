// 14565번 역원(inverse) 구하기
// 덧셈역: (a+b)mod n=0 -> n-a = b
// 곱셈역: (a*c)mod n=1

#include <iostream>
using namespace std;
using ll = long long;

ll extended_gcd(ll a,ll b,ll &x,ll &y){
    if (!b){
        x=1; y=0;
        return a;
    }
    ll result = extended_gcd(b,a%b,x,y);
    ll temp = y;
    y = x-(a/b)*y;
    x = temp;
    if (x<=0){
        x+=b;
        y-=a;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n,a,x,y;
    cin >> n >> a;
    
    if (extended_gcd(a,n,x,y)!=1) x=-1;
    
    cout << n-a << " " << x << '\n';
    
    return 0;
}
