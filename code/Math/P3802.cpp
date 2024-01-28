#include <cstdio>
double a[7],sum,ans=1;
int main(){
    for (int i=0;i<7;i++){
        scanf("%lf",a+i);
        sum+=a[i];
    }
    if (sum<7.){
        printf("0.000");
        return 0;
    }
    for(int i=0;i<7;i++) ans=(ans*a[i])/(sum-i);
    printf("%.3lf\n",ans*7*6*5*4*3*2*1*(sum-6));
    return 0;
}