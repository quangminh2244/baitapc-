#include<bits/stdc++.h>
#include<cctype>
using namespace std;
class nguoi{
    protected:
    string hoten;
    int namsinh;
    public:
    nguoi();
};
nguoi::nguoi(){
    hoten=" ";
    namsinh=0;
}
class sinhvien:public nguoi{
    private:
    string msv;
    int dtb;
    public:
    sinhvien();
    friend istream& operator>>(istream& in,sinhvien &sv);
    friend ostream& operator<<(ostream& out,sinhvien sv);
    string get_hoten();
    string get_msv();
};
sinhvien::sinhvien(){
    msv=" ";
    dtb=0;
}
string sinhvien::get_msv(){
    return msv;
}
string sinhvien::get_hoten(){
    return hoten;
}
istream& operator>>(istream& in,sinhvien &sv){
    cout<<"ho ten:";
    fflush(stdin);
    getline(in,sv.hoten);
    for(char &c:sv.hoten){
            c=toupper(c);
        }
    cout<<"nam sinh:";
    in>>sv.namsinh;
    cout<<"ma sinh vien:";
    fflush(stdin);
    getline(in,sv.msv);
    for(char &c:sv.msv){
            c=toupper(c);
        }
    cout<<"deim trung binh:";
    in>>sv.dtb;
    return in;
}
ostream& operator<<(ostream& out,sinhvien sv){
    cout<<setw(20)<<left<<sv.hoten<<setw(20)<<left<<sv.namsinh<<setw(20)<<left<<sv.msv<<setw(20)<<left<<sv.dtb<<endl;
    return out;
}
void nhap(int n,sinhvien sv[]){
    for(int i=0;i<n;i++){
        cout<<endl<<"----sinh vien----"<<i+1<<endl;
        cin>>sv[i];
    }
}
void xuat(int n,sinhvien sv[]){
    cout<<endl<<"danh sach sinh vien:"<<endl;
    cout<<setw(20)<<left<<"ho ten"<<setw(20)<<left<<"nam sinh"<<setw(20)<<left<<"ma sinh vien"<<setw(20)<<left<<"diem trung binh"<<endl;
    for(int i=0;i<n;i++){
        cout<<sv[i]<<endl;
    }
}
void timkiem(int n,sinhvien sv[]){
    int tmp=0;
    string tmp1=" ";
    int test=0;
    cout<<"nhap thong tin tim kiem:"<<endl;
    cout<<"chon:"<<endl;
    cout<<"1: tim kiem bang ma sinh vien"<<endl<<"2: tim kiem bang ho ten"<<endl;
    cin>>tmp;
    if(tmp==2){
        cout<<"nhap ten nguoi can tim: ";
        fflush(stdin);
        getline(cin,tmp1);
        for(char &c:tmp1){
            c=toupper(c);
        }
        for(int i=0;i<n;i++){
            if(sv[i].get_hoten()==tmp1){
                cout<<sv[i];
                test++;

            }
        }
        if(test==0){
                cout<<"khong tim thay sinh vien.";
            }
    }
    if(tmp==1){
        cout<<"nhap ma sinh vien can tim: ";
        cin>>tmp1;
        for(char &c:tmp1){
            c=toupper(c);
        }
        for(int i=0;i<n;i++){
            if(sv[i].get_msv()==tmp1){
                cout<<sv[i];
                test++;
            }
        }
        if(test==0){
                cout<<"khong tim thay sinh vien.";
            }
    }
}
int main(){
    int n;
    cout<<"nhap so luong sinh vien:";
    cin>>n;
    sinhvien sv[n];
    nhap(n,sv);
    xuat(n,sv);
    timkiem(n,sv);
}
