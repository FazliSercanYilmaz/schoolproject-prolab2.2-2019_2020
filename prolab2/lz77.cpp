#include "lz77.h"
vector<lz77out *>* tolz77(string input,int buffersize){
    vector<lz77out *> *lzOutTable  = new vector<lz77out *>();
     stringstream temp;
    vector<string> result;
    int bufferSize=buffersize;
    vector<char> searchBuffer;
    for (int i=0;i<bufferSize;i++) {
        searchBuffer.insert(searchBuffer.begin(),'\0');
    }
    string leftStr;
    unsigned int spended=0;
    for (int i=0;1;i++) {
        int repeatLength=0;
        leftStr=input.substr(spended,spended+bufferSize+2>input.size()?input.size()-spended:bufferSize+2);//zamanın anasını siktik
        if(leftStr[0]=='\0')break;
        string forAdd="";
        int location=-1;
        for (int j=bufferSize-1;j>-1;j--) {
            if(searchBuffer[j]==leftStr[0]){
                location=j;
                break;
            }
        }
        if(location!=-1){
            for (int j=location;j>-1;j--) {
                if(searchBuffer[j]==leftStr[repeatLength]){
                    forAdd.push_back(searchBuffer[j]);
                    repeatLength++;
                }
                else
                    break;
            }
        }
        forAdd.push_back(leftStr[repeatLength]);
        for (int j=0;j<repeatLength+1;j++) {
            searchBuffer.insert(searchBuffer.begin(),forAdd[j]);
            searchBuffer.pop_back();
        }

        temp<<location+1<<repeatLength<<forAdd[forAdd.size()-1];
        lzOutTable->push_back(new lz77out);
        lzOutTable->back()->x = location+1;
         lzOutTable->back()->y = repeatLength;
        lzOutTable->back()->z = forAdd[forAdd.size()-1];
        spended+=repeatLength+1;
        if(spended>input.length()){
            break;
        }
    }
    return lzOutTable;
}
