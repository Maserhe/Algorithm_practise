#include<iostream>

using namespace std;

int main(){

    int a= 100000;
    int m=0;
    for(int i = 31 ; i >=0 ; i -- ){
        m= a>>i&1;
        
        cout<<m<<i<<endl;
    }

    system("pause");
    return 0;
}