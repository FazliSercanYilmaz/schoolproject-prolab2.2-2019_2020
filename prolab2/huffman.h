#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
struct huffmanNode{
    int frekans;
    char karakter;
    struct huffmanNode *left;
    struct huffmanNode *right;
};
map<char,int> frekansbulucu(string metin);
void huffmannodeolusturucu(map<char,string> *p,map<char,int> tablo);
vector<huffmanNode*>   node_olustur(vector<huffmanNode*> a,int freq,char character);
vector<huffmanNode*>  arrayhuffSirala(vector<huffmanNode*> a);
vector<huffmanNode*>  node_birlestir(vector<huffmanNode*> a);
vector<huffmanNode*> node_yapilandirici(vector<huffmanNode*> a);
 void storeCodes(struct huffmanNode* root, string str,map<char,string> *p);
 string huffmancompress(string metin,map<char,string> table);
void mal();

#endif // HUFFMAN_H
