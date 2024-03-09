#include <algorithm>
#include<iostream>
#include<vector>

/* 이문제의 핵심은? - 집합 간의 관계를 노드와 간선으로 표현할 수 있다는 점을 깨닫는 것. 
 합집합 연산을 시행했음이 같은 트리에 속함, 즉 같은 루트를 가지게 되었음을 확인할 수 있다는 것은 굉장히 획기적인 아이디어이다.
역시 아직 트리 등  확장 자료구조에 익숙하지 않아서 떠올리지를 못한 듯.
그러나? 구조를 알면  구현이 쉽다.

*/

using namespace std;
int n, m;
int parent[1000001];

int getParent(int x) { // 루트를 확인하는 함수 
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}
void unionParent(int a, int b) { // 같은 루트로 통일해주기 위한 함수 
    a = getParent(a);
    b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}
void findParent(int a, int b) { // 원소가 속한 루트를 비교하는 함수 
    a = getParent(a);
    b = getParent(b);
    if (a == b) cout << "YES\n";
    else cout << "NO\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m; // 대입 
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if (!o) {// union연산
            unionParent(a, b);
        }
        else { //find연산
            findParent(a, b);
        }

    }

    return 0;
}
