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

void bfs(ll node)
{
	deque<ll> q;
	q.pb(node);
	while(!q.empty())
	{
		vis[node]=true;
		for(ll child:ar[q.front()])
		{
			if(!vis[child])
			{
				q.pb(child);
				vis[child]=true;
			}
		}
		cout<<q.front()<<" ";
		q.pop_front();
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

	rep(i,0,m)
	{
		ll a,b;
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}

	bfs(1);
}