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

ll n;
const ll sz=100005;
const ll szz=1000006;
vl ar[sz];
ll level[sz],LCA[sz][5];
void dfs(ll node,ll lev,ll par)
{
	level[node]=lev;
	LCA[node][0]=par;

	for(ll child:ar[node])
	{
		if(child!=par)
		{
			dfs(child,lev+1,node);
		}
	}
}


void make_table()
{
	dfs(1,0,-1);

	for(ll i=1;i<=3;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(LCA[j][i-1]!=-1)
			{
				ll par=LCA[j][i-1];
				LCA[j][i]=LCA[par][i-1];
			}
		}
	}
}

ll lca(ll a,ll b)
{
	a=6,b=8;
	if(level[a]>level[b])
		swap(a,b);

	ll d=level[b]-level[a];
	
	while(d>0)
	{
		ll k=log2(d);
		b=LCA[b][k];
		d-=(1<<k);
	}
	//cout<<a<<" "<<b<<endl;
	if(a==b)
		return a;

	nrep(i,4,0)
	{
		if(LCA[a][i]!=-1 and LCA[a][i]!=LCA[b][i])
		{
			a=LCA[a][i];
			b=LCA[b][i];
			cout<<a<<" "<<b<<endl;
		}
	}
	cout<<a<<endl;
	return LCA[a][0];
}

int main()
{
	fast;
    #ifndef ONLINE_JUDGE
	freopen("IP.txt","r",stdin);
	freopen("OP.txt","w",stdout);
	#endif

	cin>>n;
	cout<<n<<endl;
	rep(i,0,n-1)
	{
		ll a,b;
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}
	
	rep(i,1,n+1)
	{
		rep(j,0,4)
		{
			LCA[i][j]=-1;
		}
	}

	make_table();

	rep(i,1,n+1)
	{
		cout<<i<<"-> ";
		rep(j,0,4)
		{
			cout<<LCA[i][j]<<" ";
		}
		cout<<endl;
	}

	ll n1,n2;
	cin>>n1>>n2;
	cout<<n1<<" "<<n2<<endl;
	cout<<lca(n1,n2);
}
//Goodbye...

/*

Test Case
14
1 2
1 3
3 5
2 4
4 6
4 7
6 8
8 11
8 12
12 14
7 9
7 10
9 13
11 14

*/