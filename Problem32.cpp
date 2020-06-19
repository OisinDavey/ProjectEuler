//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;

using namespace std;

bool is_pandigital(int& a, int& b, int& c){
    stringstream a_s, b_s, c_s;
    a_s << a;
    b_s << b;
    c_s << c;
    string A, B, C;
    a_s >> A;
    b_s >> B;
    c_s >> C;
    int in[10];
    memset(in, 0, sizeof(in));
    for(char x : A){
        ++in[x-'0'];
    }
    for(char x : B){
        ++in[x-'0'];
    }
    for(char x : C){
        ++in[x-'0'];
    }
    for(int i=0;i<10;++i){
        if(in[i] != 1){
            return false;
        }
    }
    return true;
}

int main(){
    set<int> can_be_written;
    string pan = "123456789";
    while(pan != "987654321"){
        for(int i=0;i<5;i++){
            for(int j=i+1;j<5;++j){
                string a = pan.substr(0, i+1);
                string b = pan.substr(i+1, j-i);
                string c = pan.substr(j+1, 10-j+1);
                stringstream as, bs, cs;
                int A, B, C;
                as << a;
                as >> A;
                bs << b;
                bs >> B;
                cs << c;
                cs >> C;
                if(A * B == C){
                    can_be_written.insert(C);
                }
            }
        }
        next_permutation(All(pan));
    }
    int ans = 0;
    for(auto it = can_be_written.begin(); it != can_be_written.end();++it){
        cout << *it << ' ';
        ans += *it;
    }
    cout << endl << ans << endl;
}
