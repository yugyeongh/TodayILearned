// 24040번 예쁜 케이크
// 장식용 띠는 가로 폭이 1인 빨간색, 초록색, 하얀색 직사각형이 순서대로 번갈아 가면서 같은 개수만큼 나와야 함
// 즉, N의 가로+세로와 3의 최대공약수가 1이 아니면 예쁜 케이크를 만들 수 있음
// ax+by=1 -> xy=n, (x+y) mod 3

// 모든 가로와 세로의 길이는 3n,3n+1,3n+2로 표현이 가능하고
// 두 변의 길이의 합이 3의 배수가 될 수 있는 경우는 다음 2가지
// 1. 3n+3n=3n
// 2. (3n+1)+(3n+2)=3n+3=3n

// 따라서 합이 3의 배수일 때 곱을 구하면
// 1. 3n*3n=9n^2
// 2. (3n+1)*(3n+2)=9n^2+9n+2
// 👉🏻즉, 입력 n이 주어졌을 때 9의 배수이거나 3으로 나눈 나머지가 2이면 예쁜 케이크 만들기 가능!!


#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; long long N;
    cin >> T;
    while (T--){
        cin >> N;
        if ((N%9)==0 || (N%3)==2) cout << "TAK" << '\n';
        else cout << "NIE" << '\n';
    }
    return 0;
}
