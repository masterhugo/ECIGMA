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
#define SZ       100005
#define upA(a)   a*a
#define base     10000
#define EPS      1e-9
#define LSOne(i) (i&(-i))

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

static char cad[SZ];

struct nodo{
	char c;
	struct nodo* nxt;
	struct nodo* pre;
};

nodo* insertarNodo(char c,nodo* n){
	nodo* tmp = new nodo();
	tmp->c = c;
	tmp->nxt = n->nxt;
	n->nxt->pre = tmp;
	n->nxt= tmp;
	tmp->pre = n;
	return tmp;
}

int main(){
  int i;
	while(fgets(cad,SZ,stdin)){
    cad[strlen(cad)-1]=0;
		nodo* head = new nodo();
		nodo* tail = new nodo();
    tail->pre = head;
		head->nxt = tail;
		tail->nxt = head;
		head->pre = tail;
    nodo* current = head;
    tail->c = 0;
    for(int i=0; cad[i]; i++){
      if(cad[i]=='['){
        current = head;
        continue;
      }if(cad[i]==']'){
        current = tail->pre;
        continue;
      }
      current = insertarNodo(cad[i],current);
    }
    nodo* tmp = head->nxt;
    while(tmp->c){
      putchar(tmp->c);
      tmp = tmp->nxt;
    }
    puts("");
	}
  return 0;
}