#include<bits/stdc++.h>
using namespace std;
class diem{
    private:
    float x,y;
    public:
    friend istream& operator >> (istream &in,diem &a);
    friend double khoangcach(diem a,diem b);
    friend ostream& operator << (ostream &out,diem a);
};
class tamgiac{
    private:
    diem a,b,c;
    public:
    friend istream& operator >>(istream &in,tamgiac &t);
    friend ostream& operator <<(ostream &out,tamgiac t);
    friend void dodai(tamgiac t,double &a,double &b,double &c);
};
istream& operator >> (istream &in,diem &a){
    cout<<"x=";
    in>>a.x;
    cout<<"y=";
    in>>a.y;
    return in;
}
ostream& operator << (ostream &out,diem a){
    out<<"("<<a.x<<","<<a.y<<")";
    return out;
}
istream& operator >> (istream &in,tamgiac &t){
    cout<<"nhap diem A:"<<endl;
    in>>t.a;
    cout<<"nhap diem B:"<<endl;
    in>>t.b;
    cout<<"nhap diem C:"<<endl;
    in>>t.c;
    return in;
}
ostream& operator <<(ostream &out,tamgiac t){
    out<<"3 dinh cua tam giac la :"<<endl;;
    out<<"A"<<t.a<<endl;
    out<<"B"<<t.b<<endl;
    out<<"C"<<t.c<<endl;
    return out;
}
double khoangcach(diem a,diem b){
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
void dodai(tamgiac t,double &a,double &b,double &c){
    a=khoangcach(t.a,t.b);
    b=khoangcach(t.b,t.c);
    c=khoangcach(t.a,t.c);
}
string kiemtra(double a,double b,double c){
    if(a+b>c&&a+c>b&&b+c>a){
        if(a==b||b==c||a==c){
            if(a==b&&b==c&&a==c){
                return "day la tam giac deu";
            }else{
                if(abs(a*a+b*b-c*c)<0.0001||abs(a*a+c*c-b*b)<0.0001||abs(b*b+c*c-a*a)<0.0001){
                    return "day la tam giac vuong can";
                }else{
                    return "day la tam giac can";
                }
            }
        }else{
            if(abs(a*a+b*b-c*c)<0.001||abs(a*a+c*c-b*b)<0.001||abs(b*b+c*c-a*a)<0.001){
                return "day la tam giac vuong";
            }else{
                return "day la tam giac thuong";
            }
        }
    }else{
        return "3 canh khong tao thanh tam giac";
    }
}
int main(){
    tamgiac t;
    double a,b,c;
    cout<<endl<<"nhap tam giac ABC"<<endl;
    cin>>t;
    cout<<endl<<t;
    dodai(t,a,b,c);
    cout<<kiemtra(a,b,c);
}