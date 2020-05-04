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

vector<int> primes;

bool sieve[2000001];

ll trinum(ll n){
    return (n*n + n)/2;
}

int num_factors(ll n){
    vector<int> primepowers;
    for(int i=0;i<primes.size();++i){
        if(n%primes[i]==0)
            primepowers.push_back(0);
        while(n%primes[i]==0){
            primepowers[primepowers.size()-1]++;
            n/=primes[i];
        }
    }int total = 1;
    for(int x : primepowers){
        total *= (x+1);
    }return total;
}

int main(){
    for(int i=2;i<2000001;++i)
        if(!sieve[i])
            for(int j=i+i;j<2000001;j+=i)
                sieve[j] = 1;
    for(int i=2;i<2000001;++i)
        if(!sieve[i])
            primes.push_back(i);
    cout << "Done Computing Primes!\n";
    int maxx = 1;
    for(int i=1;1;++i){
        int N = num_factors(trinum(i));
        if(N > maxx){
            cout << N << endl;
            maxx = N;
        }
        if(N >= 500){
            cout << trinum(i) << endl;
            return 0;
        }
    }
}
