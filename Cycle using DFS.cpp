// //AnkitCode99
// #include<bits/stdc++.h>
// #define endl "\n"
// #define ll long long int
// #define MOD 1000000007
// #define mp make_pair
// #define pb push_back
// #define vl vector<ll>
// #define all(v) (v.begin(),v.end())
// #define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
// #define rep(i,a,b) for(long long int i=a;i<b;i++)
// #define nrep(i,a,b) for(long long int i=a;i>=b;i--)
// using namespace std;

// vl ar[2001];
// ll vis[2001];

// bool dfs(ll node,ll parent)
// {
// 	vis[node]=1;
// 	for(ll child:ar[node])
// 	{
// 		if(vis[child]==0)
// 		{
// 			if(dfs(child,node)==true)
// 				return true;
// 		}
// 		else
// 		{
// 			if(child!=parent)
// 				return true;
// 		}
// 	}
// 	return false;
// }

// int main()
// {
// 	fast;
//     #ifndef ONLINE_JUDGE
// 	freopen("IP.txt","r",stdin);
// 	freopen("OP.txt","w",stdout);
// 	#endif
// 	ll t;
// 	cin>>t;
// 	rep(i,1,t+1)
// 	{
// 		ll n,m;
// 		cin>>n>>m;
// 		rep(j,1,n+1)
// 		{
// 			ar[i].clear();
// 		}
// 		rep(j,1,m+1)
// 		{
// 			ll a,b;
// 			cin>>a>>b;
// 			ar[a].pb(b);
// 			ar[b].pb(a);
// 		}

// 		if(dfs(1,-1))
// 			cout<<"Cycle is present!\n";
// 		else
// 			cout<<"Cycle is not present\n";
// 	}
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

bool dfs(ll node,ll par)
{
	vis[node]=true;
	for(ll child:ar[node])
	{
		if(!vis[child])
		{
			bool res=dfs(child,node);
			if(res==true)
				return true;
		}
		else
		{
			if(child!=par)
				return true;
		}
	}
	return false;
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

	rep(i,0,m)
	{
		ll a,b;
		cin>>a>>b;

		ar[a].pb(b);
		ar[b].pb(a);
	}

	bool ans=dfs(1,-1);
	if(ans)
		cout<<"Cycle is present\n";
	else
		cout<<"Cycle is not present\n";
}