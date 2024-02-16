#include <stdio.h>
#define MAXN 100005
int heap_ori_1[MAXN];
int heap_ori_2[MAXN];

/*similar to patience sort*/

int insert;

int checkl(const void *x){
    return (*(int*)x)<insert;
}

int checkr(const void *x){
    return (*(int*)x)>=insert;
}

void* left_aviliable(void *start,unsigned long total_elem,unsigned long size,int (*check)(const void *)){
    start-=size;
    void *end=start+(total_elem)*size,*mid=start+(total_elem/2)*size;
    while (start+size<end){
        if (check(mid)) end=mid;
        else start=mid;
        mid=start+((end-start)/(size*2))*size;
    }
    return end;
}

int main(){
    freopen("../../data/P1020_3.in","r",stdin);
    heap_ori_1[0]=MAXN,
    heap_ori_2[0]=0;
    int *heap_1=heap_ori_1+1,
        *heap_2=heap_ori_2+1;
    int ipt,res1=0,res2=0;
    while (~scanf("%d",&ipt)){
        if (ipt<=heap_1[res1-1]){
            heap_1[res1++]=ipt;
        }else{
            insert=ipt;
            int* pos=left_aviliable(heap_1,res1,sizeof(int),checkl);
            *pos=ipt;
        }
        if (ipt>heap_2[res2-1]){
            heap_2[res2++]=ipt;
        }else{
            insert=ipt;
            int* pos=left_aviliable(heap_2,res2,sizeof(int),checkr);
            *pos=ipt;
        }
    }
    printf("%d\n%d\n",res1,res2);
}
