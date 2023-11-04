template <typename Tp,typename Op=plus<Tp>>
class fenwick{
    Op op;
    vector<Tp> c;
    public:
    fenwick(int n=0){resize(n);}
    int size()const{return c.size();}
    void resize(int n){c.assign(n,Tp{});}
    void fill(const Tp &x){fill(c.begin(),c.end(),x);}
    Tp query(int x,Tp def=Tp{}){
        Tp ret=def;
        while(x>=0){
            ret=op(ret,c[x]);
            x-=x+1&-x-1;
        }
        return ret;
    }
    void modify(int x,const Tp &k){
        while(x<c.size()){
            c[x]=op(c[x],k);
            x+=x+1&-x-1;
        }
    }
};