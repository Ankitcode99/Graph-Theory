//AnkitCode99
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define vl vector<ll>
#define all(v) (v.begin(),v.end())
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define nrep(i,a,b) for(long long int i=a;i>=b;i--)
using namespace std;

vl ar[2001];
ll vis[2001],col[2001];

bool dfs(ll node,ll c)
{
	vis[node]=1;
	col[node]=c;

	for(ll child:ar[node])
	{
		if(vis[child]==0)
		{
			bool res=dfs(child,c^1);
			if(res==false)
				return false;
		}
		else
		{
			if(col[node]==col[child])
				return false;
		}
	}
	return true;
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
	rep(i,1,t+1)
	{
		ll n,m;
		cin>>n>>m;
		rep(j,1,n+1)
		{
			ar[i].clear();
		}
		rep(j,1,m+1)
		{
			ll a,b;
			cin>>a>>b;
			ar[a].pb(b);
			ar[b].pb(a);
		}

		bool flag=true;
		rep(j,1,n+1)
		{
			if(!vis[j])
			{
				bool res=dfs(j,0);
				if(!res)
				{
					flag=false;
				}
			}
		}
		cout<<"Senario #"<<i<<endl;
		if(flag)
			cout<<"No suspicious bugs found!\n";
		else
			cout<<"Suspicious bugs found!\n";
	}
}