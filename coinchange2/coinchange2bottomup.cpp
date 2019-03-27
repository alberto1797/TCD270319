#include <iostream> // per cin e cout
using namespace std;
const int MAXN = 1005;
const int MAXM = 105;

long long dp[MAXN][MAXM]; 
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
    for(int i = 0; i <=M ;++i)
        dp[0][i] = 1;
    
    // Calcoliamo f(N,M-1)
    for(int i = 0; i < M; ++i)
        for(int n = 1; n <= N; ++n){
            if(i == 0){
                dp[n][i] = 0;
                if(n >= C[i])
                    dp[n][i]+=dp[n-C[i]][i];
            }else{
                dp[n][i] = dp[n][i-1];
                if(n >= C[i])
                    dp[n][i]+=dp[n-C[i]][i];
            }
        }
    
    // Stampo la risposta
    cout << "Answer: " << dp[N][M-1] << endl;
}