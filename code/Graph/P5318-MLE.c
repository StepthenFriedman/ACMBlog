#include <stdio.h>
#include <stdlib.h>
#define MAXN 100001

/*MLE is caused by the wrong implement of bfs.*/

typedef struct book{
    int len;char read;struct book **list;
}book;

int cmp(const void *a,const void *b){
    return *((book**)a)-*((book**)b);
}

book all[MAXN]={0};

void dfs(book *b){
    if (b->read) return;
    printf("%ld ",(b-all));
    b->read=1;
    for (int i=0;i<b->len;i++) dfs(b->list[i]);
}

void bfs(book *b){
    for (int i=0;i<b->len;i++){
        if (!b->list[i]->read) continue;
        printf("%ld ",(b->list[i]-all));
        b->list[i]->read=0;
    }
    for (int i=0;i<b->len;i++){
        bfs(b->list[i]);
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        all[i].list=(book**)malloc(sizeof(book*)*50);
    }
    int x,y;
    for (int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        all[x].list[all[x].len++]=&all[y];
    }
    for (int i=1;i<=n;i++){
        qsort(all[i].list,all[i].len,sizeof(book**),cmp);
    }
    dfs(&all[1]);putchar('\n');
    printf("1 ");bfs(&all[1]);putchar('\n');
    for (int i=1;i<=n;i++){
        free(all[i].list);
    }
    return 0;
}