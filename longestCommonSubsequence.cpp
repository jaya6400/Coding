//For those of you getting TLE in memoization top-down, follow some simple rules -
//1) Make sure your strings are passed by reference, as otherwise exponential times your strings will be copied when being passed to same function.
//2) Make sure to order the function arguments from least size argument to the highest size argument.
//
//Here is my code with all 3 methods :
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
int memo[1001][1001];

// Time = O(2^(n+m)) and Space = O(n+m)
int lcs_recur(string& a, string& b, int n, int m){

if( n == 0 || m == 0 )
return 0;

if( a[n-1] == b[m-1] ){
return ( 1 + lcs_recur(a, b, n-1, m-1) );
}
else{
return max(lcs_recur(a, b, n, m-1), lcs_recur(a, b, n-1, m));
}
}

// Time = O(n*m) and Space = O(n*m) + O(n+m)
int lcs_memo(int n, int m, string& a, string& b){

if( n == 0 || m == 0 )
return ( memo[n][m] = 0 );

if( memo[n][m] != -1 )
return memo[n][m];

if( a[n-1] == b[m-1] ){
return ( memo[n][m] = 1 + lcs_memo(n-1, m-1, a, b) );
}
else{
return ( memo[n][m] = max(lcs_memo(n, m-1, a, b), lcs_memo(n-1, m, a, b)) );
}
}

// Time = O(n*m) and Space = O(n*m)
int lcs_bottomUp(int n, int m, string &a, string &b){

int dp[n+1][m+1] = {-1};
//memset(dp, 0, sizeof(dp));

for(int i = 0; i <= n; ++i)
dp[i][0] = 0;
for(int i = 0; i <= m; ++i)
dp[0][i] = 0;

for(int i = 1; i <= n; ++i){
for(int j = 1; j <= m; ++j){
if( a[i-1] == b[j-1] )
dp[i][j] = 1 + dp[i-1][j-1];
else
dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
}
}

return dp[n][m];
}

//Function to find the length of longest common subsequence in two strings.
int lcs(int x, int y, string &s1, string &s2)
{
// Method 1 (gives TLE) : Using Recursion
// return lcs_recur(s1, s2, x, y);

// Method 2 : Using Top-Down Memoization
memset(memo, -1, sizeof(memo));
return lcs_memo(x, y, s1, s2);

// Method 3 : Most Efficient, Bottom Up Dp Tabulation Method
// return lcs_bottomUp(x, y, s1, s2);
}
};

int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x;
        cin>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1;
        cin>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}