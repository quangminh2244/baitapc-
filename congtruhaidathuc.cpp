#include<bits/stdc++.h>
using namespace std;
class dathuc{
    private:
    int bac;
    float *heso;
    public:
    void nhap();
    void xuat();
    friend dathuc operator+(dathuc a, dathuc b);
    friend dathuc operator-(dathuc a, dathuc b);
};
dathuc operator+(dathuc a, dathuc b){
    dathuc c;
    c.bac=a.bac>=b.bac?a.bac:b.bac;
    c.heso=new float[c.bac+1];
    for(int i=0;i<c.bac+1;i++){
        if(a.bac<b.bac){
            if(a.bac-i>=0){
            c.heso[i]=a.heso[i]+b.heso[i];
            }else{
            c.heso[i]=b.heso[i];
            }
        }else{
            if(b.bac-i>=0){
            c.heso[i]=a.heso[i]+b.heso[i];
            }else{
            c.heso[i]=a.heso[i];
            }
        }
    }
    return c;
}
dathuc operator-(dathuc a, dathuc b){
    dathuc c;
    c.bac=a.bac>=b.bac?a.bac:b.bac;
    c.heso=new float[c.bac+1];
    for(int i=0;i<c.bac+1;i++){
        if(a.bac<b.bac){
            if(a.bac-i>=0){
            c.heso[i]=a.heso[i]-b.heso[i];
            }else{
            c.heso[i]=-b.heso[i];
            }
        }else{
            if(b.bac-i>=0){
            c.heso[i]=a.heso[i]-b.heso[i];
            }else{
            c.heso[i]=a.heso[i];
            }
        }
    }
    return c;
}
void dathuc::nhap(){
    cout<<"nhap bac da thuc:";
    cin>>bac;
    int z=0;
    heso=new float[bac+1];
    for(int i=0;i<bac+1;i++){
        cout<<"nhap he so bac "<<z<<":";
        cin>>heso[i];
        z++;
    }
}
void dathuc::xuat(){
    for(int i=bac;i>=0;i--){
        
        if(i!=0){
            if(heso[i-1]>=0){
                cout<<heso[i]<<"x^"<<i;
                cout<<"+";
            }else{
                cout<<heso[i]<<"x^"<<i;
            }
        }else{
            cout<<heso[i]<<"=0";
        }
    }
}
int main(){
    dathuc a,b,c;
    cout<<"nhap da thuc 1:"<<endl;n
    a.nhap();
    cout<<"nhap da thuc 2:"<<endl;
    b.nhap();
    cout<<"da thuc vua nhap : ";
    a.xuat();
    cout<<endl;
    cout<<"da thuc vua nhap : ";
    b.xuat();
    c=a+b;
    cout<<endl<<"da thuc a+b="<<endl;
    c.xuat();
    c=a-b;
    cout<<endl<<"da thuc a-b="<<endl;
    c.xuat();
    return 0;
}