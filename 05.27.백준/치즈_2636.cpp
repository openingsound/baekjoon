//#include<iostream>
//using namespace std;
//
//int arr[102][102];
//int vis[102][102];
//int airche[102][102];
//int dy[4] = { 0,0,1,-1 };
//int dx[4] = { 1,-1,0,0 };
//
//struct Node
//{
//	int y;
//	int x;
//	int cou;
//	Node* next;
//	Node* pre;
//};
//
//Node nodes[20004];
//int cou = 0;
//
//struct Queue {
//	Node head;
//	Node tail;
//	int size = 0;
//};
//Queue q;
//
//Node* AddNode(int y, int x) {
//	Node* ret = &nodes[cou];
//	nodes[cou] = { y,x };
//	cou++;
//	return ret;
//}
//void AddQueue(Node* n) {
//	n->next = &q.tail;
//	n->pre = q.tail.pre;
//	n->next->pre = n;
//	n->pre->next = n;
//	q.size++;
//}
//Node* PopeQueue() {//q.size가 1이상인거 체크하기
//	Node* ret = q.head.next;
//	ret->next->pre = &q.head;
//	q.head.next = ret->next;
//	q.size--;
//	return ret;
//}
//int y, x;
//
//void dfs(int yy, int xx) {
//	vis[yy][xx] = 1;
//	for (int i = 0; i < 4; i++) {
//		int ty = yy + dy[i];
//		int tx = xx + dx[i];
//		if (ty >= 1 && ty <= y && tx >= 1 && tx <= x && arr[ty][tx] == 0 && vis[ty][tx] == 0) {
//			dfs(ty, tx);
//		}
//		else if (ty >= 1 && ty <= y && tx >= 1 && tx <= x && arr[ty][tx] == 1 && vis[ty][tx] == 0) {
//			AddQueue(AddNode(ty, tx)), vis[ty][tx] = 1;;
//		}
//		
//	}
//}
//void dfs2(int yy, int xx) {
//	vis[yy][xx] = 1;
//	for (int i = 0; i < 4; i++) {
//		int ty = yy + dy[i];
//		int tx = xx + dx[i];
//		if (ty >= 1 && ty <= y && tx >= 1 && tx <= x && vis[ty][tx] == 0) {
//			if (arr[ty][tx] == 0) {
//				dfs(ty, tx);
//			}
//			else if (arr[ty][tx] == 1) {
//				AddQueue(AddNode(ty, tx)), vis[ty][tx] = 1;;
//			}
//		}
//	}
//}
//int main() {
//	q.head.next = &q.tail;
//	q.tail.pre = &q.head;
//	
//	cin >> y >> x;
//	for (int i = 1; i <= y; i++) {
//		for (int j = 1; j <= x; j++) {
//			cin >> arr[i][j];
//		}
//	}
//	dfs(1, 1);
//
//	int ans2 = q.size;
//	for (int i = 1; i <= 100; i++) {
//		if (q.size == 0) {
//			cout << i -1<< '\n' << ans2;
//			return 0;
//		}
//		ans2 = q.size;
//		int cyclen = q.size;
//		for (int j = 1; j <= cyclen; j++) {
//			if (q.size == 0)break;
//			Node *tem = PopeQueue();
//			for (int t = 0; t < 4; t++) {
//				int ty = tem->y + dy[t];
//				int tx = tem->x + dx[t];
//				if (vis[ty][tx]==0 && arr[ty][tx] == 1) {
//					AddQueue(AddNode(ty, tx));
//					vis[ty][tx] = 1;
//				}
//				if (vis[ty][tx] == 0 && arr[ty][tx] == 0) {
//					dfs2(ty, tx);
//				}
//			}
//		}
//	}
//}