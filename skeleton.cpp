#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define cBits(x) __builtin_popcountll((ll)x)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) a/gcd(a,b)*(b)
#define FOR(i,a,b) for (int i=a;i<b;i++)
#define FORr(i,a,b) for (int i=a;i>=b;i--)
#define MAX3(a,b,c) max(a,max(b,c))
#define MIN3(a,b,c) min(a,min(b,c))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<long long, long long> PLL;
typedef pair<int,int> PII;

const int MOD=1000000007;

template <typename T>
void pvec(const vector<T>& arr) {
    for (auto elem:arr) {
        cout << elem << " ";
    }
    cout << "\n";
}

template <typename T>
void clearq(queue<T>& q) {
   queue<T> empty;
   swap(q, empty);
}

template <typename T>
bool checkCommon(const vector <T>& v1, const vector <T>& v2) {
    typename vector <T>::iterator it1 = v1.begin();
    typename vector <T>::iterator it2 = v2.begin();
    while(it1 != v1.end() && it2 != v2.end()) {
        if (*it1 == *it2) {
            return true;
        }
        if (*it1 < *it2) {
            it1 = lower_bound(it1, v1.end(), *it2);
        }
        else if (*it2 < *it1) {
            it2 = lower_bound(it2, v2.end(), *it1);
        }
    }
    return false;
}

// solve(): solves an individual test case
void solve() {

    

}

int main() {

    // fastio;
    // #ifndef ONLINE_JUDGE
    // 	freopen("input.txt", "r", stdin);
    // 	freopen("output.txt", "w", stdout);
    // #endif

    int t = 1;
    // multiple test cases:
    // cin >> t;
    while(t--) {
        solve();
    }

	return 0;
}
