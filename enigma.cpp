#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

struct zegar{
       int zeb1;
       int zeb2;
       int zeb3;
       int zeb4;
       int klucz;};
       
struct zegar ustaw(){
       bool i=1; int j; char S[4];
       struct zegar ZZ;
       while(i){              
        cout << "Ustaw pozycjê 1. zebatki (28): ";
        cin >> j; ZZ.zeb1=j%28;
        cout << "Ustaw pozycjê 2. zebatki (24): ";
        cin >> j; ZZ.zeb2=j%24;
        cout << "Ustaw pozycjê 3. zebatki (13): ";
        cin >> j; ZZ.zeb3=j%13;
        cout << "Ustaw pozycjê 4. zebatki (12): ";
        cin >> j; ZZ.zeb4=j%12;
        
        //cout << "Ustawiono zebatki:\n1.na pozycji " <<ZZ.zeb1<< "., 2.na pozycji "  << ZZ.zeb2
        //        << ".,\n3.na pozycji " << ZZ.zeb3 << "., 4.na pozycji " << ZZ.zeb4 << endl ;
          cout << "Zebatki ustawiono na podanych pozycjach!\n" <<
                     "Czy powyzsze dane sa poprawne? (t/n) :";
        while(i){
        cin >> S;
        if(S[0]=='t') i=0;
        if(S[0]=='n') break;
        if(i){
        cout << "Bledny znak!!" << endl;}}}
        
        ZZ.klucz=0;
        return ZZ;}
    
struct zegar przestaw(struct zegar ZZ){
      ZZ.klucz=ZZ.zeb1*32+ZZ.zeb2*10+ZZ.zeb3*9+ZZ.zeb4*3;
      ZZ.zeb1++;
      if(ZZ.zeb1>27){
         ZZ.zeb1=0; ZZ.zeb2++;
         if(ZZ.zeb2>23){
            ZZ.zeb2=0; ZZ.zeb3++;
            if(ZZ.zeb3>12){
               ZZ.zeb3=0;ZZ.zeb4++;
               ZZ.zeb4%=12;}
               }
         }
       return ZZ;           
      }
      
char przekrec(char Z,int klucz, bool kod){
      if(!kod) klucz=-klucz;
      int k=klucz%26, j=klucz%10;
    	
    if(Z>='a' && Z<='z'){ //ma³e litery
		Z+=k;
		if(Z<'a' && k<0)
			Z+=26;
		if(Z>'z')
			Z-=26;
		if(Z<'a' && k>0)
			Z-=26;
			}
	if(Z>='A' && Z<='Z'){ //wielkie litery
		Z+=k;
		if(Z<'A')
			Z+=26;
		if(Z>'Z')
			Z-=26;
			}
	if(Z>='0' && Z<='9'){ //cyfry
		Z+=j;
		if(Z<'0')
			Z+=10;
		if(Z>'9')
			Z-=10;
			}return Z;
  };		
      
zegar koduj(char* F, struct zegar ZZ, FILE* dok){
     for(int i=0;i<strlen(F);i++){
        ZZ=przestaw(ZZ);
        int klucz=ZZ.klucz;
        char Z = przekrec(F[i],klucz,1);
        fputc(Z,dok);}
        
        ZZ=przestaw(ZZ); fputc(' ',dok);
        return ZZ;};
        
zegar dekoduj(struct zegar ZZ, FILE* dok, FILE* cel=NULL){
     if(cel==NULL)  
      while(!feof(dok)){
        char Z=fgetc(dok);
        ZZ=przestaw(ZZ);
        int klucz=ZZ.klucz;
        Z = przekrec(Z,klucz,0);
        cout << Z;}
     else   
      while(!feof(dok)){
        char Z=fgetc(dok);
        ZZ=przestaw(ZZ);
        int klucz=ZZ.klucz;
        Z = przekrec(Z,klucz,0);
        fputc(Z,cel);}
        
        return ZZ;};
           
    

 int main (){
   char F[512],S[32],Z;
   zegar ZZ;
    int j,k,klucz=0;
     FILE *dok,*cel;
     
     //
     
 for(;;){
     
 cout << "e - utworz nowy zaszyfrowany dokument" << endl;
 cout << "w - otworz i odszyfruj istniejacy dokument" << endl;
 cout << "q - zakoncz program" << endl << endl << ":"; 
 
 cin >> Z;
 
 if(Z=='e'){
	  cout << "Nazwij plik do zapisu: ";      
      cin >> S;
       if(!((dok=fopen(S,"r"))==NULL)) {
        cout << "Blad - podany plik juz istnije!\n Czy mimo to kontynuowac? (t/n) :";
         fclose(dok); cin >> Z;
         if(Z=='t');
         else
        return 1;}
	   cel=fopen(S,"w");
        
       ZZ=ustaw();
        
      for(j=0;;j++){            
       if(j) cout << "Wpisz tutaj tresc do zakodowania, max 500 znakow. Napisz 'ZAK', aby zakonczyc" << "\n ";
         //cin >> noskipws >> F;
          cin.getline (F,sizeof(F));
        
        if(F[0]=='Z' && F[1]=='A' && F[2]=='K') break;
        else ZZ=koduj(F,ZZ,cel);
            
            }
      fclose(cel);
      break;}
      
  if(Z=='w'){
	  cout << "Podaj nazwe pliku do dekodowania: ";      
      cin >> S;
		
	  if ((dok=fopen(S, "r"))==NULL) {
     cout << "Blad - brak pliku do czytania!\n";
      return 1;
      }
        
      ZZ=ustaw();
      
      cout << "Zapisac wynik tylko do nowego pliku, czy wyswietlic na ekranie?" << endl;
      for(;;){
       cout << "s - zapisz do pliku, d - wyswietl na ekranie (pozniej mozna zapisac) :";
       cin >> Z;
       
       if(Z=='d'){        
        ZZ=dekoduj(ZZ,dok);
        
        cout << endl << "Zapisac wynik w pliku? (t/n) :";
        cin >> Z;
        if(Z=='t') Z='s';
        if(Z=='n') break;}
        if(Z!='s') break;
        
       if(Z=='s'){ 
   	    cout << "Nazwij plik do zapisu: ";      
        cin >> S;
        if (!((cel=fopen(S,"r"))==NULL)) {
        cout << "Blad - podany plik juz istnije!\n Czy mimo to kontynuowac? (t/n)";
         fclose(cel); cin >> Z;
         if(Z=='t');
         else
        return 1;}
	   cel=fopen(S,"w");
	   
	    ZZ=dekoduj(ZZ,dok,cel);
	    fclose(cel);                }

      fclose(dok);
      break;}break;}
 
 if(Z=='q') break;

}
     
   return 0;
 }
