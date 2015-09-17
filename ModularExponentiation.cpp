ll mod_pow(ll base,ll exp,ll mod)
{
    ll res=1;
    while(exp>0)
    {
        if(exp&1)
        {
            res=(res*base)%mod;
        }
        exp=exp>>1;
        base=(base*base)%mod;
    }
    return res;
}
