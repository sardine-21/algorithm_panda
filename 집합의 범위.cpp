#include <algorithm>
#include<iostream>
#include<vector>

/* �̹����� �ٽ���? - ���� ���� ���踦 ���� �������� ǥ���� �� �ִٴ� ���� ���ݴ� ��. 
 ������ ������ ���������� ���� Ʈ���� ����, �� ���� ��Ʈ�� ������ �Ǿ����� Ȯ���� �� �ִٴ� ���� ������ ȹ������ ���̵���̴�.
���� ���� Ʈ�� ��  Ȯ�� �ڷᱸ���� �ͼ����� �ʾƼ� ���ø����� ���� ��.
�׷���? ������ �˸�  ������ ����.

*/

using namespace std;
int n, m;
int parent[1000001];

int getParent(int x) { // ��Ʈ�� Ȯ���ϴ� �Լ� 
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}
void unionParent(int a, int b) { // ���� ��Ʈ�� �������ֱ� ���� �Լ� 
    a = getParent(a);
    b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}
void findParent(int a, int b) { // ���Ұ� ���� ��Ʈ�� ���ϴ� �Լ� 
    a = getParent(a);
    b = getParent(b);
    if (a == b) cout << "YES\n";
    else cout << "NO\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m; // ���� 
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if (!o) {// union����
            unionParent(a, b);
        }
        else { //find����
            findParent(a, b);
        }

    }

    return 0;
}
