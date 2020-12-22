#include <iostream>
#include <iomanip>

using namespace std;

double calcola(double x, int n, double epsilon);
double potenza(double x, double esp);
double abs(double x);

int main () {
  double epsilon, x;
  int n;

  cout << "Inserisci il numero di termini dell’approssimazione: ";
  cin >> n;
  cout << "Inserisci l’errore massimo epsilon: ";
  cin >> epsilon;
  char c;

  do {
    cout << "Inserisci il valore x in cui vuoi calcolare f(x) = 1 / (1 - x) ^ 2: ";
    cin >> x;
    while(x >= 1 || x <= -1) {
      cout << "Valore errato, prego reintrodurre (-1 < x < 1):";
      cin >> x;
    }
    cout << "L’approssimazione di f(x) e': ";
    cout << setprecision(10) << calcola(x, n, epsilon);
    cout << endl;
    cout << "Continuare (s/n)? ";
    cin >> c;
  } while(c != 'n' && c != 'N');
  return(0);
}

double calcola(double x, int n, double epsilon){
  double res=0.0;
  double ultimoRes;
  int i=1;  
  do {
    cout << "sono entrato nel loop della calcola" << endl;
    ultimoRes = res;
    res += i*potenza(x, i-1);
    i++;
  } while (i<=n && (abs(res-ultimoRes) >= epsilon));

  return res;
}

double potenza(double x, double esp){
  double risultato=1;
  for(int i=0; i<esp; i++){
    risultato *= x;
  }
  cout << "Il risultato della potenza e'" << risultato << endl;
  return risultato;
}

double abs(double x){
  double risultato = x;
  if (x < 0)
    risultato  = -x;

  return risultato;
}
