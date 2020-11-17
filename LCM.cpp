#include <bits/stdc++.h>
#define MAXN   1000001 
typedef long long ll;
using namespace std;

int spf[MAXN];

ll powmod(ll a,ll b, ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

  

void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)  
        spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) { 

        if (spf[i] == i) { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 

map<int, int> getFactorization(int x) { 
    map<int,int> ret; 
    while (x != 1){ 
        ret[spf[x]]++; 
        x = x / spf[x]; 
    } 
    return ret; 
} 

int main(){
	int t;
	cin>>t;
    sieve();
	while(t--){
		long long n, mod, k, result=1;
		int a;
        map<int,int> m, temp;
		scanf("%lld%lld%lld",&n, &mod, &k);

		for(int i=0; i<n ; i++){
			scanf("%d",&a);
			temp = getFactorization(a);
            for(auto it=temp.begin(); it!=temp.end(); it++){
                if(m[it->first] < it->second)
                    m[it->first] = it->second;
            }
		}
        for(auto it=m.begin(); it!=m.end(); it++){
            result= (result%mod) * powmod(it->first, (it->second)*k, mod);
        }
		printf("%lld\n", result%mod);
	}
	return 0;
}


