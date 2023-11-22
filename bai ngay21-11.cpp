#include<bits/stdc++.h>
using namespace std;
class SP1{
    protected:
    float phanthuc,phanao;
    public:
    SP1(){}
    void nhap();
    void xuat();
    float tinhmodun();
};
class SP2:public SP1{
    public:
    bool operator=(SP2 a);
    friend bool operator<(SP2 a,SP2 b);
    friend SP2 operator+(SP2 a,SP2 b);
    friend bool operator==(SP2 a,SP2 b);
};
void SP1::nhap(){
    cout<<"phan thuc:";
    cin>>phanthuc;
    cout<<"phan ao";
    cin>>phanao;
}
void SP1::xuat(){
    cout<<phanthuc<<"+"<<phanao<<"i";
}
float SP1::tinhmodun(){
    return sqrt(phanthuc*phanthuc+phanao*phanao);
}
bool SP2::operator=(SP2 a){
    phanthuc=a.phanthuc;
    phanao=a.phanao;
    return true;
}
bool operator<(SP2 a,SP2 b){
    if(a.tinhmodun()<b.tinhmodun()){
        return true;
    }else{
        return false;
    }
}
SP2 operator+(SP2 a,SP2 b){
    SP2 c;
    c.phanthuc=a.phanthuc+b.phanthuc;
    c.phanao=a.phanao+b.phanao;
    return c;
}
bool operator==(SP2 a,SP2 b){
    return a=b;
}
void nhap(int n,SP2 a[]){
    for(int i=0;i<n;i++){
        cout<<"so phuc "<<i+1<<":"<<endl;
        a[i].nhap();
    }
}
void xuat(int n,SP2 a[]){
    for(int i=0;i<n;i++){
        cout<<"z"<<i+1<<"=";
        a[i].xuat();
    }
}
int main(){
    int n;
    cout<<"nhap so luong so phuc:";
    cin>>n;
    SP2 a[n];
    nhap(n,a);
    xuat(n,a);

}