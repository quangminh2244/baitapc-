#include<bits/stdc++.h>
using namespace std;
class SP1{
    protected:
    float phanthuc,phanao;
    public:
    SP1(){}
    SP1(float a,float b){
        phanthuc=a;
        phanao=b;
    }
    void nhap();
    void xuat();
    float tinhmodun();
};
class SP2:public SP1{
    public:
    SP2(){}
    SP2(float a,float b):SP1(a,b){}
    bool operator=(SP2 a);
    friend bool operator<(SP2 a,SP2 b);
    friend SP2 operator+(SP2 a,SP2 b);
    friend bool operator==(SP2 a,SP2 b);
};
void SP1::nhap(){
    cout<<"phan thuc:";
    cin>>phanthuc;
    cout<<"phan ao:";
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
    if(a.phanthuc==b.phanthuc&&a.phanao==b.phanao){
        return true;
    }else{
        return false;
    }
}
void nhap(int n,SP2 a[]){
    for(int i=0;i<n;i++){
        cout<<"------so phuc "<<i+1<<"-------"<<endl;
        a[i].nhap();
    }
}
void xuat(int n,SP2 a[]){
    for(int i=0;i<n;i++){
        cout<<"z"<<i+1<<"=";
        a[i].xuat();
        cout<<endl;
    }
}
void xapxep(int n,SP2 a[]){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                swap(a[i],a[j]);
            }
        }
    }
}
SP2 tinhtong(int n,SP2 a[]){
    SP2 tong(0,0);
    for(int i=0;i<n;i++){
        tong=tong+a[i];
    }
    return tong;
}
int dem(int n,SP2 a[]){
    SP2 tp(3,4);
    int temp=0;
    for(int i=0;i<n;i++){
        if(tp==a[i]){
            temp++;
        }
    }
    return temp;
}
void maxmin(int n,SP2 a[]){
    cout<<endl<<"so phuc nho nhat:";
    a[0].xuat();
    cout<<endl<<"so phuc lon nhat:";
    a[n-1].xuat();
}
int main(){
    int n;
    cout<<"nhap so luong so phuc:";
    cin>>n;
    SP2 a[n];
    nhap(n,a);
    cout<<"so phuc da nhap:";
    xuat(n,a);
    xapxep(n,a);
    cout<<endl<<"sau khi sap xep:::::::::::::::"<<endl;
    xuat(n,a);
    maxmin(n,a);
    cout<<endl<<"tong cac so phuc =";
    tinhtong(n,a).xuat();
    cout<<endl<<"co "<<dem(n,a)<<" so phuc co gia tri =3+4i";
}
