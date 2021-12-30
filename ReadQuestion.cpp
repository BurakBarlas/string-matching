#include <iostream>
#include "ReadQuestion.h"
#include <fstream>
#include <string>


using namespace std;

void readFromQuestion(){

    string word;
    string temp = "";
    //int str_arr_limit = 0;
    int num_of_quest = 0;
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
                //str_arr_limit++;
                if(word.back() == '?') {
                    cout << temp << " " << endl;
                    temp = "";
                    num_of_quest++;
                    
                }
            }
        }
        cout << num_of_quest << endl;
    }
     question.close();
}
//Who is suddenly aware that the hundreds of other beachgoers have stopped their activities to stare at him?