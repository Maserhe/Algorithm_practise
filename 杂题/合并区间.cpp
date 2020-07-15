#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int ,int > PII;

vector<PII> segs;

int n;

void merge( vector<PII> & segs){
    
    vector<PII> res;
    
    int st =-2e9, ed = -2e9;
    
    sort(segs.begin(),segs.end());
    
    for( auto seg : segs){
        if(ed < seg.first){
            if(st  != -2e9) res.push_back({seg.first,seg.second});
            
            st =seg.first;
            ed =seg.second;
            
        }
        else{
            
            ed = max(ed,seg.second);
        }
        
    }
    
    if(st != -2e9) res.push_back({st,ed});
    
    segs= res;
    
}

int main(){
    
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        int l , r;
        cin >>l>>r;
        
        segs.push_back({l,r});
    }
    
    merge(segs);
    
    cout<<segs.size();

    
     system("pause");                               
    return 0;
}