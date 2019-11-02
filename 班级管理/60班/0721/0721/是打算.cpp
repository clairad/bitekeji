#include<cstdio> 
using namespace std;
const int maxN = 2000000;
int q[maxN + 1][2] = { 0 }, n, m, head = 0, tail = 0;
////q[i][0]表示值， q[i][1]表示在原来顺序的位置
int main() {
	scanf("%d%d", &n, &m);
	printf("0\n"); ////第1个数前没有数，输出0
	scanf("%d", &q[tail][0]); //第1个数进队列
	tail++;
	for (int i = 1; i<n; i++) {
		if (i - q[head][1]>m) head++;
		printf("%d\n", q[head][0]); //输出队首元素（最小）
		int x;
		scanf("%d", &x);
		while (tail>head&&x<q[tail - 1][0])
			tail--;
		q[tail][0] = x; q[tail][1] = i; //当前数进队列
		tail++;
	}
	return 0;
}
