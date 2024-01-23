#include<stdio.h>
#define maxn 11000002
#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) (x)>(y)?(x):(y)

char data[maxn<<1];
int p[maxn<<1]={0},
    left[maxn<<1]={0},
    p2[maxn<<1]={0},
    newp[maxn<<1]={0},
cnt,ans;
void qr(){
    cnt=1;
    char c=getchar();
    data[0]='~',data[1]='|';
    while(c<'a'||c>'z') c=getchar();
    while(c>='a'&&c<='z') data[++cnt]=c,data[++cnt]='|',c=getchar();
}
int main(){
    qr();
    int i,j,rightmost=0,mid=0,ans=0;
    for (i=1;i<=cnt;i++){
        if (mid<i&&i<rightmost){
            p[i]=min(rightmost-i+1,p[mid*2-i]);
        }else p[i]=0;
        for (;data[i-p[i]]==data[i+p[i]];p[i]++);
        p[i]--;
        for (j=1;j<=p[i];j++)
            left[i-j]=max(left[i-j],j);
        if (p[i]+i>rightmost) rightmost=p[i]+i,mid=i;
    }
    rightmost=0,mid=0;
    int start;
    for (i=1;i<=cnt;i++) if (p[i]>0) {
        if (mid<i&&i<rightmost){
            start=rightmost-i;
        }else start=1;
        for (j=start;j<=p[i];j++) if (left[i+j]) {
            p2[i]=max(p2[i],j+left[i+j]);
        }
        if (p[i]+i>rightmost) rightmost=p[i]+i,mid=i;
        ans=max(ans,p2[i]);
    }
    printf("%d\n",ans);
    return 0;
}