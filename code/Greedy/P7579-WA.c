#include <stdio.h>

int x=0,y=0,get=0;

char ask(int start,int mid,int end){
    char ans;
    int i;
    printf("1 %d ",mid-start);
    for (i=start;i<mid;i++){
        printf("%d ",i+1);
    }
    printf("%d ",end-mid);
    for (;i<end;i++){
        printf("%d ",i+1);
    }
    putchar('\n');
    scanf("%c",&ans);
    getchar();
    return ans;
}

char ask_1(int added,int start,int mid,int end){
    char ans;
    int i;
    printf("1 %d ",mid-start+1);
    for (i=start;i<mid;i++){
        printf("%d ",i+1);
    }
    printf("%d %d ",added+1,end-mid);
    for (;i<end;i++){
        printf("%d ",i+1);
    }
    printf("\n");
    scanf("%c",&ans);
    getchar();
    return ans;
}

char ask_2(int added,int start,int mid,int end){
    char ans;
    int i;
    printf("1 %d ",mid-start);
    for (i=start;i<mid;i++){
        printf("%d ",i+1);
    }
    printf("%d ",end-mid+1);
    for (;i<end;i++){
        printf("%d ",i+1);
    }
    printf("%d\n",added+1);
    scanf("%c",&ans);
    getchar();
    return ans;
}

void solve(int start,int end,int want){
    char ans;
    int all=end-start;
    int mid;
    int i;
    if (get==2) return;
    if (all%2==1){
        start++;
        all-=1;
        mid=start+all/2;
        ans=ask(start,mid,end);
        if (ans=='='){
            if (want==2){
                solve(start,mid,1);
                solve(mid,end,1);
            }
            else if (want==1){
                if (get==0) x=start,get++;
                else y=start;
            }
        }else if (ans=='<'){
            if (want==2){
                ans=ask_2(start-1,start,mid,end-1);
                if (ans=='='){
                    x=start;
                    solve(start,mid,1);
                }else if (ans=='<'){
                    solve(start,mid,2);
                }else{
                    printf("Z\n");
                }
            }
            else if (want==1){
                if (get==0) x=start,get++;
                else y=start;
            }
        }else if (ans=='>'){
            if (want==2){
                printf("1st\n");
                ans=ask_1(start-1,start+1,mid,end);
                if (ans=='='){
                    printf("2nd\n");
                    x=start;
                    printf("x:%d\n",x);
                    printf("mid:%d end%d\n",mid,end);
                    solve(mid,end,1);
                }else if (ans=='<'){
                    solve(mid,end,2);
                }
                else{
                    printf("Z\n");
                }
            }
            else if (want==1){
                if (get==0) x=start,get++;
                else y=start;
            }
        }
    }
    else{
        if (all==2){
            printf("3th\n");
            ans=ask(start,mid,end);
            if (get==0){
                if (ans=='>') x=start+1,get++;
                else x=mid,get++;
            }
            else{
                if (ans=='>') y=start+1,get++;
                else y=mid,get++;
            }
        }
        mid=start+all/2;
        ans=ask(start,mid,end);
        if (ans=='='){
            if (want==2){
                solve(start,mid,1);
                solve(mid,end,1);
            }
        }else if (ans=='<'){
            if (want==2){
                solve(start,mid,2);
            }
            else if (want==1){
                solve(start,mid,1);
            }
        }else if (ans=='>'){
            if (want==2){
                solve(mid,end,2);
            }
            else if (want==1){
                solve(mid,end,1);
            }
        }
    }
    printf("get: %d %d\n",x,y);
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    solve(0,n,2);
    printf("2 %d %d\n",x,y);
}