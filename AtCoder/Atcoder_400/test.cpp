#include<bits/stdc++.h>
#define ll long long
#define r(i,n) for(ll i=0;i<n;i++)
#define rp(i,a,b) for(ll i=a;i<b;i++)
#define ret return
#define rt ret
#define db double
#define p(x) cout<<(x)<<endl;
#define ce continue;
#define bl bool
#define r0 ret 0;
#define r1 ret 1;
#define elif else if
#define bk break;
#define A p("A")//roll call:点呼.
#define B p("B")
#define C p("C")
#define D p("D")
#define E p("E")
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define cn cin
#define n(a) a.size();
#define els else
#define vc vector
#define vd void
using namespace std;
void Justice(int g){if(g)p("YES")else p("NO")rt;}
void justice(int g){if(g)p("Yes")else p("No")rt;}
ll pow_mod(ll n,ll k,ll m){if(!k)r1 if((k%2))//戻値は(n^k)mod m;
  rt (pow_mod(n,k-1,m)*(n%m))%m;if(!(k%2)){//戻値は(n^k)mod m;
    ll t=pow_mod(n,k/2,m);rt (t*t)%m;}
    r0
  }//戻値は(n^k)mod m;
  ll power(ll k){ll t=1;r(i,k+1)t*=2;ret t;}//この関数は2のk乗を返す.
  ll comb(ll i,ll j){ll up=1;for(ll n=i;n>i-j;n--){up*=n;}ll down=1;for(ll r=j;r>=1;r--)down*=r;ret up/(down);}//nCr.
  ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)ret b;gcd(b,a%b);}
  //set<ll>uuu;
  //void prime(){bool x[(ll)1e6];memset(x,0,sizeof(x));rp(i,2,1e6)if(!x[i])for(ll j=i+i;j<(ll)1e6;j+=j)x[j]=1;vector<ll>sosu;ll t;rp(i,2,1e6)if(!x[i])sosu.push_back(i);rp(i,2,(ll)1e6){if(!x[i])uuu.insert(i);}ret;}
  //ll ispn(ll k){if(uuu.find(k)!=uuu.end())ret 1;ret 0;}//素数判定.動作不良の可能性大.
  //bl ispn2(ll k){if(k==1)rt 0;if(k==2||k==3)rt 1;rp(i,2,(ll)sqrt((db)k)+1)if(k%i==0)rt 0;rt 1;}
  ll AmountOfDigits(ll k){ll t=0;while(k){t+=k%10;k/=10;}rt t;}
  char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
  //srand((unsigned int)time(NULL));
  const ll INF=(ll)1e18;
  typedef pair<ll,ll> P;
  typedef struct edge{ll to,cost;}EDGE;

  int main(){
    while(1){
      ll n,c;
      cin>>n>>c;
      vector<ll>s(n),t(n),ch(n);
      r(i,n)cin>>s[i]>>t[i]>>ch[i];
      ll time[100001];
      ll tt[100001];
      memset(time,0,sizeof(time));
      rp(i,1,c+1){//CHANNEL
        memset(tt,0,sizeof(tt));
        r(j,n)if(ch[j]==i)tt[(s[j] == 0) ? s[j] : s[j]-1]++,tt[t[j]]--;
        ll g=0,sta=0,sum=0;
        rp(ii,1,100001){
          tt[ii]+=sum,sum=tt[ii];
          if(tt[ii]&&!g){sta=ii;g=1;}
          elif(!tt[ii]&&g){
            time[sta]++;
            time[ii]--;
            g=0;
          }
          elif(!g&&!tt[ii])ce
          elif(g&&tt[ii])ce
        }//IMOSSING
      }//REP
      ll sum=0,mx=-(ll)1e18;
      rp(i,1,100001)
      time[i]+=sum,sum=time[i],mx=max(mx,time[i]);
      p(mx)
      r0
    }
  }
