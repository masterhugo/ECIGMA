#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)
#define itloop(i,a) for(i=a.begin();i!=a.end();i++)
#define ms(a,c)    memset(a,c,sizeof(a))
#define READ(file)  freopen(file, "r", stdin)
#define WRITE(file) freopen(file, "w", stdout)
#define pb(a)    push_back(a)
#define pf(a)    push_front(a)
#define tup(a,b) make_pair(a,b)
#define popb()   pop_back()
#define popf()   pop_front()
#define X        first
#define Y        second
#define LIM      100
#define INF      1000000010
#define SZ       1000005
#define upA(a)   a*a
#define Base     10000

using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef deque<int> di;
typedef deque<ii> dii;
typedef di::iterator dit;
typedef vector<int> vi;
typedef set<int> si;
typedef set<large> sl;
typedef complex<double> im;
typedef vector<char*> vs;
typedef vector<large> bigint;

int main(){
	int n,a,b;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&a,&b);
		printf("%d\n",b^(b>>1));
	}
  return 0;
}