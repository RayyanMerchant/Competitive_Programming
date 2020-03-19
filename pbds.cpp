#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#define debug(x) cout << #x " = " << (x) << '\n';
#define P(x) cout << #x << '\n';    
#define int long long
typedef pair<int, int> pii;
const int mod = 1000000007;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    
    ordered_set <pii> st;
    st.insert({1, 2});
    st.insert({1, 3});
    st.insert({2, 2});
    st.insert({-1, 4});
    
    pii is = *st.find_by_order(0);
    cout << is.first << " " << is.second << '\n';
    
    return 0;
}

/*
won't compile on windows use jdoodle 
Link : https://www.jdoodle.com/online-compiler-c++17/
*/
/*
Functions -:
st.insert(x) : inserts x into the set
*st.find_by_order : 0 indexed and returns iterator so * must be used to get the value
*/









