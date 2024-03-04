#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
const int MAXN=100001;


typedef struct book{
    char read;vector<struct book*> list;
}book;

bool cmp(book* a,book* b){
    return a<b;
}

book all[MAXN]={0};

void dfs(book *b){
    if (b->read) return;
    printf("%ld ",(b-all));
    b->read=1;
    for (auto i=b->list.begin();i!=b->list.end();i++) dfs(*i);
}


void bfs(book *x){
    book* q[MAXN];
	q[0]=x;
    printf("%ld ",x-all);
    x->read=0;
    int i=0,j=1;
	while(i<j){
		x=q[i];
        for (auto ref=x->list.begin(); ref!=x->list.end(); ++ref){
            book* reference=*ref;
			if(reference->read==1){
                q[j++]=reference;
                printf("%ld ",reference-all);
                reference->read=0;
            }
        }
        i++;
	}
}


void bfs2(book *x){ 
	queue <book*> q; 
	q.push(x);  
	printf("%ld ",x-all);
	x->read=0;
	while(!q.empty()){ 
		book* fro=q.front(); 
		for (auto ref=fro->list.begin(); ref!=fro->list.end(); ++ref){
            book* reference=*ref;
			if(reference->read==1){
				q.push(reference); 
				printf("%ld ",reference-all);
				reference->read=0;
			}
		}
		q.pop(); 
	}
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int x,y;
    for (int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        all[x].list.push_back(&all[y]);
    }
    for (int i=1;i<=n;i++){
        sort(all[i].list.begin(),all[i].list.end(),cmp);
    }
    dfs(&all[1]);putchar('\n');
    bfs(&all[1]);putchar('\n');
    return 0;
}