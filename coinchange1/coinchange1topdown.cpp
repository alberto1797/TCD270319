#include <iostream> // per cin e cout
#include <cstring> //per memset, se si vuole utilizzarlo per inizializzare dp a -1
using namespace std; // per evitare di scrivere std::cout e std::cin ogni volta
const int MAXN = 1005;
const int MAXM = 105;

int dp[MAXN]; 
int N,M;
int C[MAXM];

// Programmazione dinamica top down - metodo ricorsivo
int f(int n){
    if(n < 0) return N+1; 
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int ans = N+1;
    for(int i = 0; i < M; ++i)
        ans = min( f(n-C[i])+1, ans);
    return dp[n] = ans;
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
        dp[n] = -1;

   // Computo la risposta
    if(f(N) >= N+1)
        cout << "Impossibile!" << endl;
    else 
        cout << "Answer: " << f(N) << endl; // Il valore di f(N) è gia noto qua perchè è calcolato dentro l'if
}