#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[1010][1010];
char s1[100010],s2[100010],ans[1000010];

int main(){
	int i,j;
    scanf("%s%s",s1+1,s2+1);
	int len1=strlen(s1+1), len2=strlen(s2+1);
	dp[0][0]=0;
	for(i=1;i<=len1;i++){
		for(j=1;j<=len2;j++){
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if(s1[i] == s2[j])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
		}
	}
	i=len1,j=len2;
	while(dp[i][j]>0){
		if(s1[i]==s2[j]){
            ans[dp[i][j]] = s1[i];
            i--,j--;
        }
		else{
			if(dp[i][j]==dp[i-1][j]) i--;
			else j--;
		}
	}
	printf("%s",ans+1);
    return 0;
}