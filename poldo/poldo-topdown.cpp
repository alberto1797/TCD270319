#include <iostream> // per cin e cout
#include <cstring> //per memset, se si vuole utilizzarlo per inizializzare dp a -1
using namespace std; // per evitare di scrivere std::cout e std::cin ogni volta
const int MAXN = 1005;

int dp[MAXN]; 
int W[MAXN];
int N;

// Programmazione dinamica top down - metodo ricorsivo
// Servono long long perchè il numero di combinazioni potrebbe non stare dentro un int
int f(int n){
    if(dp[n] != -1) return dp[n];
    int ans = 0;
    for(int i = n+1; i < N; ++i)
        if(W[i] < W[n])
            ans = max(ans, 1+f(i));
    return dp[n] = ans;
}

int main(){
    // Leggo l'input
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> W[i];

    // Inizializziamo i valori della tabella di dp a -1 -> -1 = non ho ancora calcolato la soluzione
    // memset(dp,-1,sizeof(dp));
    for(int n = 0; n <= N; ++n)
        dp[n] = -1;

   // Computo la risposta
   int ans = 0;
   for(int i = 0; i < N; ++i)
        ans = max(ans, f(i)+1);
   cout << "Answer: " << ans << endl;    
}