#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
#include "huffman.h"
#include "fixedhuffman.h"
#include "deflate.h"
#include "lz77.h"
using namespace std;
string readFile(string path);
string inputPath="D:\\test\\input.txt";
string lzoutPath="D:\\test\\lzout.txt";
map<char,int> frekansbulucu(string metin);
int main()
{
    deflate(readFile(inputPath),256,256,lzoutPath);
  /* vector<lz77out *> *a =  tolz77("abracadabradddsadsagefdgfsdhgfdgadgfsdgfsaFDAHFADdd",16);
    for(int i=0;i<a->size();i++){
       cout<<(a->at(i)->x) << " "<< a->at(i)->y << " "<< a->at(i)->z <<endl;
    }*/
    //huffmanchooser("merhaba");

    //string metin = "d2";
   // map<char,string> *tablo = new map<char,string>();
    /*vector<huffmanNode*>* arraya = new vector<huffmanNode*>();
     cout<<endl << huffmannodeolusturucu(arraya,"alaadinkapi",tablo) << endl ;
    for (const auto& x : *tablo) {
         std::cout << x.first << ": " << x.second << "\n";
        }

    //cout << (*tablo)['c'];
    map<char,int> a  = frekansbulucu("alaadinkapi");
    for (const auto& x : a) {
        std::cout << x.first << ": " << x.second << "\n";
        }
    return 0;*/
 // fixedhuffmanolustur("merhaba",tablo);
}
string readFile(string path){
    ifstream ifs;
    string line;
    ifs.open(path.c_str());
    string fileStr="";
    while (getline(ifs,line)) {
        fileStr+=line;
    }
    ifs.close();
    return fileStr;
}
