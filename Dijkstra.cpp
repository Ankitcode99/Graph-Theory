//AnkitCode99 here....
//every ups and downs matter!

#include<bits/stdc++.h>

#define endl "\n"
typedef long long int ll;
#define MOD 1000000007
#define pll pair<ll,ll>
#define pb push_back
//max xor btw range of two numbers..
#define max_XOR(a,b) (1 << int(log2(a ^ b) + 1)) - 1
#define vl vector<ll>
#define inf ll(1e18)
#define all(v) v.begin(),v.end()
#define Ryuga ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define nrep(i,a,b) for(long long int i=a;i>=b;i--)
#define ceil(a,b) a/b+((a%b ==0 )?0:1)

using namespace std;

const ll sz=100005;
const ll szz=1000006;
ll n,m;
vector<pll> ar[sz];
ll dis[sz],par[sz];

void dijkstra(ll source)
{
	rep(i,1,n+1)
	{
		if(i!=source)
			dis[i]=inf;
		else
			dis[i]=0;
	}

	memset(par,-1,sizeof par);

	priority_queue<pll,vector<pll>,greater<pll>> pq;

	pq.push({0,source});

	while(!pq.empty())
	{
		ll curr=pq.top().second;
		ll dist_v=pq.top().first;
		pq.pop();
		if(dist_v!=dis[curr])
			continue;

		for(auto edge:ar[curr])
		{
			ll child=edge.first;
			ll len=edge.second;

			if(dis[curr]+len<dis[child])
			{
				dis[child]=dis[curr]+len;
				par[child]=curr;
				pq.push({dis[child],child});
			}
		}
	}
}

int main()
{
	Ryuga;
	
    #ifndef ONLINE_JUDGE
	freopen("IP.txt","r",stdin);
	freopen("OP.txt","w",stdout);
	#endif	

	cin>>n>>m;

	rep(i,0,m)
	{
		ll a,b,we;
		cin>>a>>b>>we;
		ar[a].pb({b,we});
		ar[b].pb({a,we});
	}
	

	ll source;
	cin>>source;
	dijkstra(source);

	rep(i,1,n+1)
	{
		cout<<dis[i]<<" ";
	}

}//Goodbye...

/*
Test Case 

8 9
1 2 2
1 3 3
3 8 1
3 7 3
7 8 1
2 4 5
2 5 7
5 6 4
5 7 1
1

O/P - 0 2 3 7 6 10 5 4 
*/