class disjoint_set{
    vector<int> fa;
    public:
    disjoint_set()=default;
    disjoint_set(int n){resize(n);}
    int size()const{return fa.size();}
    void reset(){fill(fa.begin(),fa.end(),-1);}
    void resize(int n){fa.resize(n);reset();}
    int find(int x){
        if(fa[x]<0)return x;
        return fa[x]=find(fa[x]);
    }
    int setsize(int x){return -fa[find(x)];}
    void merge(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        if(fa[x]<fa[y])swap(x,y);
        fa[y]+=fa[x];
        fa[x]=y;
    }
    void merge_in_order(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        fa[y]+=fa[x];
        fa[x]=y;
    }
};