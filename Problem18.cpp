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

ll maxx[200][200];

int main(){
    int n;
    cin >> n;
    int a[n][n];
    for(int i=0;i<n;++i)
        for(int j=0;j<=i;++j)
            cin >> a[i][j];
    for(int j=0;j<n;++j)
        maxx[n-1][j] = a[n-1][j];
    for(int i=n-2;i>=0;--i)
        for(int j=0;j<=i;++j)
            maxx[i][j] = a[i][j] + max(maxx[i+1][j], maxx[i+1][j+1]);
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j)
            cout << maxx[i][j] << ' ';
        cout << endl;
    }
}
