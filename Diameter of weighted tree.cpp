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
#define vpll vector<pll>
#define inf ll(1e18)
#define all(v) (v.begin(),v.end())
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define nrep(i,a,b) for(long long int i=a;i>=b;i--)
#define ceil(a,b) a/b+((a%b ==0 )?0:1)
using namespace std;

const ll sz=100005;
const ll szz=1000006;
vpll ar[sz];
bool vis[sz];
ll maxnode,maxdis;

void dfs(ll node,ll dis)
{
	vis[node]=true;
	if(dis>maxdis)
	{
		maxdis=dis;
		maxnode=node;
	}
	for(pll child:ar[node])
	{
		if(!vis[child.first])
		{
			dfs(child.first,dis+child.second);
		}
	}
}

int main()
{
	fast;
    #ifndef ONLINE_JUDGE
	freopen("IP.txt","r",stdin);
	freopen("OP.txt","w",stdout);
	#endif

	ll t;
	cin>>t;
	while(t--)
	{
		rep(i,0,sz)
		{
			ar[i].clear();
		}
		memset(vis,false,sizeof vis);
		ll n;
		cin>>n;
		rep(i,0,n-1)
		{
			ll a,b,edge_length;
			cin>>a>>b>>edge_length;
			ar[a].pb({b,edge_length});
			ar[b].pb({a,edge_length});
		}

		maxdis=-1;
		dfs(1,0);

		memset(vis,false,sizeof vis);

		maxdis=-1;
		dfs(maxnode,0);
		cout<<maxdis<<endl;
	}
}

/*
Test case

1
6
1 2 3
2 3 4 
2 6 2
6 4 6
6 5 5

O/P - 12
*/
