#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n;

    vector<long long>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    cin>>k;

    const long long mod=1e9+7;
    vector<long long> c(32);

    for(long long v:a){
        for(int j=0;j<32;j++){
            if(v&(1LL<<j)) c[j]++;
        }
    }

    long long ans=0;

    for(int i=0;i<k;i++){
        long long x=0;
        for(int j=0;j<32;j++){
            if(c[j]){
                x|=(1LL<<j);
                c[j]--;
            }
        }
        ans=(ans+(x*x)%mod)%mod;
    }

    cout<<ans;
}