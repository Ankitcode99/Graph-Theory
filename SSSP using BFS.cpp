//AnkitCode99 here....
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define MOD 1000000007
#define mp make_pair
#define pll pair<ll,ll>
#define pb push_back
//max xor btw range of two numbers..
#define max_XOR(a,b) (1 << int(log2(a ^ b) + 1)) - 1
#define vl vector<ll>
#define inf 1e20
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define nrep(i,a,b) for(long long int i=a;i>=b;i--)
#define ceil(a,b) a/b+((a%b ==0 )?0:1)
using namespace std;

vl ar[105];
ll vis[105],dis[105];

void BFS(ll src)
{
	vis[src]=1;
	dis[src]=0;

	queue<ll> q;
	q.push(src);

	while(!q.empty())
	{
		ll curr=q.front();
		q.pop();

		for(ll child:ar[curr])
		{
			if(vis[child]==0)
			{
				q.push(child);
				dis[child]=dis[curr]+1;
				vis[child]=1;
			}
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
		
		ll n,m;
		cin>>n>>m;
		rep(i,0,105)
		{
			ar[i].clear();
			vis[i]=0;
		}
		memset(dis,0,sizeof dis);
		memset(vis,0,sizeof vis);
		rep(i,0,m)
		{
			ll a,b;
			cin>>a>>b;
			ar[a].pb(b);
			ar[b].pb(a);
		}

		ll source;
		cin>>source;
		BFS(source);

		rep(i,1,n+1)
		{
			if(i==source)
				continue;
			else if(vis[i])
			{
				cout<<6*dis[i]<<" ";
			}
			else if(!vis[i])
			{
				cout<<"-1 ";
			}
		}
		cout<<endl;

		// cout<<dis[n]<<endl;
	}
}