#include<bits/stdc++.h>
using namespace std;
class monhoc{
    protected:
    string tenmonhoc;
    float cc,kt,dt;
    public:
};

class sinhvien:public monhoc{
    private:
    string hoten,lop,masv;
    public:
    void nhap();
    void xuat();
    int camthi();
};
int sinhvien::camthi(){
    if(cc<5||kt==0){
        return 1;
    }else{
        return 0;
    }
}
void sinhvien::nhap(){
    cout<<"nhap ho ten:";
    cin.ignore();
    getline(cin,hoten);
    cout<<"nhap lop:";
    getline(cin,lop);
    cout<<"nhap ma sinh vien:";
    getline(cin,masv);
    cout<<"nhap ten mon hoc:";
    getline(cin,tenmonhoc);
    cout<<"diem chuyen can:";
    cin>>cc;
    cout<<"diem kiem tra:";
    cin>>kt;
    cout<<"diem thi:";
    cin>>dt;
}
void sinhvien::xuat(){
    cout<<setw(20)<<left<<hoten;
    cout<<setw(20)<<left<<lop;
    cout<<setw(20)<<left<<masv;
    cout<<setw(20)<<left<<tenmonhoc;
    cout<<setw(20)<<left<<cc;
    cout<<setw(20)<<left<<kt;
    cout<<setw(20)<<left<<dt;
}
void nhap(int n,sinhvien sv[]){
    for(int i=0;i<n;i++){
        cout<<"nhap sinh vien "<<i+1<<endl;
        sv[i].nhap();
    }
}
void xuat(int n,sinhvien sv[]){
    cout<<"-------tong tin sinh vien---------"<<endl;
    cout<<setw(20)<<left<<"HO TEN";
    cout<<setw(20)<<left<<"LOP";
    cout<<setw(20)<<left<<"MA SINH VIEN";
    cout<<setw(20)<<left<<"TEN MON HOC";
    cout<<setw(20)<<left<<"DIEM CHUYEN CAN";
    cout<<setw(20)<<left<<"DIEM KIEM TRA";
    cout<<setw(20)<<left<<"DIEM TOAN";
    cout<<endl;
    for(int i=0;i<n;i++){
        sv[i].xuat();
        cout<<endl;
    }
}
void camthi(int n,sinhvien sv[]){
    int tmp=0;
    for(int i=0;i<n;i++){
        if(sv[i].camthi()){
            if(tmp==0){
                cout<<"danh sach sinh vien cam thi:"<<endl;
                cout<<setw(20)<<left<<"HO TEN";
                cout<<setw(20)<<left<<"LOP";
                cout<<setw(20)<<left<<"MA SINH VIEN";
                cout<<setw(20)<<left<<"TEN MON HOC";
                cout<<setw(20)<<left<<"DIEM CHUYEN CAN";
                cout<<setw(20)<<left<<"DIEM KIEM TRA";
                cout<<setw(20)<<left<<"DIEM TOAN";
                cout<<endl;
            }
            sv[i].xuat();
            cout<<endl;
            tmp++;
        }
    }
    if(tmp==0){
        cout<<"khong co sinh vien nao bi cam thi"<<endl;
    }
}
int main(){
    int n;
    cout<<"nhap vao so luong hoc sinh:";
    cin>>n;
    sinhvien sv[n];
    nhap(n,sv);
    xuat(n,sv);
    camthi(n,sv);
}
