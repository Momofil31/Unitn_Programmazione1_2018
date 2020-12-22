#include "message.h"

void read_message(message & m) 
{
  cout << "messaggio? ";
  cin >> m.info;
  cout << "priorita'? ";
  cin >> m.priority;
}

void print_message(const message & m) 
{
  cout << m.info << endl;
}




  
