#include<bits/stdc++.h>
using namespace std;
template<class kieudoituong>
class cuahang{
    public:
    virtual void nhap()=0;
    virtual void xuat()=0;
};
class xe:public cuahang<xe>{
    private:
    string tenxe;
    string mausac;
    public:
    void nhap();
    void xuat();
};
void xe::nhap(){
    cout<<"Nhap ten xe: ";
    getline(cin,tenxe);
    cout<<"Nhap mau sac: ";
    getline(cin,mausac);
}
void xe::xuat(){
    cout<<setw(15)<<left<<tenxe;
    cout<<setw(15)<<left<<mausac;
}
class dienthoai:public cuahang<dienthoai>{
    private:
    string tendt;
    string madt;
    public:
    void nhap();
    void xuat();
};
void dienthoai::nhap(){
    cout<<"Nhap ten dien thoai: ";
    getline(cin,tendt);
    cout<<"Nhap ma dien thoai: ";
    getline(cin,madt);
}
void dienthoai::xuat(){
    cout<<setw(15)<<left<<tendt;
    cout<<setw(15)<<left<<madt;
}
template<class doituong>
class quanlihang{
    int sl;
    cuahang<doituong> **dt;
    public:
    void nhap(int soluong){
        sl=soluong;
        dt=new cuahang<doituong>*[sl];
        for(int i=0;i<sl;i++){ 
            if(is_same<doituong,xe>::value){
                cout<<"nhap xe "<<i+1<<endl;
            }else{
                cout<<"nhap dien thoai "<<i+1<<endl;
            }
            dt[i] = new doituong;
            dt[i]->nhap();
        }
    }
    void xuat(){
        if(is_same<doituong,xe>::value){
                cout<<setw(15)<<left<<"TEN XE"<<setw(15)<<left<<"MAU SAC"<<endl;
            }else{
                cout<<setw(15)<<left<<"TEN DTHOAI"<<setw(15)<<left<<"MA DTHOAI"<<endl;
            }
        for(int i=0;i<sl;i++){
            dt[i]->xuat();
            cout<<endl;
        }
    }
};
int main(){
    int xeoto,dt;
    quanlihang<xe> xe;
    quanlihang<dienthoai> dienthoai;
    cout<<"nhap so luong xe o to:";
    cin>>xeoto;
    cin.ignore();
    xe.nhap(xeoto);
    cout<<"nhap so luong dien thoai:";
    cin>>dt;
    cin.ignore();
    dienthoai.nhap(dt);
    cout<<"-----XE O TO-----"<<endl;
    xe.xuat();
    cout<<"-----DIEN THOAI-----"<<endl;
    dienthoai.xuat();
}