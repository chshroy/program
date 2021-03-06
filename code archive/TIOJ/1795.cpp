//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ii> e0,e1;
ll g0[MAXn],g1[MAXn];

ll fd(ll a,ll *p){return p[a]=(a==p[a]?a:fd(p[a],p));}
void mg(ll a,ll b,ll *p)
{
  a=fd(a,p);b=fd(b,p);
  p[a]=b;
}

int main()
{
    IOS();
    ll n,m,k;
    cin>>n>>m>>k;
    REP(i,m)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      if(c)e1.pb(ii(a-1,b-1));
      else e0.pb(ii(a-1,b-1));
    }
    REP(i,n)g0[i]=g1[i]=i;
    for(ii tmp:e0)if(fd(tmp.X,g0)!=fd(tmp.Y,g0))mg(tmp.X,tmp.Y,g0);
    for(ii tmp:e1)
    {
      if(!k)break;
      if(fd(tmp.X,g0)!=fd(tmp.Y,g0))
      {
        mg(tmp.X,tmp.Y,g0);
        mg(tmp.X,tmp.Y,g1);
        k--;
      }
    }
    for(ii tmp:e1)
    {
      if(!k)break;
      if(fd(tmp.X,g1)!=fd(tmp.Y,g1))
      {
        mg(tmp.X,tmp.Y,g1);
        k--;
      }
    }
    ll ct=0;
    REP(i,n)if(g0[i]==i)ct++;
    if(ct!=1)k=1;
    if(k)cout<<"NIE"<<endl;
    else cout<<"TAK"<<endl;
}
