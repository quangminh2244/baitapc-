#include<bits/stdc++.h>
using namespace std;
class nguoi{
    protected:
    string hoten;
    int namsinh;
    public:
    void nhap();
    void xuat();
};
void nguoi::nhap(){
    cout<<"ho ten:";
    cin.ignore();
    getline(cin,hoten);
    cout<<"nam sinh:";
    cin>>namsinh;
}
void nguoi::xuat(){
    cout<<setw(20)<<left<<hoten;
    cout<<setw(20)<<left<<namsinh;
}
class monhoc{
    protected:
    string tenmonhoc;
    float cc,kt,dt;
    void nhap();
    void xuat();
};
void monhoc::nhap(){
    cout<<"ten mon hoc:";
    cin.ignore();
    getline(cin,tenmonhoc);
    cout<<"diem chuyen can:";
    cin>>cc;
    cout<<"diem kiem tra:";
    cin>>kt;
    cout<<"diem thi:";
    cin>>dt;
}
void monhoc::xuat(){
    cout<<setw(20)<<left<<tenmonhoc;
    cout<<setw(20)<<left<<cc;
    cout<<setw(20)<<left<<kt;
    cout<<setw(20)<<left<<dt;
}
class sinhvien:public nguoi,public monhoc{
    private:
    string masv;
    float dtb;
	public:
	sinhvien();
    void nhap();
    void xuat();
	float getdtb();
	float getcc();
	float getkt();
	string getten();
	string getmsv();
	float tongdiem();
};
sinhvien::sinhvien(){
	hoten="";
	namsinh=0;
	tenmonhoc="";
	cc=0;
	kt=0;
	dt=0;
	masv="";
	dtb=0;
}
float sinhvien::tongdiem(){
	return cc+kt+dt;
}
float sinhvien::getdtb(){
	return dtb;
}
float sinhvien::getcc(){
	return cc;
}
float sinhvien::getkt(){
	return kt;
}
string sinhvien::getten(){
	return hoten;
}
string sinhvien::getmsv(){
	return masv;
}
void sinhvien::nhap(){
    nguoi::nhap();
    monhoc::nhap();
    cout<<"masv:";
    cin>>masv;
    cout<<"dtb:";
    cin>>dtb;
}
void sinhvien::xuat(){
    nguoi::xuat();
    monhoc::xuat();
    cout<<setw(20)<<left<<masv;
    cout<<setw(20)<<left<<dtb;
}
void nhap(int n,sinhvien sv[]){
    for(int i=0;i<n;i++){
        cout<<"nhap sinh vien "<<i+1<<endl;
        sv[i].nhap();
    }
}
void xuat(int n,sinhvien sv[]){
	cout<<setw(20)<<left<<"HO TEN"<<setw(20)<<left<<"NAM SINH"<<setw(20)<<left<<"TEN MON HOC"<<setw(20)<<left<<"DIEM CHUYEN CAN"<<setw(20)<<left<<"DIEM KIEM TRA"<<setw(20)<<left<<"DIEM THI"<<setw(20)<<left<<"MA SINH VIEN"<<setw(20)<<left<<"DIEM TRUNG BINH"<<endl;
	for(int i=0;i<n;i++){
		sv[i].xuat();
		cout<<endl;
	}
}
void sapxep(int n,sinhvien sv[]){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(sv[i].getdtb()<sv[j].getdtb()){
				sinhvien temp=sv[i];
                sv[i]=sv[j];
                sv[j]=temp;
			}
		}
	}
}
void camthi(int n,sinhvien sv[]){
	cout<<"DANH SACH SINH VIEN BI CAM THI:"<<endl;
	cout<<setw(20)<<left<<"HO TEN"<<setw(20)<<left<<"NAM SINH"<<setw(20)<<left<<"TEN MON HOC"<<setw(20)<<left<<"DIEM CHUYEN CAN"<<setw(20)<<left<<"DIEM KIEM TRA"<<setw(20)<<left<<"DIEM THI"<<setw(20)<<left<<"MA SINH VIEN"<<setw(20)<<left<<"DIEM TRUNG BINH"<<endl;
	for(int i=0;i<n;i++){
		if(sv[i].getcc()<5||sv[i].getkt()==0){
			sv[i].xuat();
			cout<<endl;
		}
	}
}
void timkiem(int n,sinhvien sv[]){
	int tmp=0;
	string key;
	cout<<"nhap ten hoac ma sinh vien de tim kiem sinh vien"<<endl;
    cin.ignore();
	getline(cin,key);
	for(int i=0;i<n;i++){
		if(key==sv[i].getten()||key==sv[i].getmsv()){
			if(tmp==0){
				cout<<"danh sach sinh vien da tim duoc:"<<endl;
				cout<<setw(20)<<left<<"HO TEN"<<setw(20)<<left<<"NAM SINH"<<setw(20)<<left<<"TEN MON HOC"<<setw(20)<<left<<"DIEM CHUYEN CAN"<<setw(20)<<left<<"DIEM KIEM TRA"<<setw(20)<<left<<"DIEM THI"<<setw(20)<<left<<"MA SINH VIEN"<<setw(20)<<left<<"DIEM TRUNG BINH"<<endl;
			}
			sv[i].xuat();
			cout<<endl;
			tmp++;
		}
	}
	if(tmp==0){
        cout<<"khong tim thay";
    }
}
void topsv(int n,sinhvien sv[]){
	sinhvien tmp;
	cout<<"SINH VIEN CO TONG DIEM CAO NHAT:"<<endl;
	for(int i=0;i<n;i++){
		if(tmp.tongdiem()<sv[i].tongdiem()){
			tmp=sv[i];
		}
	}
	cout<<setw(20)<<left<<"HO TEN"<<setw(20)<<left<<"NAM SINH"<<setw(20)<<left<<"TEN MON HOC"<<setw(20)<<left<<"DIEM CHUYEN CAN"<<setw(20)<<left<<"DIEM KIEM TRA"<<setw(20)<<left<<"DIEM THI"<<setw(20)<<left<<"MA SINH VIEN"<<setw(20)<<left<<"DIEM TRUNG BINH"<<endl;
	tmp.xuat();
}
int main(){
    int n;
    cout<<"nhap so luong sinh vien:";
    cin>>n;
    sinhvien sv[n];
    nhap(n,sv);
	sapxep(n,sv);
	xuat(n,sv);
	camthi(n,sv);
	timkiem(n,sv);
	topsv(n,sv);
}