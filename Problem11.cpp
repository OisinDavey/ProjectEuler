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

int main(){
    ll a[20][20];
    for(int i=0;i<20;++i)
        for(int j=0;j<20;++j)
            cin >> a[i][j];
    ll maxx = 0;
    for(int i=0;i<17;++i){
        for(int j=0;j<17;++j){
            maxx = max(a[i][j] * a[i+1][j] * a[i+2][j] * a[i+3][j], maxx);
            maxx = max(a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3], maxx);
            maxx = max(a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j+3], maxx);
        }
    }for(int i=0;i<17;++i){
        for(int j=3;j<20;++j){
            maxx = max(maxx, a[i][j] * a[i+1][j-1] * a[i+2][j-2] * a[i+3][j-3]);
        }
    }cout << maxx << endl;
}
