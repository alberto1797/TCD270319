#include <iostream> // per cin e cout
#include <cstring> //per memset, se si vuole utilizzarlo per inizializzare dp a -1
using namespace std;  // per evitare di scrivere std::cout e std::cin ogni volta

int N;
const int MAXN = 105;
long long dp[MAXN];

// programmazione dinamica top down - metodo ricorsivo
// servono long long perchè il risultato potrebbe non stare dentro un int
long long f(int n){
    if(n==0) return 0ll;
    if(n==1) return 1ll;
    if(dp[n] != -1ll) return dp[n];
    return dp[n] = f(n-1) + f(n-2);
}

int main(){
    // Leggo l'input
    cin >> N;

    // Inizializziamo i valori della tabella di dp a -1 -> -1 = non ho ancora calcolato la soluzione
    // memset(dp,-1,sizeof(dp));
    for(int n = 0; n<= N; ++n)
        dp[n] = -1;

    // Stampo la risposta
    cout << "Answer: " << f(N) << endl;
}