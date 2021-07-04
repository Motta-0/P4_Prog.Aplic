#ifndef complexado_h
#include <math.h>
#define complexado_h

using namespace std;

struct tNo
{
  float numeros;
  tNo* proximo;
};

tNo* criarNo(int item)
{
  tNo* no = new tNo;

  no -> numeros = item;
  no -> proximo = NULL;

  return no;
} 

struct tLista
{
  tNo* primeiro;
  tNo* ultimo;
  tNo* marcador;
  int tamanho;
};

void startList(tLista* pList)
{
  pList -> primeiro = NULL;
  pList -> ultimo = NULL;
  pList -> marcador = NULL;
  pList -> tamanho = 0;
}

int obterTamanho(tLista* pList)
{
  return pList -> tamanho;
}

bool emptyList(tLista* pList)
{
  return (pList -> tamanho == 0);
}

bool endList(tLista* pList)
{
  return (pList -> marcador == NULL);
}

void includeEnd(tLista* pList, float numeros)
{
  tNo* no;
  no = criarNo(numeros);

  if(emptyList(pList))
  {
    pList -> primeiro = no;
  }
  else
  {
    pList -> ultimo -> proximo = no;
  }

  pList -> ultimo = no;
  pList -> marcador = no;
  pList -> tamanho ++;
}

void printList(tLista* pList)
{
  pList -> marcador = pList -> primeiro;

  while(!endList(pList))
  {
    int information = pList -> marcador -> numeros;

    cout << information;

    pList -> marcador = pList -> marcador -> proximo;
  }
}

void readFile(tLista* pList)
{
  pList -> marcador = pList -> primeiro;

  ifstream RFILE;
  RFILE.open("Arquivo.txt", ios::in);
  float read;

  while (!RFILE.eof())
  {
    RFILE >> read;
    includeEnd(pList, read);
  }
  RFILE.close();
}

void writeFile(tLista*, pList)
{
  pList -> marcador = pList -> primeiro;

  ofstream WFILE;
  WFILE.open("Arquivo.txt", ios::out);

   while(!endList(pList))
   {
    float information = pList -> marcador -> numeros;
    WFILE << information << " ";
    pList -> marcador = pList -> marcador -> proximo;
   }
  WFILE.close();
}


//--------------------------------------------------------------------------\\


struct tComplexos
{
  float real;
  float imaginario;
  float mod1;
  float mod2;

} Ncomplex[3], complex;


void add(tLista*, complex)
{
  Ncomplex[2].real = Ncomplex[0].real + Ncomplex[1].real;
  includeEnd(complex, Ncomplex[2].real);
  Ncomplex[2].imaginario = Ncomplex[0].imaginario + Ncomplex[1].imaginario;
  includeEnd(complex, Ncomplex[2].imaginario);
}

void sub(tLista*, complex)
{
  Ncomplex[2].real = Ncomplex[0].real - Ncomplex[1].real;
  includeEnd(complex, Ncomplex[2].real);
  Ncomplex[2].imaginario = Ncomplex[0].imaginario - Ncomplex[1].imaginario;
  includeEnd(complex, Ncomplex[2].imaginario);
}

void mult(tLista*, complex)
{
  Ncomplex[2].real = (Ncomplex[0].real * Ncomplex[1].real) - (Ncomplex[0].imaginario * Ncomplex[1].imaginario);
  includeEnd(complex, Ncomplex[2].real);

  Ncomplex[2].imaginario = (Ncomplex[1].imaginario * Ncomplex[0].real) + (Ncomplex[0].imaginario * Ncomplex[1].real);
  includeEnd(complex, Ncomplex[2].imaginario);
}

void div(tLista*, complex)
{
  Ncomplex[2].real = (Ncomplex[0].real * Ncomplex[1].real) + (Ncomplex[0].imaginario * Ncomplex[1].imaginario);
  includeEnd(complex, Ncomplex[2].real);

  Ncomplex[2].imaginario = (Ncomplex[0].imaginario * Ncomplex[1].real) - (Ncomplex[1].imaginario * Ncomplex[0].real);
  includeEnd(complex, Ncomplex[2].imaginario);

  float denominador = (Ncomplex[1].real * Ncomplex[1].real) + (Ncomplex[1].imaginario * Ncomplex[1].imaginario);
  includeEnd(complex, denominador);

  cout << "\n\nO resultado é: " << Ncomplex[2].real << "/" << denominador;

  if (Ncomplex[2].imaginario >= 0)
  {
    cout << "+" << Ncomplex[2].imaginario << "j/" << denominador << endl;
  }
  else
  cout << Ncomplex[2].imaginario << "j/" << denominador << endl;
}

void module(tLista*, complex)
{
  Ncomplex[2].mod1 = sqrt(pow(Ncomplex[0].real,2) + pow(Ncomplex[0].imaginario,2));
  includeEnd(complex, Ncomplex[2].mod1);

  cout << "\n\n\nO modulo do primeiro número complexo é: " << Ncomplex[2].mod1 << endl;

  Ncomplex[2].mod2 = pow(pow(Ncomplex[1].real,2) + pow(Ncomplex[1].imaginario,2), 0.5);
  includeEnd(complex, Ncomplex[2].mod2);

  cout << "O modulo do segundo número complexo é: " << Ncomplex[2].mod2 << endl;
}

void print_result()
{ 
  cout << endl << "O resultado da operação é: ";
  cout << Ncomplex[2].real;
  
  if (Ncomplex[2].imaginario > 0)
    {
      cout << "+" << Ncomplex[2].imaginario << "j" << endl;
    }
    else 
    cout << Ncomplex[2].imaginario << "j" << endl << endl;
}
#endif