//AnkitCode99 here....
//every ups and downs matter!

#include<bits/stdc++.h>
#define endl "\n"
#define Ryuga ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back

using namespace std;

const ll sz=1e5+5;
const ll szz=1e6+6;
const ll mod=1e9+7;

ll n,m,target;
vector<ll> ar[sz];
ll dp[sz];
bool vis[sz];

ll moves(ll node,ll par)
{
	if(node==target)
		return 1;
	
	ll ways=0;
	for(ll x:ar[node])
	{
		if(x!=par)
			ways+=moves(x,node);
	}
	return dp[node]=ways;
}

int main()
{
	Ryuga;

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("op.txt","w",stdout);
	#endif

	clock_t startTime=clock();

	cin>>n>>m;
	rep(i,0,m)
	{
		ll a,b;
		cin>>a>>b;
		ar[a].pb(b);
	}



	cin>>target;

	cout<<moves(1,-1)<<endl;

	rep(i,1,7)
	{
		cout<<dp[i]<<" ";
	}

	cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

}//Goodbye...