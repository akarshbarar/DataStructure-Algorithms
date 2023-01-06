#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define int long long
#define print(x) cout<<x;
#define debn(x) cout<<x<<" ";
#define deb(x) cout<<x<<"\n";
#define deB(x,comp) cout<<x<<" "<<comp<<"\n";
#define Deb(x,comp,compSqrt) cout<<x<<" "<<comp<<" "<<compSqrt<<"\n";
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define clt(x) 63-__builtin_clzll(x)
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define pi pair<ll,ll>
#define vi vector<ll>
#define vpi vector<pair<ll,ll>>
#define maxq priority_queue<ll>
#define minq priority_queue<ll,vector<ll>, greater<ll>>
#define cont continue;
#define reto return 0;
#define sz(x) (ll)(x.size()) 
#define spmod 1116295198451
#define md 998244353 
#define mod 1000000007
#define AKARSH 9876543210
// #define Акарш "Брар";
#define Plag "lag jayega";
#define Copy "krna glt bat h";
# define NO_OF_CHARS 256

 bool isOdd(int n) {
  return (n&1);
 }

 int countNumberOfBits(int n) {
    int count =0;
    while (n > 0) {
      count += (n&1);
      n = n >>1;
    }
    return count;
 }

 int removeLastSetBit(int n) {
  return (n & (n-1));
 }

 // Swap two numbers 
 //  x = x ^ y 
 //  y = x ^ y 
 //  x = x ^ y 

 int extractIthBit(int n, int i) {
   return (n & (1 << i));
 }


 int changeIthBit(int n, int i) {
  return (n | (1 << i));
 }

 int clearIthBit(int n, int i) {
  return (n & (~(1 << i)));
 }
// recursive implementation
int gcdOfArray(vector<int>& arr, int idx)
{
    if (idx == arr.size() - 1) {
        return arr[idx];
    }
    int p = arr[idx];
    int q = gcdOfArray(arr, idx + 1);
    return __gcd(p, q); // __gcd(p,q) is inbuilt library function
}

int getSum(int p, int q) {
    return q==0? p:getSum(p^q, (p&q)<<1); //be careful about the terminating condition;
}


int decToBinary(int n)
{
    // array to store binary number
    int binaryNum = 0;
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
        // storing remainder in binary array
        binaryNum =  binaryNum*10 + (n % 2);
        n = n / 2;
        i++;
    }
 
    int res = 0;

    while( binaryNum !=0) {
      int r = binaryNum%2;
      res = res*10 + r;
       binaryNum = binaryNum/2;
    }
    return res;
    
}


// right most set bit mask = (n) => n & -n
bool isHappy(int n) {
    if(n==1) return true;
    if (n>=2 && n <= 9) return false;
    int res = 0;
    while(n!=0) {
        int r = n%10;
        res+=(r*r);
        n=n/10;
    }
    cout<<res<<endl;
    bool x = isHappy(res);
    return x;
}
bool sortbysec(const pair<int,int> &p,const pair<int,int> &q)
{
    return (p.second < q.second);
}
    bool isPalindrome(string s) {
        int l = s.length();
        cout<<l<<endl;
        int j=l-1;
       for(int i=0; i< l; i++) {
            if (s[i] == 32) continue;
            if (s[j] == 32) {
              j--;
            }

            if((abs(toupper(s[i])-toupper(s[j])) != 0)) {
                cout<<s[i]<<"-->"<<s[j]<<abs(s[i]-s[j])<<endl;
                cout<<"false"<<endl;
                return false;
            }
        }

        return true;
    }
void solve() {
  // Start HERE
  // Акарш
  // Input

int n; cin>>n;
vector<int> a(n);
for (int i = 0; i < n; ++i)
{
  /* code */
  cin>>a[i];
}

vector<int> l(n);
vector<int> r(n);
l[0] = a[0];
for(int i=1; i<n; i++) {
  l[i] = a[i]*l[i-1];
}
r[0] = a[n-1];
for(int i=n-2; i>=0; i--) {
  r[i] = a[i]*r[i+1];
}
for(int i=0; i<n; i++) {
  cout<<l[i]<<" ";
}
cout<<endl;

for(int i=0; i<n; i++) {
  cout<<r[i]<<" ";
}
cout<<endl;

  // Акарш
} 

signed main() {
  // your code goes here
  int t; 
  cin>> t;
  while(t--) solve();
}

