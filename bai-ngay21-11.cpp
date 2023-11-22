#include<bits/stdc++.h>
using namespace std;
class PS1{
    protected:
    int tuso,mauso;
    public:
    void nhapps();
    void xuatps();
    void toigian();
    int gcd(int tuso,int mauso);
};
int PS1::gcd(int a,int b){
    a=abs(a);
    b=abs(b);
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }

}
void PS1::nhapps(){
    do{
        cout<<"nhap tu so:";
        cin>>tuso;
        cout<<"nhap mau so:";
        cin>>mauso;
    }while(mauso==0);

}
void PS1::toigian(){
    int uc=gcd(tuso,mauso);
    tuso=tuso/uc;
    mauso=mauso/uc;
}
void PS1::xuatps(){
    PS1::toigian();
    cout<<endl<<tuso<<"/"<<mauso;
}
class PS2:public PS1{
    public:
    PS2(){
        
    }
    PS2(int a,int b){
        tuso=a;
        mauso=b;
    }
    bool operator=(PS2 a);
    friend bool operator>(PS2 a,PS2 b);
    friend bool operator<(PS2 a,PS2 b);
    friend PS2 operator+(PS2 a,PS2 b);
};
PS2 operator+(PS2 a,PS2 b){
    PS2 c;
    c.tuso=a.tuso*b.mauso+a.mauso*b.tuso;
    c.mauso=a.mauso*b.mauso;
    return c;
}
bool PS2::operator=(PS2 a){
    this->tuso=a.tuso;
    this->mauso=a.mauso;
    return 1;
}
bool operator>(PS2 a,PS2 b){
    if(a.tuso*b.mauso>a.mauso*b.tuso){
        return 1;
    }else{
        return 0;
    }
}
bool operator<(PS2 a,PS2 b){
    if(a.tuso*b.mauso<a.mauso*b.tuso){
        return 1;
    }else{
        return 0;
    }
}
void nhap(int n,PS2 ps[]){
    cout<<"nhap phan so:..............."<<endl;
    for(int i=0;i<n;i++){
        cout<<"phan so "<<i+1<<endl;
        ps[i].nhapps();
    }
}
void xuat(int n,PS2 ps[]){
    cout<<"--------------phan so ------------"<<endl;
    for(int i=0;i<n;i++){
        ps[i].xuatps();
    }
}

void sapxep(int n,PS2 ps[]){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ps[i]<ps[j]){
                swap(ps[i],ps[j]);
            }
        }
    }
}
void xuatmaxmin(int n,PS2 ps[]){
    cout<<endl<<"------------------------------------"<<endl;
    cout<<endl<<"phan so lon nhat:";
    ps[0].xuatps();
    cout<<endl<<"phan so nho nhat:";
    ps[n-1].xuatps();
}
void tinhtong12(int n,PS2 ps[]){
    PS2 e(0,1);
    PS2 tm(1,2);
    for(int i=0;i<n;i++){
        if(ps[i]<tm){
            e=e+ps[i];
        }
    }
    e.xuatps();
}
void tinhtong14(int n,PS2 ps[]){
    PS2 f(0,1);
    PS2 tm(1,4);
    for(int i=0;i<n;i++){
        if(ps[i]>tm){
            f=f+ps[i];
        }
    }
    f.xuatps();
}
int main(){
    int n;
    cout<<"nhap so phan tu (max 10):";
    do{
        cin>>n;
    }while(n>10);
    PS2 ps[n];
    nhap(n,ps);
    xuat(n,ps);
    sapxep(n,ps);
    cout<<endl<<"sau khi sap xep:"<<endl;
    xuat(n,ps);
    xuatmaxmin(n,ps);
    cout<<endl<<"tong gia tri nho hon 1/2:";
    tinhtong12(n,ps);
    cout<<endl<<"tong gia tri lon hon 1/4:";
    tinhtong14(n,ps);

}