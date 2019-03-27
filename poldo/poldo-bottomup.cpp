#include <iostream> // per cin e cout
using namespace std; // per evitare di scrivere std::cout e std::cin ogni volta
const int MAXN = 1005;

int dp[MAXN]; 
int W[MAXN];
int N;

int main(){
    // Leggo l'input
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> W[i];

    // Programmazione dinamica - BOTTOM UP
    for(int n = N-1; n >= 0; --n){
        dp[n] = 0;
        for(int i = n+1; i < N; ++i)
            if(W[i]<W[n])
                dp[n] = max(dp[n],dp[i]+1);
    }

   // Computo la risposta
   int ans = 0;
   for(int i = 0; i < N; ++i)
        ans = max(ans, dp[i]+1);
   cout << "Answer: " << ans << endl;    
}