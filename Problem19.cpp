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
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int c = 0, D = 1;
    for(int i=1901;i<2001;++i){
        bool Leap;
        if(i%400==0)
            Leap = 1;
        else if(i%100==0)
            Leap = 0;
        else if(i%4==0)
            Leap = 1;
        else
            Leap = 0;
        for(int j=0;j<12;++j){
            c += (D == 6);
            D += days[j];
            D += (j==1 && Leap);
            D %= 7;
        }
    }cout << c << endl;
}


