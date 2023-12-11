#include<bits/stdc++.h>
using namespace std;
class matranvuong{
    private:
    int capmatran;
    vector<vector<float>> matran;
    public:
    void nhap();
    void xuat();
    float tongcheochinh();
    float tongcheophu();
};
void matranvuong::nhap(){
    cout<<"nhap cap ma tran:";
    cin>>capmatran;
    matran.resize(capmatran,vector<float>(capmatran,0));
    cout<<"Nhap matran:"<<endl;
    for(int i=0; i<capmatran;i++){
        for(int j=0; j<capmatran;j++){
            cout<<"a["<<i<<"]["<<j<<"]:";
            cin>>matran[i][j];
        }
    }
}
void matranvuong::xuat(){
    for(int i=0; i<capmatran;i++){
        for(int j=0; j<capmatran;j++){
            cout<<setw(10)<<left<<matran[i][j];
        }
        cout<<endl;
    }
}
float matranvuong::tongcheochinh(){
    float tong=0;
    for(int i=0;i<capmatran;i++){
        tong+=matran[i][i];
    }
    return tong;
}
float matranvuong::tongcheophu(){
    float tong=0;
    for(int i=0;i<capmatran;i++){
        tong+=matran[i][capmatran-i-1];
    }
    return tong;
}
int main(){
    matranvuong mtv;
    mtv.nhap();
    mtv.xuat();
    cout<<"tong cac phan tu nam tren duong cheo chinh:"<<mtv.tongcheochinh();
    cout<<"tong cac phan tu nam tren duong cheo phu:"<<mtv.tongcheophu();
    return 0;
}