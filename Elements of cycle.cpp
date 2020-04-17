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
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define nrep(i,a,b) for(long long int i=a;i>=b;i--)
#define ceil(a,b) a/b+((a%b ==0 )?0:1)
using namespace std;

const ll sz=100005;
const ll szz=1000006;

ll n,m,t;
vl ar[sz];
ll sttime[sz], vis[sz];
vector<ll> ans;
ll dfs(ll node, ll par, ll time)
{
	if(vis[node])//if already visited check if the difference in time is greater than k
	{
		if(abs(time-sttime[node])>t)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	vis[node]=1;
	sttime[node]=time;
	ll st=0;
	for(ll child:ar[node])
	{
		if(child==par)
			continue;
		st|=dfs(child, node, time+1);//kya iss node k dfs se hume cycle mili?
		if(st==1)
		{
			ans.pb(child);
			break;
		}
	}
	return st;
}
 
int main()
{
	fast;
	#ifndef ONLINE_JUDGE
	freopen("IP.txt","r",stdin);
	freopen("OP.txt","w",stdout);
	#endif

	cin>>n>>m>>t;
	rep(i,0,m)
	{
		ll u,v;
		cin>>u>>v;
		ar[u].pb(v);
		ar[v].pb(u);
	}
	dfs(1, 1, 1);
	set<ll> store;
	ll cycle_length=0;
	for(auto it:ans)
	{
		if(store.find(it)!=store.end())
			break;
		store.insert(it);
		cycle_length++;
	}
	store.clear();
	cout<<cycle_length<<endl;
	for(auto it:ans)
	{
		if(store.find(it)!=store.end())
			break;
		store.insert(it);
		cout<<it<<" ";
	}
	
}//Goodbye