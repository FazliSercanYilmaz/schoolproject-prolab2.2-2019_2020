#include "deflate.h"

map<char,string>* huffmanchooser(string metin){
    long long int fixedboyut,variableboyut,noncompress;
      map<char,int> tablo = frekansbulucu(metin);
      fixedboyut= variableboyut = tablo.size()*8;
      map<char,string> *fixedcodetable = new  map<char,string>();
      map<char,string> *variablecodetable = new map<char,string>();
      fixedtableolusturucu(tablo,fixedcodetable);
      huffmannodeolusturucu(variablecodetable,tablo);
     /* for (const auto& x : *variablecodetable) {
          std::cout << x.first << ": " << x.second << "\n";
          }
      cout << "bitti" << endl ;
      for (const auto& x : *fixedcodetable) {
          std::cout << x.first << ": " << x.second << "\n";
          }*/
      for (const auto& x : tablo) {
        //  std::cout << x.first << ": " << x.second << "\n";
          fixedboyut+=((*fixedcodetable)[x.first].size())*x.second;
          variableboyut+=((*variablecodetable)[x.first].size())*x.second;
          }
      if(fixedboyut>variableboyut)
        {
          return variablecodetable;
        }
        else if(fixedboyut<variableboyut)
        {
         return fixedcodetable;
        }
        else
        {
         return variablecodetable;
        }
}
void deflate(string metin,int lz77bufferSize,int minhuffmanblocksize,string output){
    ofstream myfile;
    myfile.open(output);
cout<<"basladi"<<endl;
    vector<deflateTableAndvalues *> deflatecompresseddata;
    vector<lz77out *> * tablo =  tolz77(metin,256);
    string block = "";
    string block2 = "";
    int *bitis = new int();
    *bitis = 0;
    int min = minhuffmanblocksize;
    int dynamicsize = minhuffmanblocksize;
    int dynamicsizeafter = minhuffmanblocksize;
    double oran1;
int temp=0;
int start=0;
while(1){
block = DeflateParser(tablo,start,dynamicsize,bitis);
oran1 =karhesaplayici(block);
if(oran1 == -1000){
    if((dynamicsize-start)<=10){
    deflatecompresseddata.push_back(new deflateTableAndvalues);
    deflatecompresseddata.back()->table=NULL;
    deflatecompresseddata.back()->compressed_data=DeflateParsernoncompress(tablo,start,dynamicsize);
  //  cout<<deflatecompresseddata.back()->compressed_data<<endl;
    start= dynamicsize;
    dynamicsize += min;
    if((*bitis)!=1){
       continue;
    }
    else {
        break;}
}
    if((dynamicsize-5)>(start)){
        dynamicsize-=5;
        continue;
    }
    continue;
}
block2 = DeflateParser(tablo,start,dynamicsize+20,bitis);
//cout<<oran1<< " : " << karhesaplayici(block2) <<endl;
if(oran1>=karhesaplayici(block2)){
  start= dynamicsize;
  dynamicsize += min;
  deflatecompresseddata.push_back(new deflateTableAndvalues);
  deflatecompresseddata.back()->table= huffmanchooser(block);
  deflatecompresseddata.back()->compressed_data =deflateprint(block,(*huffmanchooser(block)));
 // cout<<deflateprint(block,(*huffmanchooser(block)))<<endl;
  if((*bitis)!=1){
     continue;
  }
  else {
      break;}

}
else {
    if(dynamicsize+20<=tablo->size())
dynamicsize+=20;
continue;
}
}
cout<<"bitti"<<endl;
string c="";
for(int i =0;i<deflatecompresseddata.size();i++){
    if(deflatecompresseddata.at(i)->table !=NULL){
    for (const auto& x : *(deflatecompresseddata.at(i)->table)) {
        c+=x.first;
}
    }
}
map<char,string>* bigtable = huffmanchooser(c);
//print

myfile <<"char      "<< "ascii       " << "code" <<endl;
for (const auto& x : *bigtable) {
    if((int)x.first<0){
        myfile << x.first << "  " <<256+((int)x.first) <<"     " << x.second <<endl;
        continue;
    }
    myfile << x.first << "  " <<(int)x.first <<"     " << x.second <<endl;
    }

myfile.close();

}
string deflateprint(string metin,map<char,string> table){
    string gonderi = "";
    for (int i = 0; i < metin.size();){
            gonderi+="("+table[metin[i]]+","+table[metin[(i+1)]]+","+table[metin[(i+2)]]+")";
    i +=3;
    }
    return gonderi;
}
string DeflateParser(vector<lz77out *> *tablo,int startindex,int lastindex,int *bitis){
string a = "";
    if((lastindex>=tablo->size())){
        *bitis = 1;
        lastindex=tablo->size();}
    for(int i =startindex;i<lastindex;i++){
        a += (char)tablo->at(i)->x;
        a += (char)tablo->at(i)->y;
         a+= tablo->at(i)->z;
    }
    if(a == ""){
        cout<<"book"<<endl;
    }
    return  a;
}
string DeflateParsernoncompress(vector<lz77out *> *tablo,int startindex,int lastindex){
    string a = "";
        if(lastindex>tablo->size()){
            lastindex=tablo->size();}
        for(int i =startindex;i<lastindex;i++){
            a+='(';
           a += to_string(tablo->at(i)->x) ;
            a+= ',';
           a += to_string(tablo->at(i)->y);
           a+= ',';
            a+= tablo->at(i)->z;
            a+= ')';
        }
        return  a;
}
double karhesaplayici(string metin){
    double fixedboyut,variableboyut,noncompress;
      map<char,int> tablo = frekansbulucu(metin);
      fixedboyut= variableboyut = tablo.size()*8;
      map<char,string> *fixedcodetable = new  map<char,string>();
      map<char,string> *variablecodetable = new map<char,string>();
      fixedtableolusturucu(tablo,fixedcodetable);
      huffmannodeolusturucu(variablecodetable,tablo);
      for (const auto& x : tablo) {
          fixedboyut+=((*fixedcodetable)[x.first].size())*x.second;
          variableboyut+=((*variablecodetable)[x.first].size())*x.second;
          }
      if(((metin.size()*8)<fixedboyut)||((metin.size()*8)<variableboyut)){
          return -1000;
      }
      if(fixedboyut>variableboyut)
        {
          return (((metin.size()*8)-variableboyut)/(metin.size()*8))*100;
        }
         if(fixedboyut<variableboyut)
        {
         return (((metin.size()*8)-fixedboyut)/(metin.size()*8))*100;
        }
        else
        {
         return (((metin.size()*8)-variableboyut)/(metin.size()*8))*100;
        }
}
