#include <bits/stdc++.h>
using namespace std;

bool ok(vector<int>& a,int m,int x){
    long long o=0;
    for(int v:a) o+=(v-1)/x;
    return o<=m;
}

int main(){
    int n,m;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>m;

    int l=1,r=*max_element(a.begin(),a.end()),ans=r;

    while(l<=r){
        int mid=(l+r)/2;
        if(ok(a,m,mid)){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }

    cout<<ans;
}