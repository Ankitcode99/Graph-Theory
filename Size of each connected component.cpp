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
#define inf ll(1e18)
#define all(v) (v.begin(),v.end())
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define nrep(i,a,b) for(long long int i=a;i>=b;i--)
#define ceil(a,b) a/b+((a%b ==0 )?0:1)
using namespace std;

const ll sz=100005;
vl ar[sz];
bool vis[sz];

ll lendfs(ll node,ll cursize)
{
	vis[node]=true;
	cursize=1;
	for(ll child:ar[node])
	{
		if(!vis[child])
		{
			cursize+=lendfs(child,cursize);
		}
	}
	return cursize;
}

int main()
{
	fast;
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("op.txt","w",stdout);
	#endif

	ll n;
	cin>>n;
	memset(vis,false,sizeof vis);
	rep(i,0,n)
	{
		ll a,b;
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}
	ll maxi=-inf,mini=inf;
	rep(i,1,n+1)
	{
		if(!vis[i])
		{
			mini=min(mini,lendfs(i,0));
			maxi=max(maxi,lendfs(i,0));
		}
	}
}