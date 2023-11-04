template <int mod>
class modint{
    int val;
    public:
    static int norm(int x){return x<0?x%mod+mod:x%mod;}
    modint(const int &x=0){val=norm(x);}
    explicit operator int()const{return val;}
    modint operator-()const{return val?mod-val:0;}
    bool operator==(const modint &o)const{return val==o.val;}
    bool operator!=(const modint &o)const{return val!=o.val;}
    modint operator+(const modint &o)const{return (val+o.val)%mod;}
    modint operator-(const modint &o)const{return norm(val-o.val);}
    modint operator*(const modint &o)const{return (long long)val*o.val%mod;}
    friend modint operator+(int x,const modint &y){return modint(x)+y;}
    friend modint operator-(int x,const modint &y){return modint(x)-y;}
    friend modint operator*(int x,const modint &y){return modint(x)*y;}
    modint &operator+=(const modint &o){return *this=*this+o;}
    modint &operator-=(const modint &o){return *this=*this-o;}
    modint &operator*=(const modint &o){return *this=*this*o;}
    modint &operator++(){return *this+=1;}
    modint &operator--(){return *this-=1;}
    modint operator++(int){modint ret=*this;++*this;return ret;}
    modint operator--(int){modint ret=*this;--*this;return ret;}
    friend istream &operator>>(istream &is,modint &a){
        int x;
        return is>>x,a=x,is;
    }
    friend ostream &operator<<(ostream &os,const modint &a){return os<<a.val;}
};