/*Definir as matrizes correspondentes 
a cada letra e ao espaço (pause)*/
unsigned char pause[8][8] = 
{ 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0,
};
 
unsigned char S[8][8] = 
{
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 0, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
};
unsigned char E[8][8] = 
{
  0, 1, 1, 1, 1, 1, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 1, 1, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 0, 0,
};
unsigned char N[8][8] = 
{
  0, 1, 0, 0, 0, 1, 1, 0,
  0, 1, 0, 0, 0, 1, 1, 0,
  0, 1, 0, 0, 0, 1, 1, 0,
  0, 1, 0, 0, 1, 1, 1, 0,
  0, 1, 0, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 0, 1, 1, 0,
  0, 1, 1, 0, 0, 1, 1, 0,
  0, 1, 0, 0, 0, 1, 1, 0,
};
 
unsigned char A[8][8] = 
{
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
};

unsigned char I[8][8] =
{
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
};

// vetor de 8 inteiros que são as portas digitais que representam as colunas
int colunas[] = {2, 7, A5, 5, 13, A4, 12, A2};
// vetor de 8 inteiros que são as portas digitais que representam as linhas
int linhas[] = {6, 11, 10, 3, A3, 4, 8, 9};
byte col = 0; 

void setup() { 
  // definindo a porta do potenciômetro
  pinMode(A0, INPUT); 
  for(int i = 0; i<8; i++)  
  {  
    pinMode(colunas[i],OUTPUT);  
    pinMode(linhas[i],OUTPUT);  
  }   
}

void loop()  
{  
  for(int i = 0 ; i < 50 ; i++)        //Loop display 50 times  
  {  
    Display(S);                   //Display "S" 
  }  
  for(int i = 0 ; i < 50 ; i++)         //Loop display 50 times
  {     
    Display(E);                 //Display "E"
  }
  for(int i = 0 ; i < 50 ; i++)         //Loop display 50 times  
  {     
    Display(N);                 //Display "N"
  }
  for(int i = 0 ; i < 50 ; i++)         //Loop display 50 times  
  {     
    Display(A);                 //Display "A"
  }
  for(int i = 0 ; i < 50 ; i++)         //Loop display 50 times  
  {     
    Display(I);                 //Display "I"
  }        
}  
  
void Display(unsigned char dat[8][8])    
{  
  for(int c = 0; c<8; c++)  
  {  
    digitalWrite(colunas[c],LOW);    
    for(int r = 0; r<8; r++)  
    {  
      digitalWrite(linhas[r],dat[r][c]);  
    }  
    delay(1);  
    Clear();  
  }  
}    
void Clear()                          
{  
  for(int i = 0; i<8 ; i++)  
  {  
    digitalWrite(linhas[i],LOW);
    digitalWrite(colunas[i],HIGH);
       
  }  
}  