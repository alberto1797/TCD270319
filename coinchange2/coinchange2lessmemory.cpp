#include <iostream> // per cin e cout
using namespace std; // per evitare di scrivere std::cout e std::cin ogni volta
const int MAXN = 1005;
const int MAXM = 105;

long long dp[MAXN]; // Dimensione della tabella di programmazione dinamica O(N) !
int N,M;
int C[MAXM];

int main(){
    // Leggo l'input
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; ++i)
        cin >> C[i];

    //Programmazione dinamica BOTTOM UP
    // Inizializziamo i casi base
    dp[0] = 1;
    for(int n = 1; n <= N; ++n)  
        dp[n] = 0; // Concettualmente potete pensare questi valori come f(n,-1)
    
    // Calcoliamo la soluzione
    // f(n,i) ha due stati, ma f(n,i) dipende solo dai valori f(m,i) e f(m,i-1) con 0<=m<=N. Non mi serve memorizzare tutta la tabella
    // dp[n] alla fine dell'iterazione i contiene il valore dp[n][i]. 
    for(int i = 0; i < M; ++i)
        for(int n = C[i]; n <= N; ++n)
            dp[n]+= dp[n-C[i]];
    
    // Stampo la risposta
    cout << "Answer: " << dp[N] << endl;
}