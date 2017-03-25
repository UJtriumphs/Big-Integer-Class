// Big Integer Implementation
#include "bits/stdc++.h"
using namespace std;
typedef double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

#define pb                       push_back
#define fi                       first
#define se                       second
#define tracearr(a,n)            for(int i=0;i<n;i++)  cout<<a[i]<<" ";
#define tracemat(a,n,m)          for(int i=0;i<n;i++) { for(int j=0;j<m;j++)  cout<<a[i][j]<<" "; cout<<endl; }
#define tracepair(a,n)           for(int i=0;i<n;i++)  cout<<a[i].first<<" "<<a[i].second<<endl;
#define all(v)                   v.begin(),v.end()
#define uniq(v)                  sort(all(v));  v.erase(unique(all(v)),v.end())
#define foreach(c,itr)           for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mp(v,a,b)                v.push_back(make_pair(a,b))
#define FOR(i,n,m)               for(int i=0;i<n;i+=m)
#define For(i,n,m)               for(int i=1;i<=n;i+=m)
#define countbits(value)         __builtin_popcount(value)
#define countbitsll(value)       __builtin_popcountll(value)
#define trailing0bits(value)     __builtin_parity(value)
#define leading0bits(value)      __builtin_clz(value)
#define max(a,b)                 (a>=b?a:b)
#define min(a,b)                 (a<b?a:b)
#define s(a)                     scanf("%d",&a)
#define p(a)                     printf("%d",a)
#define pln()                    printf("\n")
#define clr(x)                   memset(x,0,sizeof(x))
#define uj()                     int t; scanf("%d",&t); while(t--)
template<typename T> T gcd(T a, T b) {if(!b) return a;return gcd(b, a % b);}
template<typename T> T lcm(T a, T b) {return a * b / gcd(a, b);}
int greater1(string x,string y){
   int i=0;
   while(x[i]==y[i] && i<x.size()){
    i++;
   }
   if(i==x.size()) return -1;
   if(x[i]-'0'>y[i]-'0') return 1;
   else return 0;
}
vector<string> equallength(string x,string y){
    //if(x.size()==y.size()) return;
    if(x.size()>y.size()){
        string temp1=x,temp2=y;
        reverse(all(temp1));
        reverse(all(temp2));
        int u=x.size()-y.size();
        while(u--){
            temp2.pb('0');
        }
        reverse(all(temp1));
        reverse(all(temp2));
        x=temp1;
        y=temp2;
    }
    if(y.size()>x.size()){
        string temp1=x,temp2=y;
        reverse(all(temp1));
        reverse(all(temp2));
        int u=y.size()-x.size();
        while(u--){
            temp1.pb('0');
        }
        reverse(all(temp1));
        reverse(all(temp2));
        x=temp1;
        y=temp2;
    }
    vector<string> ans;
    ans.pb(x);
    ans.pb(y);
    return ans;
}

string add(string x,string y){
       string ans="";
       vector<string> el=equallength(x,y);
       x=el[0];
       y=el[1];
       int carry=0;
       for(int i=x.size()-1;i>=0;i--){
           //cout<<(((x[i]-'0')+(y[i]-'0')+carry)%10)<<endl;
         int ans1=(((x[i]-'0')+(y[i]-'0')+carry)%10);
         ans.pb((char)(ans1+48));
         carry=(x[i]-'0'+y[i]-'0'+carry)/10;
       }
    if(carry!=0)
    ans.pb((char)(carry+48));
    reverse(all(ans));
    return ans;
}

string subtract(string x,string y){
    string ans="";
    vector<string> el=equallength(x,y);
    x=el[0];
    y=el[1];
    //cout<<x<<" "<<y<<endl;
    int flag=greater1(x,y);
    //cout<<flag<<endl;
        if(!flag)
        {
            string temp=x;
            x=y;
            y=temp;
        }
        for(int i=x.size()-1;i>=0;i--){
            if(x[i]-y[i]>=0){
                ans.pb((char)(48+x[i]-y[i]));
            }
            else{
              int r=i-1;
              while(x[r]=='0') r--;
              x[r]=x[r]-1;
              for(int k=r+1;k<i;k++){
                x[k]='9';
              }
              int p=10+(x[i]-'0');
              int q=y[i]-'0';
              ans.pb((char)(48+(p-q)));
            }
            //cout<<x<<" "<<y<<" "<<ans<<endl;
        }
    reverse(all(ans));
    return ans;

}

string multiply(string x,string y){
   string ans="";
   for(int i=y.size()-1;i>=0;i--){
    string temp="";
    int e=y.size()-1-i;;
    while(e--) temp.pb('0');
    int p=y[i]-'0';
    int carry=0;
    //cout<<y[i]<<" ";
    for(int j=x.size()-1;j>=0;j--){
        //cout<<x[i]<<" ";
        int q=x[j]-'0';
        int y=((p*q)+carry)%10;
        carry=((p*q)+carry)/10;
        cout<<carry<<" ";
        temp.pb((char)(y+48));
    }
    if(carry!=0)temp.pb((char)(carry+48));
    reverse(all(temp));
    cout<<temp<<endl;
   // cout<<temp<<endl;
    if(ans==""){
        ans=temp;
    }
    else{
        vector<string> el=equallength(temp,ans);
        temp=el[0],ans=el[1];
        ans=add(temp,ans);
    }
   }
   return ans;
}

string divide(string x,string y){

}
int main(){
    string x,y;
   cin>>x>>y;
   string ans=subtract(x,y);
   cout<<ans<<endl;

return 0;
}

