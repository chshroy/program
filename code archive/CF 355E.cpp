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


const ll MAXn=3e5+5,MAXc=1000000+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MAXn],ispm[MAXc];
vector<ll> pm;
int main()
{
    IOS();
    /*for(ll i=2;i<MAXc;i++)
    {
      if(!ispm[i])pm.pb(i);
      for(int j=0;pm[j]*i<MAXc;j++)
      {
        ispm[i*pm[j]]=1;
        if(i%pm[j]==0)break;
      }
    }*/
    debug(123);
    ll n,k;
    cin>>n>>k;
    REP(i,n)cin>>d[i];
    sort(d,d+n);
    ll mx=1;
    //debug(SZ(pm));
    for(ll t=d[0];t>2;t--)
    {
      bool ok=1;
      for(int j=0;j*t<d[n-1];j++)
      {
        ll cta = lower_bound(d,d+n,(j+1)*t)-lower_bound(d,d+n,j*t);
        ll ctb = upper_bound(d,d+n,min(j*t+k,(j+1)*t-1))-lower_bound(d,d+n,j*t);
        if(cta!=ctb||(j==0&&cta!=0)){ok=0;break;}
      }
      if(ok){cout<<t<<endl;return 0;}
    }
    cout<<1<<endl;

}
