 #include <bits/stdc++.h>
 using namespace std;
 char s[200];
 int dist(array<int,2>a,array<int,2>b){
    return abs(a[0]-b[0])+abs(a[1]-b[1]);
 }
 int main(){
    set<int>okk;
    ifstream cin("input.txt");
    vector<array<int,2> >sensor,beacon;
    int start=0;
    int fine=0;
    int ris=0;
    while(cin.getline(s,150)){
        int x1=0,y1=0,x2=0,y2=0;
        for(int i=0;i<150;i++){
            if(s[i]=='x'){
                int j=i+2;
                while(s[j]>='0'&&s[j]<='9'){
                    x1*=10;
                    x1+=s[j]-'0';
                    j++;
                }
                break;
            }
        }
        for(int i=0;i<150;i++){
            if(s[i]=='y'){
                int j=i+2;
                while(s[j]>='0'&&s[j]<='9'){
                    y1*=10;
                    y1+=s[j]-'0';
                    j++;
                }
                break;
            }
        }
        for(int i=140;i>=0;i--){
            if(s[i]=='x'){
                int j=i+2;
                bool neg=false;
                if(s[j]=='-'){
                    neg=true;
                    j++;
                }
                while(s[j]>='0'&&s[j]<='9'){
                    x2*=10;
                    x2+=s[j]-'0';
                    j++;
                }
                if(neg)x2*=-1;
                break;
            }
        }
        for(int i=140;i>=0;i--){
            if(s[i]=='y'){
                int j=i+2;
                bool neg=false;
                if(s[j]=='-'){
                    neg=true;
                    j++;
                }
                while(s[j]>='0'&&s[j]<='9'){
                    y2*=10;
                    y2+=s[j]-'0';
                    j++;
                }
                if(neg)y2*=-1;
                break;
            }
        }
        start=min(start,y1-dist({x1,y1},{x2,y2}));
        fine=max(fine,y1+dist({x1,y1},{x2,y2}));
        cout<<x1<<" "<<y1<< " | "<<x2<<" "<<y2<<"\n";
        sensor.push_back({x1,y1});
        beacon.push_back({x2,y2});
        if(y2==2000000)okk.insert(x2);
    }
    ris=-okk.size();
    cout<<okk.size()<<"\n";
    cout<<start<<" "<<fine<<"\n";
    for(int x=start-10;x<fine+10;x++){
        bool ok=true;
        for(int i=0;i<sensor.size();i++){
            if(dist(sensor[i],beacon[i])>=dist(sensor[i],{x,2000000})){
                ok=false;
                break;
            }
        }
        if(!ok)ris++;
    }
    cout<<ris<<"\n";
 }