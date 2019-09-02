int Binsearch(int i , int j , int k , int a[])
{
    int l = i , r  =  j , tmp = 0 ;
    int m = (l+r)/2;
    while (l <=  r)
    {
        if (a[m] < k)
        {
            l = m + 1;
            tmp = m ;
        }
        else
            if (a[m] == k) return m ;
        else
            if (a[m] > k) r = m - 1;
            m =(l +r)/2;
    }
    return tmp;
}

    REP(i,1,n-1)
    REP(j,i+1,n)
        {
            int k = Binsearch(1,n,m-(a[i]+a[j]),a);
            if (m >= (a[i] + a[j] + a[k]) && i != k && j != k) re =max(re,a[i]+a[j]+a[k]) ;
            else break;
        }
    write(re);
}