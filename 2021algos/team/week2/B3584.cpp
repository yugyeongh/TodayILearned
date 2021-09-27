// 3584 가장 가까운 공통 조상 (골드4)
// 알고리즘: 트리,최소 공통 조상
// dfs로도 풀 수 있을거같음
/*
📌 풀이방법
  1. 벡터에 자식을 인덱스로 하고, 부모 노드의 번호를 벡터에 저장함 -> parent[자식노드] = 부모노드
  2. 찾고자하는 노드의 루트를 찾기 위해 반복문을 사용해 parent 벡터에서 타고타고 조상을 구해서 마지막에 루트를 구함 -> 구한 부모들은 벡터에 저장하기
  3. 각 노드의 부모들을 저장한 벡터를 비교하며 같은 노드가 있으면 출력하고 반복문 빠져나오기
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T,N;
    cin >> T;
    for (int i=0;i<T;i++){
        cin >> N;
        vector<int> parent(10001,0);
        for (int j=0;j<N-1;j++){
            int a,b;
            cin >> a >> b;
            parent[b] = a;
        }
        
        // 공통 조상 구할 노드 입력받기
        int c,d;
        cin >> c >> d;
        vector<int> v1;
        vector<int> v2;
        
        // 루트까지 찾아가기
        int node = c;
        while (node!=0){
            v1.push_back(node);
            node = parent[node]; // 공통 조상 구할 하나의 노드의 루트 노드 구하기
        }
        node = d;
        while (node!=0){
            v2.push_back(node);
            node = parent[node]; // 공통 조상 구할 하나의 노드의 루트 노드 구하기
        }
        
        // 가장 가까운 공통 조상 찾기
        bool flag = false;
        for (int j=0;j<v1.size();j++){
            if (flag) break;
            for (int k=0;k<v2.size();k++){
                if (v1[j] == v2[k]){
                    cout << v1[j] << '\n';
                    flag = true;
                    break;
                }
            }
        }
    }
}
