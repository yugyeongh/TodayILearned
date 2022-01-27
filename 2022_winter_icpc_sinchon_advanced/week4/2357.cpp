#include <iostream>
#include <cmath>
#define MAX 1000000001
using namespace std;

int n,m,a,b;
long long *max_tree,*min_tree,arr[100001];

int init(int start,int end,int node,bool flag){
    if (start==end){
        if (flag) return max_tree[node]=arr[start];
        return min_tree[node]=arr[start];
    }
    int mid = (start+end)/2;
    if (flag) return max_tree[node]=max(init(start,mid,node*2,flag),init(mid+1,end,node*2+1,flag));
    return min_tree[node]=min(init(start,mid,node*2,flag),init(mid+1,end,node*2+1,flag));
}

int find(int start,int end,int left,int right,int node,bool flag){
    if(left>end || right<start){
        if (flag) return -MAX;
        return MAX;
    }
    if(left<=start && end<=right){
        if (flag) return max_tree[node];
        return min_tree[node];
    }
    int mid = (start+end)/2;
    if (flag) return max(find(start,mid,left,right,node*2,flag),find(mid+1,end,left,right,node*2+1,flag));
    return min(find(start,mid,left,right,node*2,flag),find(mid+1,end,left,right,node*2+1,flag));
}
               

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    // 배열 사이즈 조정 안 하면 런타임 에러 발생함
    int height = ceil(log2(n));
    min_tree = new long long [1<<(height+1)];
    max_tree = new long long [1<<(height+1)];
    
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    init(0,n-1,1,true);
    init(0,n-1,1,false);
    
    for (int i=0;i<m;i++){
        cin >> a >> b;
        cout << find(0,n-1,a-1,b-1,1,false) << " " << find(0,n-1,a-1,b-1,1,true) << '\n';
    }
    return 0;
}
