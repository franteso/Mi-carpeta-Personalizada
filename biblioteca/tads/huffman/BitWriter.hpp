#ifndef _TARR_BITWRITER_
#define _TARR_BITWRITER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../../funciones/strings.hpp"
#include "../../funciones/files.hpp"

using namespace std;
typedef unsigned char Byte;
void byteWrite(Byte i,FILE* f)
{
   fwrite(&i,sizeof(Byte),1,f);   
}
struct BitWriter
{
    FILE* file;            // Puntero al archivo donde se escribirán los bits.
    unsigned char buffer;  // Búfer de 8 bits para acumular los bits.
    int bitCount;          // Contador de bits en el búfer (de 0 a 7).
};

BitWriter bitWriter(FILE* f)
{
       BitWriter bw;
    bw.file = f;
    bw.buffer = 0;  // El búfer inicia vacío (todos los bits en 0).
    bw.bitCount = 0; // No hay bits en el búfer todavía.
    return bw;
}

void bitWriterWrite(BitWriter& bw,int bit)
{
    bw.buffer = bw.buffer << 1;
    if (bit == 1) {
        bw.buffer = bw.buffer | 00000001;
    }
    bw.bitCount++;
    if (bw.bitCount == 8)
    {
      byteWrite(bw.buffer, bw.file);
        bw.buffer = 0;
        bw.bitCount = 0;
    }
}

void bitWriterWrite(BitWriter& bw,string sbit)
{
   int c = length(sbit);
   for(int i =0; i<c;i++)
   {
   char bitChar = sbit[i];
   int bit = bitChar - '0';
        bitWriterWrite(bw, bit);
   }
}


int bitWriterFlush(BitWriter& bw)
{
    if (bw.bitCount == 0) {
        return 0;
    }

    int bitsDeRelleno = 8 - bw.bitCount;
    bw.buffer = bw.buffer << bitsDeRelleno;

    // Usamos tu función específica aquí también.
    byteWrite(bw.buffer, bw.file);
    
    bw.buffer = 0;
    bw.bitCount = 0;

    return bitsDeRelleno;
}

#endif
