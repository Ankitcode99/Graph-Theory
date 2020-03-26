// #include<bits/stdc++.h>
// #define REP(i,n) for (int i = 1; i <= n; i++)
// #define mod 1000000007
// #define pb push_back
// #define ff first
// #define ss second
// #define ii pair<int,int>
// #define vi vector<int>
// #define vii vector<ii>
// #define lli long long int
// #define INF 1000000000
// #define endl '\n'
// const double PI = 3.141592653589793238460;
// typedef std::complex<double> Complex;
// typedef std::valarray<Complex> CArray;
 
// using namespace std;
 
// vector<int> ar[100001];
// int vis[100001];
 
// void dfs(int node)
// {
// 	vis[node] = 1;
//  	cout<<node<<"  ";
// 	for(int child : ar[node])
// 	{
// 		if(!vis[child])
			
// 			dfs(child);
// 	}
		 
// }
 
 
// int main()
// {
	
// 	#ifndef ONLINE_JUDGE
// 	freopen("IP.txt","r",stdin);
// 	freopen("OP.txt","w",stdout);
// 	#endif

// 	int n , m , a , b;
// 	cin>>n>>m;
 
// 	for(int i=1;i<=m;i++)
// 		cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);
 
// 	dfs(1);
// }

//AnkitCode99 here....
#include<bits/stdc++.h>
#define endl "\n"
typedef long long int ll;
#define MOD 1000000007
#define mp make_pair
#define pll pair<ll,ll>
#define pb push_back
//max xor btw range of two numbers..
#define max_XOR(a,b) (1 << int(log2(a ^ b) + 1)) - 1
#define vl vector<ll>
#define inf ll(1e20)
#define all(v) (v.begin(),v.end())
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define nrep(i,a,b) for(long long int i=a;i>=b;i--)
#define ceil(a,b) a/b+((a%b ==0 )?0:1)
using namespace std;

const ll sz=100005;

vl ar[sz];
bool vis[sz];

void dfs(ll node)
{
	vis[node]=true;
	cout<<node<<" ";
	for(ll child:ar[node])
	{
		if(!vis[child])
			dfs(child);
	}
}

int main()
{
	fast;
    #ifndef ONLINE_JUDGE
	freopen("IP.txt","r",stdin);
	freopen("OP.txt","w",stdout);
	#endif

	ll n,m;
	cin>>n>>m;
	memset(vis,false,sizeof vis);
	rep(i,0,m)
	{
		ll a,b;
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}

	dfs(1);
	return 0;
}