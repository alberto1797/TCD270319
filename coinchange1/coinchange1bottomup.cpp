#include <iostream> // per cin e cout
using namespace std; // per evitare di scrivere std::cout e std::cin ogni volta
const int MAXN = 1005;
const int MAXM = 105;

int dp[MAXN];
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
    dp[0] = 0;

    // Calcoliamo f(N,M-1)
    for(int n = 1; n <= N; ++n){
        dp[n] = N+1; //+inf
        for(int i = 0; i < M; ++i)
            if(n-C[i] >= 0)
                dp[n] = min(dp[n], dp[n-C[i]]+1);
    }

    // Stampo la risposta
    if(dp[N] >= N+1)
        cout << "Impossibile!" << endl;
    else 
        cout << "Answer: " << dp[N];
}