// 1058 친구 실버2
// 사용 알고리즘: 다익스트라 -> 플로이드 와샬
// 플로이드 와샬: 모든 최단 경로를 구하는 알고리즘

// 플로이드 와샬 알고리즘
// 1. 모든 최단 경로를 저장할 인접행렬
// 2. d[i][j] > d[i][k]+d[k][j]면 d[i][j]=d[i][k]+d[k][j]로 

#include <iostream>
#define INF 98765
using namespace std;

int N;
string str;
int graph[51][51];

void floyd(){
    for (int k=0;k<N;k++){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    
    cin >> N;
    // 친구 관계 저장하기
    for (int i=0;i<N;i++){
        cin >> str;
        for (int j=0;j<N;j++){
            if (str[j]=='Y') graph[i][j]=1;
            else graph[i][j]=INF;
        }
    }
    
    // 최단 거리 저장하기
    floyd();
    
    // 1또는 2인 관계 저장하기
    int result=0;
    for (int i=0;i<N;i++){
        int cnt=0;
        for (int j=0;j<N;j++){
            if (i==j) continue;
            if (graph[i][j]==2 || graph[i][j]==1) cnt++;
        }
        result=max(result,cnt);
    }
    cout << result;
}
