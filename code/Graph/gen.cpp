#include <cstdio>
#include <cstdlib>
#include <ctime>
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)

int n=100000,m=2000000;

int main(){
	srand(time(0));
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++) printf("%d ",(rand()%100000000)+1);
	putchar('\n');
	for(int i=1;i<=m;i++) {
		int x=rand()%n+1,y=rand()%n+1;
		printf("%d %d\n",min(x,y),max(x,y));
	}
}
