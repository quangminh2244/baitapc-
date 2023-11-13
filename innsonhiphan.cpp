#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void nhiphan(){
    queue<int> hd;
    int a;
    hd.push(1);
    for(int i=0;i<10000;i++){
        a=hd.front();
        v.push_back(a);
        hd.pop();
        hd.push(a*10);
        hd.push(a*10+1);


    }
}
int main() {
    nhiphan();
    int n;
    cout<<"nhap n:";
    cin>>n;
    for(int i=0;i < n;i++){
        cout<<endl<<v[i];
    }
}
