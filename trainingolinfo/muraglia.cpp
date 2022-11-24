#include <utility>
#include <iostream>
#include <vector>
using namespace std;

// Declaring variables
static int R;
static vector<int> risultato1;
static vector<int> risultato2;

// Declaring functions

#define MAXN 1000005
vector<int>st(4*MAXN);
int n;
vector<int>ar;
void build(int i,int l,int r){
    if(l==r){
        st[i]=l;
        return;
    }
    int mid=(l+r)/2;
    build(i*2+1,l,mid);build(i*2+2,mid+1,r);
    if(ar[st[i*2+1]]>ar[st[i*2+2]])st[i]=st[i*2+1];
    else st[i]=st[i*2+2];
}

void up(int i,int l,int r,int pos,int v){
    if(l==r){
        ar[pos]=v;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)up(i*2+1,l,mid,pos,v);
    else up(i*2+2,mid+1,r,pos,v);
    if(ar[st[i*2+1]]>ar[st[i*2+2]])st[i]=st[i*2+1];
    else st[i]=st[i*2+2];
}
int q1(int i,int l,int r,int pos,int v){
    if(l>=pos)return -1;
    if(r<pos){
        while(l!=r){
            int mid=(l+r)/2;
            if(ar[st[i*2+2]]>v){
                l=mid+1;
                i=i*2+2;
            }else if(ar[st[i*2+1]]>v){
                r=mid;
                i=i*2+1;
            }else{
                return -1;
            }
        }
        if(ar[l]>v)return l;
        return -1;   
    }
    int mid=(l+r)/2;
    int a=q1(i*2+1,l,mid,pos,v),b=q1(i*2+2,mid+1,r,pos,v);
    return max(a,b);
}

int q2(int i,int l,int r,int pos,int v){
    if(r<=pos)return n;
    if(l>pos){
        while(l!=r){
            int mid=(l+r)/2;
            if(ar[st[i*2+1]]>v){
                r=mid;
                i=i*2+1;
            }else if(ar[st[i*2+2]]>v){
                l=mid+1;
                i=i*2+2;
            }else{
                return n;
            }
        }
        if(ar[l]>v)return l;
        return n;   
    }
    int mid=(l+r)/2;
    int a=q2(i*2+1,l,mid,pos,v),b=q2(i*2+2,mid+1,r,pos,v);
    return min(a,b);
}
void inizializza(int N, vector<int> H){
    ar=H;
    n=N;
    build(0,0,N-1);
}

// Functions ad-hoc for this grader
pair<int, int> chiedi(int x){
    return {max(0,q1(0,0,n-1,x,ar[x])),min(n-1,q2(0,0,n-1,x,ar[x]))};
}
void cambia(int x, int h){
    up(0,0,n-1,x,h);
    
}

void leggi_eventi(int M) {
    for (int i = 0; i < M; i++) {
        char tipo;
        cin >> tipo;

        if (tipo == 'Q') {
            int x;
            cin >> x;
            pair<int, int> risultato = chiedi(x);
            risultato1[R] = risultato.first;
            risultato2[R] = risultato.second;
            R++;
        } else {
            int x, h;
            cin >> x >> h;
            cambia(x, h);
        }
    }
}


int main() {
	// Reading input
	int N, M;
	cin >> N >> M;

	vector<int> H(N);
	risultato1.resize(M);
	risultato2.resize(M);

	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	
	// Calling functions
	inizializza(N, H);
	leggi_eventi(M);

	// Writing output
	for (int i = 0; i < R; i++) {
		cout << risultato1[i] << ' ' << risultato2[i] << '\n';
	}

	return 0;
}