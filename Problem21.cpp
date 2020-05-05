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

int D [10000];

int main(){
    for(int i=1;i<10000;++i){
        int count = 1;
        for(int j=2;j<=sqrt(i);++j){
            if(j==sqrt(i)){
                count +=j;
                break;
            }if(i%j==0){
                count += j;
                count += i/j;
            }
        }D[i] = count;
    }vector<int> ans;
    int count = 0;
    for(int i=1;i<10000;++i){
        if(D[i]<10000){
            if(i==D[D[i]] && i!=D[i]){
                ans.push_back(i);
                count += i;
                cout << i << ' ' << D[i] << endl;
            }
        }
    }cout << count << endl;
}
