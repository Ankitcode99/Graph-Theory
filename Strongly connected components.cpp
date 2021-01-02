//AnkitCode99 here....
//every ups and downs matter!

#include<bits/stdc++.h>
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;

using namespace std;

const ll sz=1e5+5;

ll n,m;
vector<ll> order,compo;
vector<ll> g[sz],gT[sz];
vector<bool> vis;

void dfs1(ll node)
{
	vis[node]=true;
	for(ll child:g[node])
	{
		if(!vis[child])
		{
			dfs1(child);
		}
	}
	order.push_back(node);
}

void dfs2(ll node)
{
	vis[node]=true;
	compo.push_back(node);
	for(ll child:gT[node])
	{
		if(!vis[child])
		{
			dfs2(child);
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

	clock_t startTime=clock();

	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		g[a].push_back(b);
		gT[b].push_back(a);
	}

	vis.assign(n+1,0);

	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
			dfs1(i);
	}

	vis.assign(n+1,0);

	ll c=0;
	for(ll i=1;i<=n;i++)
	{
		ll curr=order[n-i];
		if(!vis[curr])
		{
			c++;
			compo.clear();
			dfs2(curr);
			for(auto x:compo)
				cout<<x<<" ";
			cout<<endl;
		}
	}
	
	cout<<"Total number of Strongly Connected Components are : "<<c<<endl;
	
	cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

}//Goodbye...
