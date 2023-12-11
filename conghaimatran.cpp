#include<bits/stdc++.h>
using namespace std;
class matran{
    private:
    int sohang=0,socot=0;
    vector<vector<float>> phantu;
    public:
    void nhap(int a,int b);
    void xuat();
    int gethang();
    int getcot();
    friend matran cong(matran a,matran b);
};
matran cong(matran a,matran b){
    matran c;
    c.sohang=a.sohang;
    c.socot=a.socot;
    c.phantu.resize(a.sohang,vector<float>(a.socot,0));
    for(int i=0;i<a.sohang;i++){
        for(int j=0;j<a.socot;j++){
            c.phantu[i][j] =a.phantu[i][j]+b.phantu[i][j];
        }
    }
    return c;
}
int matran::gethang(){
    return sohang;
}
int matran::getcot(){
    return socot;
}
void matran::nhap(int a,int b){
    sohang=a;
    socot=b;
    phantu.resize(sohang,vector<float>(socot,0));
    for(int i=0;i<sohang;i++){
        for(int j=0;j<socot;j++){
            cout<<"["<<i<<"]["<<j<<"]:";
            cin>>phantu[i][j];
        }
    }
}
void matran::xuat(){
    for(int i=0;i<sohang;i++){
        for(int j=0;j<socot;j++){
            cout<<setw(10)<<left<<phantu[i][j];
        }
        cout<<endl;
    }
}
int main(){
    int hang,cot;
    matran a;
    matran b;
    do{
        cout<<"nhap hang:";
        cin>>hang;
        cout<<"nhap cot:";
        cin>>cot;
    }while(hang==0||cot==0);
    cout<<"nhap ma tran 1:"<<endl;
    a.nhap(hang,cot);
    cout<<"nhap ma tran 2:"<<endl;
    b.nhap(hang,cot);
    cout<<"ma tran 1:"<<endl;
    a.xuat();
    cout<<"ma tran 2:"<<endl;
    b.xuat();
    cout<<"cong 2 ma tran:"<<endl;
    cong(a,b).xuat();
}