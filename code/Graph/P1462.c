#include <stdio.h>
#include <stdbool.h>
#define INF 1000000001
#define M 100001
#define N 10001
#define r(i,a,b) for (int i=a;i<=b;i++)
int n,m,k,x,y,t,u,z,tot,team[N],head=0,tail=1,d,f[N],p,l,r,mid,b[N];
int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}
long long dis[N];bool v[N];
struct node{int next,to,v;}a[M];
void add(int u,int v,int w)
{
    a[++tot].next=f[u];
    a[tot].to=v;
    a[tot].v=w;
    f[u]=tot;
}
void write(int x)
{
    if (x<0) {putchar('-');x=-x;}
    if (!x) {putchar(48);return;}
    if (!(x/10)){putchar(x%10+48);return;}
    write(x/10);putchar(x%10+48);
}
bool spfa(int wh)
{
    if (b[1]>wh) return false;
    r(i,1,n) dis[i]=INF;
    head=0;team[1]=1;tail=v[1]=true;dis[1]=0;
    while(head!=tail)
     {
        head=head%N+1;
        u=team[head];v[u]=true;t=f[u];
        while(t)
         {
            if (dis[u]+a[t].v<dis[a[t].to])
             {
                  dis[a[t].to]=dis[u]+a[t].v;
                   if (!v[a[t].to]&&b[a[t].to]<=wh)
                    {
                         tail=tail%N+1;
                         team[tail]=a[t].to;//入队
                         v[a[t].to]=1;//标记
                     }
             }
            t=a[t].next;
         }
         v[u]=false;
     }
     if(dis[n]<k) return true;//满足要求
     return false;//否则
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    r(i,1,n) 
     {scanf("%d",b+i);r=max(b[i],r);}//r就是所有费用中的最大值
    l=max(b[1],b[n]);//第一个和最后一个的最大值
    r(i,1,m)
    {
        scanf("%d%d%d",&x,&y,&z);if (x==y) continue;
        add(x,y,z);
        add(y,x,z);//双向
    }
    if (!spfa(INF)) {printf("AFK");return 0;}//特判
    while(r-l+1)//相当于l<=r，然而这并没有什么卵用
    {
        int mid=(l+r)>>1;//二分
        if (spfa(mid)) r=mid-1;else l=mid+1;
    }
    printf("%d",l);//输出
}