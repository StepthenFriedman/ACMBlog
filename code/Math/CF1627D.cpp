#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+2;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int bucket[MAX]={0};
int arr[MAX];

int main(){
    int n,i,j,maxx=0,ans=0;
    cin>>n;
    for (i=0;i<n;i++){
        cin>>arr[i];
        bucket[arr[i]]=1;
        maxx=max(maxx,arr[i]);
    }
    for(i=1;i<=maxx;++i){
		if(bucket[i]!=0) continue;
		int commongcd=0;
		for(j=i;j<=maxx;j+=i){
			if(bucket[j]!=0) commongcd=gcd(commongcd,j);
		}
		if(commongcd==i) ans++;
	}
    cout<<ans<<endl;
    return 0;
}