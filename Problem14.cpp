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

ll collatzLength[2000000];

ll FCollatzLength(ll n){
    if(n >= 2000000){
        if(n%2==0)
            return FCollatzLength(n/2) + 1;
        else
            return FCollatzLength(3*n + 1) + 1;
    }else{
        if(collatzLength[n] != 0){
            return collatzLength[n];
        }else{
            if(n%2==0)
                return collatzLength[n] = FCollatzLength(n/2) + 1;
            else
                return collatzLength[n] = FCollatzLength(3*n + 1) + 1;
        }
    }
}

int main(){
    collatzLength[1] = 1;
    ll maxx = 0;
    ll maxnum = 1;
    for(int i=2;i<1000000;++i){
        if(FCollatzLength(i) > maxx){
            maxx = FCollatzLength(i);
            maxnum = i;
        }
    }cout << maxnum << ' ' << maxx << endl;
}
