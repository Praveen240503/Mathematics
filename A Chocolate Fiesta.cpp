#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
ll power(ll a, ll b){
        
    ll ans = 1;
    while(b){
        if(b&1){
            ans =((ans % mod)* ( a % mod))% mod;
            
        }
        a = ((a % mod)  *  ( a % mod))  % mod;
        
        b >>= 1;
    }
    return ans % mod;
}
ll inverse ( ll a, ll b){
    return power(a,b);
}
int main(){
    ll n;
    cin>> n ;
    vector<int>ar(n);
    ll o_odd=0, o_eve=0, od_ev=0;
    ll eve=0;
    ll odd=0;
    
    
    for(int i=0;i<n;i++){
        cin>>ar[i];
        if(ar[i]&1)odd++;
        else eve++;
    }
    // cout<<odd<<eve;
    // cout<<power(2,0);
    if(odd!=0){
        o_odd=(power(2,odd) % mod)* (inverse(2,mod-2) % mod ) % mod ;
        //o_odd=(power(2,odd-1)%mod;
        o_odd--;
    }
    // cout<<o_odd;
    if(eve!=0){
        o_eve=power(2,eve) % mod;
        o_eve--;
    }
    if(eve!=0 and odd!=0)od_ev  = ((o_odd % mod ) * (o_eve % mod)) % mod;
    cout<<(od_ev + o_odd + o_eve) % mod<<"\n";
}
