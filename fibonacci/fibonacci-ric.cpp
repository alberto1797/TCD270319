#include <iostream> // per cin e cout
using namespace std;  // per evitare di scrivere std::cout e std::cin ogni volta

int N;

// servono long long perchè il risultato potrebbe non stare dentro un int
long long f(int n){
    if(n==0) return 0ll;
    if(n==1) return 1ll;
    return f(n-1)+f(n-2);
}

int main(){
    // Leggo l'input
    cin >> N;

    // Stampo la risposta
    cout << "Answer: " << f(N) << endl;
}