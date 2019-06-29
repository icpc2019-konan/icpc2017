#include <stdio.h>
#include <string.h>

int main(void) {
	while(1) {
		//入力
		char str1[201], str2[201];// 問題文ではs1,s2となっています。
		scanf("%s", str1);
		if(str1[0] == '.' && str1[1] == '\0') break;
		scanf("%s", str2);

		//処理
		if(strcmp(str1, str2) == 0){
			printf("IDENTICAL\n"); //2つの文字列は完全に一致したなら、IDENTICALを出力。
			continue;
		}

		bool inQuotes = false; //二重引用府(")の中ならtrue,外ならfalse
		int i=0, j=0;
		int diffCount=0;//文字列定数(奇数番目の二重引用符とその次の二重引用符の間の文字の並び)がstr1とstr2とで異なってる数。
		while(str1[i] != '\0' || str2[j] != '\0') {
			if(str1[i] != str2[j]) {
				if(inQuotes == false) {
					diffCount = 2;//二重引用符の外で異なっている場合は、その時点でDIFFERENT。
					break;
				} else{
					diffCount++;
					if(diffCount == 2) break;
					//str1,str2共に、二重引用符(")のところまで、進める。
					while(str1[i] != '"') i++;
					while(str2[j] != '"') j++;
					inQuotes = false;
				}
			} else if(str1[i] == '"' && str2[j] == '"') {
				inQuotes = !inQuotes;//trueならfalseに、falseならtureにする。
			}
			i++; j++;
		}

		//出力
		if(diffCount == 1){
			printf("CLOSE\n");
		} else{
			printf("DIFFERENT\n");
		}
	}
	return 0;
}