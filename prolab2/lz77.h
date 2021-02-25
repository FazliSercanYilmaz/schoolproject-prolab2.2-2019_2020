#ifndef LZ77_H
#define LZ77_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;
struct lz77out{
    int x,y;
    char z;
};

string readFile(string path);
vector<lz77out *>* tolz77(string input,int buffersize);

#endif // LZ77_H
