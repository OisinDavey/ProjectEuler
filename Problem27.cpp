#include<bits/stdc++.h> 
#define MX_N 5001
#define INF 100000000

#define mod7 1000000007

typedef long long int ll;
typedef unsigned long long int ull;

ll gcd(ull a, ull b){return (a==0)?b:gcd(b%a,a);}
ll lcm(ull a, ull b){return a*(b/gcd(a,b));}

int kx[8] = {+2,+2,-2,-2,+1,+1,-1,-1};
int ky[8] = {+1,-1,+1,-1,+2,-2,+2,-2};
int d9x[9] = {+1,+1,+1,+0,+0,+0,-1,-1,-1};
int d9y[9] = {+1,+0,-1,+1,+0,-1,+1,+0,-1};
int dx4[4] = {0, 0, +1, -1};
int dy4[4] = {+1, -1, 0, 0};

using namespace std;

bool sieve [2000000];
vector<ll> primes;

void fill_sieve(){
    for(int i=2;i<2000000;++i)
        if(sieve[i] == false)
            for(int j=i+i;j<2000000;j+=i)
                sieve[j] = true;
    sieve[1] = true;
    sieve[0] = true;
    for(int i=0;i<2000000;++i)
        if(sieve[i] == false)
            primes.push_back((long long int)i);
}

ll num_primes(int a, int b){
    for(int i=0;1;++i){
        ll N = i*i + a*i + b;
        if(N < 0)
            return i;
        if(sieve[N])
            return i;
    }
}

int main(){
    fill_sieve();
    pair<int, int> best = {0, 0};
    ll maxx = 0;
    int b = 0;
    cout << primes[0] << endl;
    for(b=0;primes[b]<=1000;++b){
        if(primes[b]%2==0){
            for(int a=-998;a<1000;a+=2){
                ll temp = num_primes(a, primes[b]);
                if(temp > maxx){
                    best = {a, primes[b]};
                    maxx = temp;
                }
            }
        }else{
            for(int a=-999;a<1000;a+=2){
                ll temp = num_primes(a, primes[b]);
                if(temp > maxx){
                    best = {a, primes[b]};
                    maxx = temp;
                }
            }
        }
    }cout << best.first << ' ' << best.second << endl << maxx << endl;
    cout << sieve[1601] << endl;
}
