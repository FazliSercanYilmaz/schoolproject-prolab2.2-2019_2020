#ifndef DEFLATE_H
#define DEFLATE_H
#include "fixedhuffman.h"
#include "huffman.h"
#include "lz77.h"
struct deflateTableAndvalues{
map<char,string> *table;
string compressed_data;
};
map<char,string>* huffmanchooser(string metin);
void deflate(string metin,int lz77bufferSize,int minhuffmanblocksize,string output);
string deflateprint(string metin,map<char,string> table);
string DeflateParser(vector<lz77out *> *tablo,int startindex,int lastindex,int *bitis);
double karhesaplayici(string metin);
string DeflateParsernoncompress(vector<lz77out *> *tablo,int startindex,int lastindex);
#endif // DEFLATE_H
