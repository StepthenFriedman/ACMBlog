#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const double zero=0.00000001;
double arr[110][110];
double res[110]={0};
int main(){
    int n,i,j,k;
    cin>>n;
    for (i=0;i<n;i++){
        for (j=0;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for (i=0;i<n-1;i++){
        //delete the ith element
        for (j=i+1;j<n;j++){
            //each statement
            double rate=arr[i][i]/arr[j][i];
            for (k=i+1;k<=n;k++){
                //each element
                arr[j][k]*=rate;
                arr[j][k]-=arr[i][k];
            }
        }
    }
    for (i=n-1;i>-1;i--){
        if (abs(arr[i][i])<zero){
            cout<<"No Solution\n";
            return 0;
        }else{
            for (j=n-1;j>i;j--) arr[i][n]-=res[j]*arr[i][j];
            res[i]=arr[i][n]/arr[i][i];
        }
    }
    for (i=0;i<n;i++) printf("%.2f\n",res[i]);
    return 0;
}