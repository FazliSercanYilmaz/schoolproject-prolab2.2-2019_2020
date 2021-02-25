#include "fixedhuffman.h"
string decToBinary(int n,int buffer)
{
    string sonuc = "";
    // Size of an integer is assumed to be 32 bits
    for (int i = buffer-1; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            sonuc += '1';
        else
            sonuc += '0';
    }
    return sonuc;
}
string fixedhuffmanolustur(string metin,map<char,string> *codetable,map<char,int> *freqtable){
map<char,int> tablo = frekansbulucu(metin);
fixedtableolusturucu(tablo,codetable);
for (const auto& x : tablo) {
    std::cout << x.first << ": " << x.second << "\n";
    }
   // cout <<  bitset<3>(4).to_string();
return huffmancompress(metin,*codetable);
}
void fixedtableolusturucu(map<char,int> a,map<char,string> *p){
int i;
    for(i = 1 ;;i++){
    if(a.size()<=pow(2,i))
        break;
   }
int j =0;
    for (const auto& x : a) {
        (*p)[x.first] = decToBinary(j,i);
        j++;
        }
}
