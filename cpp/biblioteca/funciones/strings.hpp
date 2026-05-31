#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int i=0;
   while( s[i++]!='\0');
   return i-1;
}

int charCount(string s,char c)
{
   int sum=0;
   for(int i=0; i<length(s); i++)
   {
      if( s[i]==c )
      {
         sum++;
      }
   }

   return sum;
}

string substring(string s,int d,int h)
{
   string x="";
   for(int i=d; i<h; i++)
   {
      x+=s[i];
   }

   return x;
}

string substring(string s,int d) // ok
{
   return substring(s,d,length(s));
}

int indexOf(string s,char c) // ok
{
   for(int i=0;i<length(s); i++)
   {
      if(s[i]==c)
      {
         return i;
      }
   }

   return -1;
}

int indexOf(string s,char c,int offSet) // ok
{
   string ns = substring(s,offSet,length(s));
   return indexOf(ns,c);
}


int lastIndexOf(string s,char c)
{
   for(int i=length(s)-1; i>=0;i--)
   {
      if(s[i]==c) return i;
   }

   return -1;
}

int indexOfN(string s,char c,int n)
{
   int offset=0;
   int x=-1;
   for(int i=0; i<n; i++)
   {
      x=indexOf(s,c,offset);
      offset+=x+1;
   }
   return offset-1;
}

int charToInt(char c)
{
   return c-'0';
}

char intToChar(int i)
{
   return '0'+i;
}

int poww(int x,int y)
{
   int p=1;
   for(int i=0;i<y;i++)
   {
      p*=x;
   }

   return p;
}

int getDigit(int n,int i)
{
   int r1=n%(int)poww(10,i+1);
   return r1/(pow(10,i));
}

int digitCount(int n)
{
   if( n==0)
   {
      return 1;
   }

   int x=0;
   double d=n;
   while( d>=1 )
   {
      d=d/10;
      x++;
   }

   return x;
}

string intToString(int i)
{
   string x="";
   int n=digitCount(i);
   for(int j=0; j<n; j++)
   {
      x=intToChar(getDigit(i,j))+x;
   }

   return x;
}

int stringToInt(string s,int b) // ok
{
   int n=length(s);
   int sum=0;
   for(int i=0; i<n; i++)
   {
      //    int d = s[n-i-1]-'0';
      int d = charToInt((char)s[n-i-1]);
      sum+=d*poww(b,i);
   }

   return sum;
}

int stringToInt(string s) // ok
{
   return stringToInt(s,10);
}

string charToString(char c)
{
   return ""+c;
}

char stringToChar(string s)
{
   return s[0];
}

string stringToString(string s)
{
   return s;
}

string doubleToString(double d)
{
   return to_string(d);
}

double stringToDouble(string s)
{
   s="hola";
   return 1.1;
}

bool isEmpty(string s)
{
   return s[0]=='\0';
}

bool startsWith(string s,string x)
{
   return substring(s,0,length(x))==x;
}

bool endsWith(string s,string x)
{
   return substring(s,length(s)-length(x))==x;
}

bool contains(string s,char c)
{
   return indexOf(s,c)>=0;
}

string replace(string s,char oldChar,char newChar)
{
   for(int i=0;s[i]!='\0';i++)
   {
      s[i]=(s[i]==oldChar)?newChar:s[i];
   }
   return s;
}

string insertAt(string s,int pos,char c)
{
   return substring(s,0,pos)+c+substring(s,pos);
}

string removeAt(string s,int pos)
{
   return substring(s,0,pos)+substring(s,pos+1);
}

string ltrim(string s)
{
   int i=0;
   while(s[i++]==' ');
   return substring(s,i-1);
}

string rtrim(string s)
{
   int i=length(s);
   while(s[--i]==' ');
   return substring(s,0,i+1);
}

string trim(string s)
{
   return ltrim(rtrim(s));
}

string replicate(char c,int n)
{
   string s="";
   for(int i=0; i<n; i++)
   {
      s+=c;
   }
   return s;
}

string spaces(int n)
{
   return replicate(' ',n);
}

string lpad(string s,int n,char c)
{
   return replicate(c,n-length(s))+s;
}

string rpad(string s,int n,char c)
{
   return s+replicate(c,n-length(s));
}

string cpad(string s,int n,char c)
{
   int dif=(n-length(s))/2;
   int res=(n-length(s))%2;
   return replicate(c,dif)+s+replicate(c,dif+res);
}

bool isDigit(char c)
{
   return c>='0' && c<='9';
}

bool isLetter(char c)
{
   return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

bool isUpperCase(char c)
{
   return c>='A' && c<='Z';
}

bool isLowerCase(char c)
{
   return c>='a' && c<='z';
}

char toUpperCase(char c)
{
   return isLowerCase(c)?'A'+c-'a':c;
}

char toLowerCase(char c)
{
   return isUpperCase(c)?'a'+c-'A':c;
}

string toUpperCase(string s)
{
   string x="";
   for(int i=0; i<length(s);i++)
   {
      x+=toUpperCase((char)s[i]);
   }
   return x;
}

string toLowerCase(string s)
{
   string x="";
   for(int i=0; i<length(s);i++)
   {
      x+=toLowerCase((char)s[i]);
   }
   return x;
}

int cmpString(string a,string b)
{
   return a<b?-1:a>b?1:0;
}

int cmpDouble(double a,double b)
{
   return a<b?-1:a>b?1:0;
}

char* stringToCString(string s)
{
   char* ret = new char[length(s)+1];

   int i=0;
   while( s[i]!='\0' )
   {
      ret[i] = (char)s[i];
      i++;
   }

   ret[i] = '\0';
   return ret;
}

string cStringToString(char c[])
{
   return string(c);
}

#endif
