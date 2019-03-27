#include <iostream> // per cin e cout
#include <cstring> //per memset, se si vuole utilizzarlo per inizializzare dp a -1
using namespace std; // per evitare di scrivere std::cout e std::cin ogni volta
const int MAXN = 1005;
const int MAXM = 105;

int dp[MAXN]; 
int N,M;
int C[MAXM];

// Programmazione dinamica top down - metodo ricorsivo
// Servono long long perchè il numero di combinazioni potrebbe non stare dentro un int
int f(int n){
    if(n < 0) return N+1; 
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int ans = N+1;
    for(int i = 0; i < M; ++i)
        ans = min( f(n-C[i])+1, ans);
    return dp[n] = ans;
}

// Assumo che sia possibile stampare la soluzione
// Posso copiare il metodo ricorsivo che calcola f(n) per stampare la soluzione
// Siccome conosco i valori di f(), posso decidere subito qual è la moneta migliore da prendere
void print(int n){
    if(n==0) return;
    int best = N+1;
    int best_idx = -1;
    for(int i = 0; i < M; ++i)
        if( f(n-C[i]) + 1 < best){ // cerco qualche moneta porta alla soluzione migliore
            best = f(n-C[i]) + 1;
            best_idx = i;
        }
    print(n-C[best_idx]); // prendo la scelta ottima
    cout << C[best_idx];
    if(n != N) cout << "+";
    else cout << endl;
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
    else{
        cout << "Answer: " << f(N) << endl; // Il valore di f(N) è gia noto qua perchè è calcolato dentro l'if
        print(N);
    }
}