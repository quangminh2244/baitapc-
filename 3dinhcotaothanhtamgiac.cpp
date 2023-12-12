#include<bits/stdc++.h>
using namespace std;
class diem{
    private:
    int x,y;
    public:
    void nhap();
    void xuat();
    friend float dodai(diem a,diem b);
};
class tamgiac{
    private:
    diem a,b,c;
    float canha,canhb,canhc;
    public:
    void nhap();
    void xuat();
    void dodai3canh(float &A,float &B,float &C);
};
void diem::nhap(){
    cout<<"x=";
    cin>>x;
    cout<<"y=";
    cin>>y;
}
void diem::xuat() {
    cout<<"("<<x<<","<<y<<")"<<endl;
}
float dodai(diem a,diem b){
    return sqrt(pow(b.x-a.x,2) + pow(b.y-a.y,2));
}
void tamgiac::nhap(){
    cout<<"nhap 3 diem cua tam giac:"<<endl;
    cout<<"diem A"<<endl;
    a.nhap();
    cout<<"diem B"<<endl;
    b.nhap();
    cout<<"diem C"<<endl;
    c.nhap();
}
void tamgiac::xuat(){
    cout<<"A";
    a.xuat();
    cout<<"B";
    b.xuat();
    cout<<"C";
    c.xuat();
}
void tamgiac::dodai3canh(float &A,float &B,float &C){
    A=canha=dodai(a,b);
    B=canhb=dodai(b,c);
    C=canhc=dodai(a,c);
}
void kiemtra(float A,float B,float C){
    if(A==B&&A==C&&B==C){
        cout<<"3 diem tao thanh tam giac deu";
    }else{
        if(A==B||B==C||C==A){
            if(abs(A*A+B*B-C*C)<0.0001||abs(A*A+C*C==B*B)<0.0001||abs(B*B+C*C==A*A)<0.0001){
                cout<<"3 diem tao thanh tam giac vuong can";
            }else{
                cout<<"3 diem tao thanh tam giac can";
            }
        }else{
            if(abs(A*A+B*B-C*C)<0.0001||abs(A*A+C*C==B*B)<0.0001||abs(B*B+C*C==A*A)<0.0001){
                cout<<"3 diem tao thanh tam giac vuong";
            }else{
                cout<<"day la tam giac thuong";
            }
        }
    }
}
int main(){
    tamgiac a;
    float A,B,C;
    a.nhap();;
    a.xuat();
    a.dodai3canh(A,B,C);
    kiemtra(A,B,C);
    return 0;
}