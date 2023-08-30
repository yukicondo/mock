#include<stdio.h>

int main(void) {
	int h, w;
	int i, j;
	int toudo_table[200][200];
	int line_toudo;
	int left_toudo;

	scanf("%d %d\n", &h, &w);

	for(i=0;i<h;i++) {
		line_toudo = 0;
		for(j=0;j<w;j++) {
			scanf("%d", &toudo[i][j]);
			line_toudo += toudo[i][j];
		}
		scanf("\n");

		if(line_toudo % 2 == 1) {
			// 奇数になっているので、分割自体無理
			printf("No\n");
			return 0;
		}

		left_toudo = 0;
		for(j=0;j<w;j++) {
			left_toudo += toudo[i][j];
			if(left_toudo == line_toudo / 2) {
				// 分割成功
				break;
			}

			if(left_toudo > line_toudo / 2) {
				// 左側が大きくなった時点で、すでに分割不可
				printf("No\n");
				return 0;
			}		
		}

		// ループをそのまま抜けた場合は、左側のほうが小さいことになるので終了
		if(j == w) {
			printf("No\n");
		}
	}

	// 全部クリアした場合、分割成功
	printf("Yes\n");

	return 0;
}