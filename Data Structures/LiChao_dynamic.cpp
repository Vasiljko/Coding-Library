/*~~~~~~~~~~~~~~~~~~~~~~~~~~~ Li Chao max ~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

template<ll SZ>
struct LiChao_max{
    struct Line{
        ll k,m;
        Line(){k=0,m=0;}
        Line(ll _k,ll _m){k=_k,m=_m;}
        ll Get(ll x){return k*x+m;}
    };

    struct node{
        node *l, *r;
        Line p;

        node(){p=Line(),l=nullptr,r=nullptr;}
        node(ll k,ll m){p=Line(k,m),l=nullptr,r=nullptr;}
        node(Line _p){p=_p,l=nullptr,r=nullptr;}
    };
    typedef node* pnode;

    pnode root=nullptr;
    
    void Reset(){root=nullptr;}
    void Set(ll k,ll m){
        Line p = Line(k,m);
        Set(root,0,SZ,p);
    }
    void Set(Line p){
        Set(root,0,SZ,p);
    }
    ll Get(ll x){return Get(root,0,SZ,x);}

    void Set(pnode &v,ll ss,ll se,Line t){
        if(!v){
            v = new node(t);
            return;
        }

        if(t.Get(ss)>v->p.Get(ss)&&t.Get(se)>v->p.Get(se)){v->p=t;return;}
        if(t.Get(ss)<=v->p.Get(ss)&&t.Get(se)<=v->p.Get(se))return;

        ll mid=(ss+se)>>1LL;

        if(t.Get(ss)<v->p.Get(ss)&&t.Get(mid)>v->p.Get(mid)){
            swap(t,v->p);
            Set(v->l,ss,mid,t);
        }else if(t.Get(ss)<v->p.Get(ss)&&t.Get(mid)<v->p.Get(mid)){
            Set(v->r,mid+1,se,t);
        }else if(t.Get(ss)>v->p.Get(ss)&&t.Get(mid)<v->p.Get(mid)){
            Set(v->l,ss,mid,t);
        }else{
            swap(t,v->p);
            Set(v->r,mid+1,se,t);
        }
    }

    ll Get(pnode &v,ll ss,ll se,ll x){
        if(v==nullptr)return -INF;
        if(ss==se)return v->p.Get(x);

        ll mid=(ss+se)>>1LL;
        if(x<=mid)return max(v->p.Get(x),Get(v->l,ss,mid,x));
        return max(v->p.Get(x),Get(v->r,mid+1,se,x));
    }
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~ Li Chao min ~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

template<int SZ>
struct LiChao_min{
    struct Line{
        ll k,m;
        Line(){k=0,m=0;}
        Line(ll _k,ll _m){k=_k,m=_m;}
        ll Get(ll x){return k*x+m;}
    };

    struct node{
        node *l, *r;
        Line p;

        node(){p=Line(),l=nullptr,r=nullptr;}
        node(ll k,ll m){p=Line(k,m),l=nullptr,r=nullptr;}
        node(Line _p){p=_p,l=nullptr,r=nullptr;}
    };
    typedef node* pnode;

    pnode root = nullptr;

    void Reset(){root=nullptr;}
    void Set(ll k,ll m){
        Line p = Line(k,m);
        Set(root,0,SZ,p);
    }
    void Set(Line p){
        Set(root,0,SZ,p);
    }
    ll Get(ll x){return Get(root,0,SZ,x);}

    void Set(pnode &v,ll ss,ll se,Line t){
        if(!v){
            v = new node(t);
            return;
        }

        if(t.Get(ss)<v->p.Get(ss)&&t.Get(se)<v->p.Get(se)){v->p=t;return;}
        if(t.Get(ss)>=v->p.Get(ss)&&t.Get(se)>=v->p.Get(se))return;

        ll mid=(ss+se)>>1LL;

        if(t.Get(ss)>v->p.Get(ss)&&t.Get(mid)<v->p.Get(mid)){
            swap(t,v->p);
            Set(v->l,ss,mid,t);
        }else if(t.Get(ss)>v->p.Get(ss)&&t.Get(mid)>v->p.Get(mid)){
            Set(v->r,mid+1,se,t);
        }else if(t.Get(ss)<v->p.Get(ss)&&t.Get(mid)>v->p.Get(mid)){
            Set(v->l,ss,mid,t);
        }else{
            swap(t,v->p);
            Set(v->r,mid+1,se,t);
        }
    }

    ll Get(pnode &v,ll ss,ll se,ll x){
        if(v==nullptr)return INF;
        if(ss==se)return v->p.Get(x);

        ll mid=(ss+se)>>1LL;
        if(x<=mid)return min(v->p.Get(x),Get(v->l,ss,mid,x));
        return min(v->p.Get(x),Get(v->r,mid+1,se,x));
    }
};



