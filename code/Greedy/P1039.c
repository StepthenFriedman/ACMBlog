#include <stdio.h>
#include <string.h>
#define MAXM 20
#define MAXN 20
#define MAXP 100

#define Meaningless 0
#define Guilty 1
#define NotGuilty 2
#define Day 3

int m,n,p;

char temp[260];
char tempname[50];
char guilty[]="I am guilty.";
char not_guilty[]="I am not guilty.";
char xxx_is_guilty[]="is guilty.";
char xxx_is_not_guilty[]="is not guilty.";
char today_is_xxx[]="Today is";

char days[7][20]={  "Today is Monday.",
                    "Today is Tuesday.",
                    "Today is Wednesday.",
                    "Today is Thursday.",
                    "Today is Friday.",
                    "Today is Saturday.",
                    "Today is Sunday."};

char names[MAXM][50];
int is_liar[MAXM]={0};

typedef struct state{
    int who,type,object;
}state;

state statement[MAXP];

int startsWith(const char *pre, const char *str){
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? 0 : memcmp(pre, str, lenpre) == 0;
}

int endsWith(const char *str, const char *suffix){
    if (!str || !suffix)
        return 0;
    size_t lenstr = strlen(str);
    size_t lensuffix = strlen(suffix);
    if (lensuffix >  lenstr)
        return 0;
    return strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0;
}

int match_day(char *day){
    for (int i=0;i<7;i++){
        if (!strcmp(day,days[i])) return i;
    }
    return -1;
}

int find_name(char *name){
    for (int i=0;i<m;i++){
        if (!strcmp(name,names[i])) return i;
    }
    return -1;
}

int main(){
    int i;
    freopen("../../data/P1039_1.in","r",stdin);
    scanf("%d%d%d",&m,&n,&p);
    for (i=0;i<m;i++) {
        scanf("%s",names[i]);
    }
    for (i=0;i<p;i++){
        scanf("%s",tempname);
        getchar();
        fgets(temp,260,stdin);
        tempname[strlen(tempname)-1]='\0';
        int len=strlen(temp);
        if (temp[len-1]=='\n') temp[--len]='\0';
        if (temp[len-1]=='\r') temp[--len]='\0';

        statement[i].who=find_name(tempname);

        if (startsWith(today_is_xxx,temp)){
            statement[i].type=Day;
            statement[i].object=match_day(temp);
            if (statement[i].object==-1) statement[i].type=Meaningless;

        }else if (!strcmp(guilty,temp)){
            statement[i].type=Guilty;
            statement[i].object=statement[i].who;
        }
        else if (!strcmp(not_guilty,temp)){
            statement[i].type=NotGuilty;
            statement[i].object=statement[i].who;
        }
        else if (endsWith(temp,xxx_is_guilty)) {
            statement[i].type=Guilty;
            sscanf(temp,"%s",tempname);
            statement[i].object=find_name(tempname);
            if (statement[i].object==-1) statement[i].type=Meaningless;
        }
        else if (endsWith(temp,xxx_is_not_guilty)) {
            statement[i].type=NotGuilty;
            sscanf(temp,"%s",tempname);
            statement[i].object=find_name(tempname);
            if (statement[i].object==-1) statement[i].type=Meaningless;

        }else statement[i].type=Meaningless;
    }
    int criminal=-1;
    for (int d=0;d<7;d++) for (int crim=0;crim<m;crim++){
        memset(is_liar,0,sizeof(int)*MAXM);
        //printf("iterate: day:%d crimminal:%d\n",d,crim);
        for (i=0;i<p;i++){
            //printf("who:%d type:%d obj:%d\n",statement[i].who,statement[i].type,statement[i].object);
            if (statement[i].type==Day){
                if (statement[i].object!=d){
                    if (is_liar[statement[i].who]==-1) goto next;
                    is_liar[statement[i].who]=1;
                    //printf("1\n");
                }
                else if (statement[i].object==d){
                    if (is_liar[statement[i].who]==1) goto next;
                    is_liar[statement[i].who]=-1;
                    //printf("2\n");
                }
            }
            else if (statement[i].type==Guilty){
                if (statement[i].object!=crim){
                    if (is_liar[statement[i].who]==-1) goto next;
                    is_liar[statement[i].who]=1;
                    //printf("3\n");
                }
                else if (statement[i].object==crim){
                    if (is_liar[statement[i].who]==1) goto next;
                    is_liar[statement[i].who]=-1;
                    //printf("4\n");
                }
            }
            else if (statement[i].type==NotGuilty){
                if (statement[i].object==crim){
                    if (is_liar[statement[i].who]==-1) goto next;
                    is_liar[statement[i].who]=1;
                    //printf("5\n");
                }
                else if (statement[i].object!=crim){
                    if (is_liar[statement[i].who]==1) goto next;
                    is_liar[statement[i].who]=-1;
                    //printf("6\n");
                }
            }
            //for (int ii=0;ii<m;ii++) printf("%d ",is_liar[ii]); putchar('\n');
        }
        int liar_count=0,meaningless_count=0;
        for (i=0;i<m;i++){
            if (is_liar[i]==1) liar_count++;
            else if (is_liar[i]==0) meaningless_count++;
        }
        if (n>=liar_count&&n<=liar_count+meaningless_count){
            //printf("passed!\n");
            if (criminal!=-1 && criminal!=crim){
                printf("Cannot Determine\n");
                return 0;
            }else criminal=crim;
        }
        next:;
    }
    if (criminal==-1) printf("Impossible\n");
    else printf("%s\n",names[criminal]);
    return 0;
}