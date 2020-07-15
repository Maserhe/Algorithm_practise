#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

const int N =1e4+10;
char l[N],s[N];
int ne[N];
int n, m ;

int main(){
    
    scanf("%s%s",l+1,s+1);
    int len_l= strlen(l + 1);
    
    int len_s= strlen(s + 1);
    //求ne[j]
    
    for(int i = 2, j = 0; i <= len_s ; i ++ ){
        while( j  && s[i] != s[ j + 1] ) j = ne[j];
        
        if( s[i] == s[ j + 1 ]) j++;
        ne[i] = j ;
        
    }
    
    for(int i = 1 , j = 0 ; i <= len_l ; i ++ ){
        while( j  && l[i] != s[ j + 1 ]) j = ne[j] ;
        if(l[i] == s[ j + 1]) j++;
        if(j == len_s ) printf("%d ",i - len_s + 1), j = ne[j] ;
        
    }
    
    
    cout<<endl;
    for(int i = 1 ; i <= len_s; i ++ ) printf("%d ", ne[i]);
    
    system("pause");
    return 0;
}