// k'th parent of node in a TREE


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

vector<ll> ar[sz];
ll kpar[sz][20];

void dfs(ll node,ll par)
{
	kpar[node][0]=par;
	rep(i,1,20)
	{
		ll temp=kpar[node][i-1];
		kpar[node][i]=kpar[temp][i-1];
	}
	for(ll x:ar[node])
	{
		if(x!=par)
		{
			dfs(x,node);
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

	clock_t startTime=clock();

	ll n;
	cin>>n;
	rep(i,0,n-1)
	{
		ll a,b;
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}

	dfs(1,-1);

	ll q;
	cin>>q;
	while(q--)
	{
		ll node,k_th;
		cin>>node>>k_th;
		ll cnt=0;
		while(k_th)
		{
			if(k_th & 1)
			{
				node=kpar[node][cnt];
			}
			k_th>>=1;
			cnt++;
		}
		cout<<node<<endl;
	}

	cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

}//Goodbye...

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
2
11 2
7 3
*/