    #include<bits/stdc++.h>
    using namespace std;
    class ps{
    private:
        int ts,ms;
    public:
        ps();
        ps(int a,int b);
        friend istream& operator>>(istream &in,ps &a);
        friend ostream& operator<<(ostream &out,ps a);
        friend ps operator+(ps a,ps b);
        friend ps operator-(ps a,ps b);
        friend int gcd(ps a);
        ps rutgon();
        friend float tofloat(ps a);
    };
    float tofloat(ps a){
        return a.ts/a.ms;
    }
    ps::ps(){
        ts=0;
        ms=0;
    }
    ps::ps(int a,int b){
        ts=a;
        ms=b;
    }
    ps operator + (ps a,ps b){
        ps kq;
        kq.ts=a.ts*b.ms+a.ms*b.ts;
        kq.ms=a.ms*b.ms;
        return kq;
    }
    ps operator-(ps a,ps b){
        ps kq;
        kq.ts=a.ts*b.ms-a.ms*b.ts;
        kq.ms=a.ms*b.ms;
        return kq;
    }
    istream& operator>>(istream &in,ps &a){
        cout<<"nhap tu:";
        in>>a.ts;
        cout<<"nhap mau:";
        in>>a.ms;
        return in;
    }
    ostream& operator<<(ostream &out,ps a){
        out<<a.ts<<"/"<<a.ms<<endl;
        return out;
    }
    void nhap(ps a[100],int &n){
        cout<<"nhap so luong phan tu:";
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"a["<<i<<"]:"<<endl;
            cin>>a[i];
        }
    }
    void xuat(ps a[100],int n){
        cout<<"cac phan tu da nhap:"<<endl;
        for(int i=0;i<n;i++){
            cout<<"a["<<i<<"]="<<a[i];
        }
    }
    int gcd(ps a){
        return gcd(a.ts,a.ms);
    }
    ps ps::rutgon(){
        ps c;
        c.ts=this->ts/gcd(this->ts,this->ms);
        c.ms=this->ms/gcd(this->ts,this->ms);
        return c;
    }
    void sosanh(const ps a[100],int n){
        float b=0;
        int temp=0;
        for(int i=0;i<n;i++){
            if(b<=tofloat(a[i])){
                temp=i;
                b=tofloat(a[i]);
            }
        }
        cout<<a[temp];
    }
    int main(){
        ps a[100];
        int n;
        cout<<"nhap phan so a"<<endl;cin>>a[1];
        a[1]=a[1].rutgon();
        cout<<"phan so sau khi rut gon:"<<endl<<a[1];
        cout<<"nhap phan so b"<<endl;cin>>a[2];
        a[2]=a[2].rutgon();
        cout<<"phan so sau khi rut gon:"<<endl<<a[2];
        cout<<"2 phan so vua nhap la:"<<endl;
        cout<<a[1];
        cout<<a[2]<<endl;
        a[3]=a[1]+a[2];
        cout<<"a+b="<<a[3]<<endl;
        a[3]=a[1]-a[2];
        cout<<"a-b="<<a[3]<<endl;
        cout<<"=========================================================================="<<endl;
        nhap(a,n);
        xuat(a,n);
        cout<<"phan so lon nhat la:";
        sosanh(a,n);
    }
