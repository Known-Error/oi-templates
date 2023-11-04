template<typename Key,typename Tp,typename Cmp>
class monotonic_map{
    Cmp cmp;
    map<Key,Tp> mp;
    public:
    monotonic_map(Tp df){mp[numeric_limits<Key>::min()]=df;}
    Tp query(Key x){return prev(mp.upper_bound(x))->second;}
    void update(Key x,Tp k){
        if(!cmp(k,query(x)))return;
        mp[x]=k;
        auto it=next(mp.find(x));
        while(it!=mp.end()){
            auto ls=it++;
            if(cmp(k,ls->second))mp.erase(ls);
            else break;
        }
    }
};