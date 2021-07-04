#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

void decimalToAny(int dec, int toBase){
   
   int reminder = 0;
   vector<char> v;

   do{
      reminder = dec % toBase;
      char ch;

      if(reminder>9){
         ch = 'A' + reminder - 10;
      }
      else{
       ch = '0' + reminder;
      }
      
      v.push_back(ch);
      dec = dec/toBase;

   } while(dec != 0);

   for(int i = v.size()-1; i>=0; i--){
      cout<<v[i];
   }
}

int anyToDecimal(int fromBase, string anyNumberString){

   int decimalNumber = 0;
   int k = 0;
   int x;

   for(int i = anyNumberString.size() - 1; i>=0; i--){

      if(anyNumberString[i] >= 'A'){
         x = anyNumberString[i] - 'A' + 10;
      }
      else{
         x = anyNumberString[i] - '0';
      }

      decimalNumber = decimalNumber + x*pow(fromBase,k);
      k++;
   }

   return decimalNumber;
}

void anyToAny(string anyNumberString,int fromBase,int toBase){

      if(toBase == 10){
         cout<<anyToDecimal(fromBase, anyNumberString);
      }
      else{
         int dec = anyToDecimal(fromBase, anyNumberString);
         decimalToAny(dec,toBase);   
      }
}

int main()
{
   string anyNumberString;
   int fromBase;
   int toBase;

   cout<<"Enter a number : "; 
   cin>>anyNumberString; cout<<anyNumberString<<"\n";
   cout<<"From Base : "; 
   cin>>fromBase;cout<<fromBase<<"\n";
   cout<<"To Base : "; 
   cin>>toBase; cout<<toBase<<"\n";

   cout<<"\nOutput = ";
   anyToAny(anyNumberString,fromBase,toBase);
}