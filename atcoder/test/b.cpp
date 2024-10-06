#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }


/*
  stl sort() can't pass testcases 2, nlog(n) compares
*/

int m['Z'+1]['Z'+1]; // memory corner case repeated compare

bool cmp(const char a, const char b) {
  if (m[a][b]==-1) {
    printf("? %c %c\n",a,b);
    fflush(stdout);
    char ans;
    scanf(" %c",&ans);
    if(ans=='>') {
      m[a][b]=0;
      m[b][a]=1;
    } else {
      m[a][b]=1;
      m[b][a]=0;
    }
  }
  return m[a][b];
}

int main() {
  int n,q;
  scanf("%d%d",&n,&q);

  char s[27];
  for(int i=0;i<n;i++) s[i]='A'+i;
  s[n]='\0';
  memset(m, -1, sizeof(m));
  
  if (n==26) {
    char k;
    for (int i=1;i<n;i++) {
      k=s[i];
      int l=0,r=i-1;
      while (l<r) {
        int mid=(l+r)>>1;
        if (cmp(k, s[mid])) r=mid;
        else l=mid+1;
      }
      if (!cmp(k,s[r])) r++;
      for (int j=i;j>r;j--) s[j]=s[j-1];
      s[r]=k;
    }
  } else {
    char t;
    if (cmp(s[1],s[0])) swap(s[0],s[1]); // AB 1
    if (cmp(s[3],s[2])) swap(s[2],s[3]); // CD 2
    if (cmp(s[2],s[0])) { // CDABE 3
      swap(s[0],s[2]);
      swap(s[1],s[3]);
    }
    
    t=s[1]; // (D)
    
    if (cmp(s[4],s[2])) { // 4
      if (cmp(s[4],s[0])) { // EC(D)AB 5
        s[1]=s[0];
        s[0]=s[4];
      } else { // C(D)EAB 5
        s[1]=s[4];
      }
    } else {
      if (cmp(s[4],s[3])) { // C(D)AEB 5
        s[1]=s[2];
        s[2]=s[4];
      } else { // C(D)ABE 5
        s[1]=s[2];
        s[2]=s[3];
        s[3]=s[4];
      }
    }
    
    // insert t (D)
    if (cmp(t,s[2])) { // 6
      if (cmp(t,s[1])) { // 7
        s[4]=s[3];
        s[3]=s[2];
        s[2]=s[1];
        s[1]=t;
      } else {
        s[4]=s[3];
        s[3]=s[2];
        s[2]=t;
      }
    } else if (cmp(t,s[3])) { // 7
      s[4]=s[3];
      s[3]=t;
    } else {
      s[4]=t;
    } 
  }
  printf("! %s\n", s);
  fflush(stdout);
    
  return 0;
}
