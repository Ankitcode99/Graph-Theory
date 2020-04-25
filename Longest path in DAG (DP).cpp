//AnkitCode99 (DP)....
//every ups and downs matter!

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;

using namespace std;

const ll sz=1e5+5;
vector<ll> adj[sz];
ll cache[sz];

ll dfs(ll node)
{
    ll &ans=cache[node];
    if(ans!=-1)
        return ans;
    ans=0;//initialise size of curr node as 0
    for(ll child:adj[node])
    {
        ans=max(ans,1+dfs(child));
    }
    return ans;
}

int main()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif

    ll n,m;
    cin>>n>>m;
    memset(cache,-1,sizeof cache);
    for(ll i=1;i<=n;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ans=max(ans,dfs(i));
    }
    cout<<ans;

}//Goodbye...