#include <iostream> // per cin e cout
#include <cstring> //per memset, se si vuole utilizzarlo per inizializzare dp a -1
using namespace std; // per evitare di scrivere std::cout e std::cin ogni volta
const int MAXN = 1005;
const int MAXM = 105;

long long dp[MAXN][MAXM]; 
int N,M;
int C[MAXM];

// Programmazione dinamica top down - metodo ricorsivo
// Servono long long perchè il numero di combinazioni potrebbe non stare dentro un int
long long f(int n, int i){
    if(i < 0) return 0ll; 
    if(n == 0) return 1ll;
    if(dp[n][i] != -1) return dp[n][i];
    if(n < C[i]) return dp[n][i] = f(n,i-1);
    return dp[n][i] = f(n,i-1) + f(n - C[i],i);
}

int main(){
    // Leggo l'input
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; ++i)
        cin >> C[i];

   // Inizializziamo i valori della tabella di dp a -1 -> -1 = non ho ancora calcolato la soluzione
    // memset(dp,-1,sizeof(dp));
    for(int n = 0; n <= N; ++n)
        for(int i = 0; i <= M; ++i)
            dp[n][i] = -1;
    
    // Computo la risposta
    cout << "Answer: " << f(N,M-1) << endl;
}