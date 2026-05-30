#ifndef _TARR_BITREADER_
#define _TARR_BITREADER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../../funciones/strings.hpp"
#include "../../funciones/files.hpp"

using namespace std;
typedef unsigned char Byte;
Byte byteRead(FILE* f)
{
   Byte i;
   fread(&i,sizeof(Byte),1,f);
   return i;   
}
struct BitReader
{
    FILE* file;            // Puntero al archivo que estamos leyendo.
    unsigned char buffer;  // Búfer para almacenar el byte actual.
    int bitCount;          // Contador del próximo bit a leer (de 0 a 7).
};

BitReader bitReader(FILE* f)
{
    BitReader bw;
    bw.file = f;
    bw.buffer = 0;  // El búfer inicia vacío (todos los bits en 0).
    bw.bitCount = 0; // No hay bits en el búfer todavía.
    return bw;
}
string binToString(unsigned char c)
{
   string s="";
   for (int i=0;i<8;i++)
   {
      c << i;
      if (c &1)
      {
         s+="1";
      }
      else 
      {
         s+="0";
      }
   }
   return s;

}
int bitReaderRead(BitReader& br)
{
   int ret;
if (br.bitCount == 8)
{
br.buffer = byteRead(br.file);
br.bitCount == 0;
}
string s = binToString(br.buffer);
char r =s[br.bitCount];
br.bitCount++;
   return r-'0';
}

#endif
