#include<bits/stdc++.h>
using namespace std;
class mtv{
    private:
    int capmatran;
    float phantu[100][100];
    public:
    void nhap();
    void xuat();
    friend float tongchinh(mtv a);
    friend float tongphu(mtv a);
};
void mtv::nhap(){
    cout<<"ma tran cap:";
    cin>>capmatran;
    cout<<"nhap ma tran"<<endl;
    for(int i=0;i<capmatran;i++){
        for(int j=0;j<capmatran;j++){
            cout<<"a["<<i<<"]["<<j<<"]=";
            cin>>phantu[i][j];
        }
    }
}
void mtv::xuat(){
    cout<<endl<<"ma tran vua nhap:"<<endl;
    for(int i=0;i<capmatran;i++){
        for(int j=0;j<capmatran;j++){
            cout<<setw(5)<<left<<phantu[i][j];
            if(j!=capmatran-1){
                cout<<"| ";
            }
    }
    cout<<endl;
    }
}
float tongchinh(mtv a){
    float tong=0;
    for(int i=0;i<a.capmatran;i++){
        tong=tong+a.phantu[i][i];
    }
    return tong;
}
float tongphu(mtv a){
    float tong;
    for(int i=0;i<a.capmatran;i++){
        tong=tong+a.phantu[3-i][0+i];
    }
    return tong;
}
int main(){
    mtv a;
    a.nhap();
    a.xuat();
    cout<<endl<<"tong cac phan tu tren duong cheo chinh="<<tongchinh(a);
    cout<<endl<<"tong cac phan tu tren duong cheo phu="<<tongphu(a);
}