#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}
vector<long long> multiply(vector<long long> const& a, vector<long long> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<long long> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}


int main(){
    string s;
    cin>>s;
    vector<long long>a(400000,0),b(400000,0);
    int k=200000;
    vector<int>prefix(s.size()+1,0);
    b[k]++;

    for(int i=1;i<=s.size();i++){
        prefix[i]=prefix[i-1];
        prefix[i]+=(s[i-1]=='1');
        a[prefix[i]+k]++;
        b[-prefix[i]+k]++;
    }
    long long supp=0;
    long long cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')cnt++;
        else{
            supp+=cnt*(cnt+1)/2;
            cnt=0;
        }
    }
    supp+=cnt*(cnt+1)/2;
    vector<long long>c=multiply(a,b);
    c[2*k]=supp;
    for(int i=2*k;i<=2*k+s.size();i++)cout<<c[i]<<" ";
    cout<<"\n";
}