#include <stdio.h>

int main(void){
	while(1){
		//入力
		int n, m; 
		scanf("%d %d", &n, &m);
		if(n==0 && m==0) break;

		int a[1001];
		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
		}

		//処理
		//全ての組み合わせを総当たりでチェックする。
		int ans = -1;
		for(int i=0; i<n-1; i++){
			for(int j=i+1; j<n; j++){
				int sum = a[i] + a[j]; //sumは、i番目の商品の金額と、j番目の商品の金額の和
				if(ans < sum && sum <= m) ans = sum;
			}
		}

		//出力 (改行を忘れないように)
		if(ans == -1){
			printf("NONE\n"); //ansの値が一度も更新されていないので、答えは見つからなかった。 
		} else{
			printf("%d\n", ans);
		}
	}
	return 0;
}