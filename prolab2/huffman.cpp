#include "huffman.h"
vector<huffmanNode*>  node_olustur(vector<huffmanNode*> a,int freq,char character){
a.insert(a.begin(),new huffmanNode);
a.at(0)->left = NULL;
a.at(0)->right = NULL;
a.at(0)->frekans = freq;
a.at(0)->karakter = character;
return  arrayhuffSirala(a);
}
vector<huffmanNode*> arrayhuffSirala(vector<huffmanNode*> a){
    sort(a.begin(), a.end(), [](const huffmanNode* lhs, const huffmanNode* rhs) {
         return lhs->frekans < rhs->frekans;
      });
    return a;
}
vector<huffmanNode*> node_birlestir(vector<huffmanNode*> a){
    struct huffmanNode* one;
    struct huffmanNode* two;
    struct huffmanNode* yeni;
    one = a.at(0);
    two = a.at(1);
    a.erase(a.begin(),a.begin()+2);
    yeni = new huffmanNode;
    yeni->left = one;
    yeni->right = two;
    yeni->karakter = -1;
    yeni->frekans = one->frekans + two->frekans;
    a.insert(a.begin(),yeni);
    return  arrayhuffSirala(a);
}
vector<huffmanNode*> node_yapilandirici(vector<huffmanNode*> a){
   while(a.size() !=1){
    a=node_birlestir(a);
   }
   return a;
}
void storeCodes(struct huffmanNode* root, string str,map<char,string> *p)
{
    if (root==NULL)
        return;
    if (root->karakter != -1)
        (*p)[root->karakter]=str;
    storeCodes(root->left, str + "0",p);
    storeCodes(root->right, str + "1",p);
}
string huffmancompress(string metin,map<char,string> table){
    string gonderi = "";
    for (int i = 0; i < metin.size(); i++){
            gonderi+=table[metin[i]];
    }
    return gonderi;
}

void huffmannodeolusturucu(map<char,string> *p,map<char,int> tablo){
      vector<huffmanNode*> *a = new vector<huffmanNode*>;
    for (const auto& x : tablo) {
             *a = node_olustur((*a),x.second,x.first);
          }
      *a = node_yapilandirici((*a));
      storeCodes(a->at(0),"",p);
}
map<char,int> frekansbulucu(string metin){
    map<char,int> a;
    for (int i = 0; i < metin.size(); i++){
       a[(metin[i])]+=1;
    }
    return a;
}
