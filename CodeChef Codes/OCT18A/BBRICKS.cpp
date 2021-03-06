// https://www.codechef.com/OCT18Aproblems/BBRICKS

#include <bits/stdc++.h>
using namespace std; 

typedef unsigned long long ul ;
typedef long long ll ;

typedef pair < int , int >  pii ;
typedef pair < ll , ll>  pll ;
typedef pair < ll , pll > edge ; 
typedef vector < int > vi ;
typedef vector < ll > vll ;
typedef vector < pll > vp ;

#define MOD 1000000007 
#define vec vector    
#define nl '\n' 
#define is == 
#define all(v) (v).begin() , (v).end() 
#define sz(v)  (long long)(v).size() 
#define lp(i , n ) for ( ll i = 0 ; i < n ; i++ )
#define lp1(i , n ) for ( ll i = 1 ; i <= n ; i++ )
#define lpp(i , n ) for ( ll i = n-1 ; i >= 0 ; i-- )
#define rep(i , a , b , n) for(ll i = a; i < b ; i += n )
#define repp(i , a , b , n) for(ll i = b-1 ; i >= a ; i -= n )      
#define umap unordered_map 

#define f first 
#define s second
#define pb push_back
#define mp make_pair

#define tc(t) ul testcases ; cin>>testcases ; for ( int t = 1 ; t <= testcases ; t++ )
#define inarr(n) vll v ( n , 0 ) ; lp ( i , n) cin>>v[i]  

#define fast ios::sync_with_stdio(false); cin.tie(0);

#define mini ( a , b )  ( (a) > (b) ? (b) : (a) ) 
#define maxi ( a , b )  ( (a) < (b) ? (b) : (a) ) 

// Array for factorials maybe .
vector < unsigned long long > factorial = { 1 , 1 , 2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880 , 3628800 , 39916800 ,  
479001600 , 6227020800 , 87178291200, 1307674368000 , 20922789888000 , 355687428096000 , 6402373705728000    } ; // 18! tak hai 

ll modInv ( ll base )
{
    ll expo = MOD - 2 ; 
    ll ans = 1 ; 
    while ( expo )
    {
        if ( expo&1 )
        {
            ans = ( ans * base ) % MOD ; 
        }
        expo>>=1 ; 
        base = ( base * base ) % MOD ; 
    }
    return ans ; 
}

int main () 
{
    fast     

    vll pow2(1000+1,1) ;
    lp1 ( i , 1000 )
    {
        pow2[i] = ( pow2[i-1] * 2 ) % MOD ; 
    } 

    vll fact(1000+1,1) ;
    lp1 ( i , 1000 )
    {
        fact[i] = ( fact[i-1] * i ) % MOD ; 
    } 

    vll factI(1000+1,1) ;
    lp1 ( i , 1000 )
    {
        factI[i] = modInv(fact[i]) ;
    }

    tc(t)
    {
        ll n , k  ;
        cin>>n>>k ; 

        ll x = n - k + 1 ; 

        ll ans = 0 ;
        ll term1 , term2 ;  

        lp1 ( i , min(k,x) )
        {    
            term1 = fact[k-1] ;                             //cout<<term1<<"_" ; 
            term1 = (term1 * factI[i-1]   ) % MOD ;         //cout<<term1<<"_" ; 
            term1 = (term1 * factI[k-i] ) % MOD ;           //cout<<term1<<" " ;             
                       
            term1 = (term1 * pow2[i] )    % MOD ;           //cout<<term1<<" " ;   
            
            term2 = 1 ; 
            lp ( j , i )
            {
                term2 = ( term2 * (x-j) ) % MOD ; 
            }
                                                            //cout<<term2<<" " ; 
            term2 = ( term2 * factI[i] ) % MOD ;             
            
                    //cout<<term2<<" " ; 
            
            ans = (ans + ( term1 * term2 ) % MOD ) % MOD ;  //cout<<ans<<" "<<endl ; 
        }
        cout<<ans<<endl ; 
    }
    return 0 ; 

}
