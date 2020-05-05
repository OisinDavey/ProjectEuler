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

vector<int> Facts = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

vector<int> perm(int n, int k){
    vector<int> quotients;
    for(int i=0;i<k;++i){
        quotients.push_back(n%(i+1));
        n/=(i+1);
    }for(int i=0;i<quotients.size();++i){
        for(int j=i+1;j<quotients.size();++j){
            if(quotients[i] >= quotients[j]){
                ++quotients[i];
            }
        }
    }reverse(quotients.begin(), quotients.end());
    return quotients;
}

int main(){
    vector<int> temp = perm(999999, 10);
    for(int x : temp)
        cout << x;
    cout << endl;
}
