#include <iostream>
#include "ReadQuestion.h"
#include <fstream>
#include <string>


using namespace std;

void readFromQuestion(){

    string word;
    string temp = "";
    bool isInBannerdWord = false;
    string bannedWord[16] = {"that","his","is","to","at","an","on","in","from","the","he","of","she","He","a","The"};
    ifstream question("questions.txt");

    if(question.is_open()){
        cout<<"burak çok konuşuyo"<<endl;
        while(question >> word) {
            for(int i = 0; i < 16; i++){
                if(word != bannedWord[i]){
                    isInBannerdWord=false;
                }
                else{
                    isInBannerdWord=true;
                    break;
                }
            }
            if(!isInBannerdWord){
                temp += word + " ";
                if(word.back() == '?') {
                    cout << temp << " " << endl;
                    temp = "";
                }
            }
        }
    }
     question.close();
}

