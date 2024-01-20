#pragma once
#include <stdio.h>

#define dbg(value,TYPE)             \
({	typeof(value) ty;               \
    #if (typeof(value)==TYPE) printf(#value":%d\n",value);    \
})

int main(){
    int kkk=10;
    dbg(kkk,int);
    return 0;
}