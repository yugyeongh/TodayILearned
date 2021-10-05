// 2339 석판 자르기 -> 너무 어려운걸
// 시간제한 2초, 메모리 제한 128MB
// 알고리즘: 분할정복, 재귀

// input: 석판의 크기 N (1은 불순물, 2는 보석 결정체, 0은 불순물과 보석결정체가 존재하지 않는 곳) *보석 결정체 수 <= 15*
// 석판 안에 불순물이 없고, 단 하나의 보석 결정체만 있도록 석판을 나눌 때 모두 몇 가지의 경우가 존재하는지 출력 (가능한 경우가 없으면 -1출력)

/* 선언할 것들 */
// 1. 보석 벡터
// 2. 불순물 벡터
// 3. graph
// 4. cnt - 석판을 나누는 방법의 수 저장

// 보석 벡터에서 하나 빼서 i<=x,j<=y동안 graph가 다 0인지 확인
// 0이면 cnt 증가
// 1이나 2가 있으면 어케하지

// i=0,1,2,..순으로 불순물을 찾아나감
// 불순물을 찾으면 먼저 갈

#include <iostream>
#include <vector>
using namespace std;

int map[21][21]={0,};
vector <pair<int,int>> jewerly;
vector <pair<int,int>> stone;
int N,a,cnt=0;

int division(int x1,int y1,int x2,int y2,bool flag){
    int result = 0;
    for (int y=y1;y<y1;y++){
        for (int x=x1;x<x1;x++){
            if (map[y][x]==1 && !flag){ //분순물이 있고, 세로로 자르는 경우
                bool check = true;
                for (int i=y1+1;i<y2-1;i++){
                    if (map[i][x] == 2){ // 세로에 보석이 있는 경우
                        check = false;
                        break;
                    }
                }
                if (check){ // 세로에 보석이 없는 경우 다시 나누기
                    result += division(x1,y1,x,y2,false)*division(x+1,y1,x2,y2,false);
                }
            } else if (map[y][x]==1 && flag) { // 불순물이 있고, 가로로 자르는 경우
                bool check = true;
                for (int i=x1+1;i<x2-1;i++){
                    if (map[i][x] == 2){ // 가로에 보석이 있는 경우
                        check = false;
                        break;
                    }
                }
                if (check){ // 가로에 보석이 없는 경우 다시 나누기
                    result += division(x1,y1,x2,y,true)*division(x1,y+1,x2,y2,true);
                }
            }
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> map[i][j];
            if (map[i][j] == 1){
                stone.push_back({i,j});
            } else if (map[i][j] == 2){
                jewerly.push_back({i,j});
            }
        }
    }
    // 석판 가로로 자르기
    int cnt1 = division(0,0,N,N,true);
    // 석판 세로로 자르기
    int cnt2 = division(0,0,N,N,false);
    
    if (cnt1+cnt2==0) cout << -1;
    else cout << cnt1+cnt2;
}

