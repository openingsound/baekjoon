#include<iostream>
using namespace std;

int arr[4][4002];
int tem[16000005];
int arr2[2][16000005];



void mergesort(int start, int end, int num) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(start, mid, num);
		mergesort(mid + 1, end, num);
		int i = start;
		int j = mid + 1;
		int k = start;
		while (i <= mid && j <= end) {
			if (arr2[num][i] < arr2[num][j]) {
				tem[k] = arr2[num][i];
				i++;
			}
			else {
				tem[k] = arr2[num][j];
				j++;
			}
			k++;
		}
		while (i <= mid) {
			tem[k++] = arr2[num][i++];
		}
		while (j <= end) {
			tem[k++] = arr2[num][j++];
		}
		for (int t = start; t <= end; t++) {
			arr2[num][t] = tem[t];
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[j][i];
		}
	}
	int cou = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr2[0][cou] = arr[0][i] + arr[1][j];
			arr2[1][cou] = arr[2][i] + arr[3][j];
			cou++;
		}
	}
	mergesort(0, cou - 1, 1);
	long long ans = 0;
	for (int i = 0; i < cou; i++) {
		int num = arr2[0][i];//찾는 숫자
		int l = 0;
		int r = cou - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (arr2[1][mid] >= -num)
				r = mid - 1;
			else
				l = mid + 1;
		}
		ans -= r;
		l = 0;
		r = cou - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (arr2[1][mid] > -num)
				r = mid - 1;
			else
				l = mid + 1;
		}
		ans += r;
	}
	cout << ans;
}