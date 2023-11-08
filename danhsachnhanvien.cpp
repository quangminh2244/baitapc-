#include<bits/stdc++.h>
using namespace std;
class nhanvien{
    private:
    string hoten,chucvu,gioitinh,quequan;
    int namsinh,namvaolam;
    public:
    friend istream& operator>>(istream &in,nhanvien &nv);
    friend ostream& operator<<(ostream &out,nhanvien nv);
    int getnamlamviec();
    int getnamsinh();
    string getten();
    friend bool cmp(nhanvien a,nhanvien b);
};
string nhanvien::getten(){
    return hoten;
}
int nhanvien::getnamsinh(){
    return namsinh;
}
bool cmp(nhanvien a, nhanvien b){
    return a.getnamsinh()<b.getnamsinh();
}
int nhanvien::getnamlamviec(){
    return 2023-namvaolam;
}
istream& operator>>(istream &in,nhanvien &nv){
    fflush(stdin);
    cout<<"nhap ho ten:";
    getline(in,nv.hoten);
    cout<<"nhap chuc vu:";
    getline(in,nv.chucvu);
    cout<<"nhap gioi tinh:";
    getline(in,nv.gioitinh);
    fflush(stdin);
    cout<<"nhap nam sinh:";
    in>>nv.namsinh;
    cout<<"nhap que quan:";
    fflush(stdin);
    getline(in,nv.quequan);
    cout<<"nam vao lam viec:";
    fflush(stdin);
    in>>nv.namvaolam;
    fflush(stdin);
    return in;
}
ostream& operator<<(ostream &out,nhanvien nv){
    out<<setw(20)<<left<<nv.hoten<<setw(20)<<left<<nv.chucvu<<setw(20)<<left<<nv.gioitinh<<setw(20)<<left<<nv.namsinh<<setw(20)<<left<<nv.quequan<<setw(20)<<left<<nv.namvaolam<<endl;
    return out;
}
void nhap(nhanvien nv[],int n){
    for(int i=0;i<n;i++){
        cout<<"nhan vien:"<<i+1<<endl;
        cin>>nv[i];
    }
}
void xuat(nhanvien nv[],int n){
    cout<<setw(20)<<left<<"ten nhan vien"<<setw(20)<<left<<"chuc vu"<<setw(20)<<left<<"gioi tinh"<<setw(20)<<left<<"nam sinh"<<setw(20)<<left<<"que quan"<<setw(20)<<left<<"nam vao lam"<<endl;
    for(int i=0;i<n;i++){
        cout<<nv[i];
    }
}
void xuatnvvip(nhanvien nv[],int n){
    for(int i=0;i<n;i++){
        if(nv[i].getnamlamviec()>20){
            cout<<nv[i];
        }
    }
}
void sapxep(nhanvien nv[],int n){
    sort(nv,nv+n,cmp);
    cout<<endl<<"danh sach sau khi sap xep:"<<endl<<endl;
    xuat(nv,n);

}
void timnguoi(nhanvien nv[],int n){
    for(int i=0;i<n;i++){
        if(nv[i].getten()=="nguyen thi thom"){
            cout<<nv[i];
        }
    }
}
int main(){
    int n;
    cout<<"nhap tong so nhan vien: ";
    cin>>n;
    nhanvien nv[n];
    nhap(nv,n);
    xuat(nv,n);
    cout<<"nhan vien lam viec tren 20 nam:"<<endl;
    xuatnvvip(nv,n);
    sapxep(nv,n);
    cout<<"nhan vien co ho ten NGUYEN THI THOM :"<<endl<<endl;
    timnguoi(nv,n);

}