#include<bits/stdc++.h>
using namespace std;
int board[1005][1005];
int visited[1005];
int n, m, a, b, cnt;
queue<int> q;

void bfs(int x){
	// 이어져있는 노드들을 탐색하되, 방문한 적이 없는 경우만 탐색한다.
	// 기본 구조는 템플릿이 있으니 다음에는 복붙말고 처음부터 작성할 수 있도록 하자.
	q.push(x);
	visited[x] = 1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 1; i <= n; i++){
			if(board[cur][i] == 1 && visited[i] == 0){
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	while(m--){
		cin >> a >> b;
		board[b][a] = 1;   // board[출발노드][도착노드]
		board[a][b] = 1;   // 이 문제는 방향성이 없는 노드들을 다루기에 [a][b], [b][a] 둘 다 1로 지정하여, 방향성이 없이 연결되어 있음을 표현한다.
	}
	for(int i = 1; i<= n; i++){
		if(visited[i] == 0){ // 모든 노드별로, 방문한 적이 없는 노드일 경우만 bfs 실행
			bfs(i);
			cnt++;  // bfs 함수가 실행된 횟수 == 연결되어 있는 집합의 개수 
			// 방문했을 경우에는 bfs를 실행하지 않으니까, 같은 집합에 속한 것이라고 볼 수 있다.
		}
	}
	cout << cnt;
	return 0;
}
