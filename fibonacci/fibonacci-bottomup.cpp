#include <iostream> // per cin e cout
using namespace std;  // per evitare di scrivere std::cout e std::cin ogni volta

int N;
const int MAXN = 105;
long long dp[MAXN];

int main(){
    // Leggo l'input
    cin >> N;

    // Programmazione dinamica - bottom up
    // Inizializzo i casi base
    dp[0] = 0;
    dp[1] = 1;

    // calcoliamo f(N)
    for(int n = 2; n <= N; ++n)
        dp[n] = dp[n-1] + dp[n-2];

    // Stampo la risposta
    cout << "Answer: " << dp[N] << endl;
}