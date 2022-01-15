#include <iostream>
#include "ReadQuestion.h"
#include <fstream>
#include <string>


using namespace std;


string quest_arr_2D[62][62];
int num_of_quests[62];

void readFromQuestion(){

    string word;
    string tempSentence = "";
    string reCreateLastWord = "";
    int questionNumber = 0;
    int questionWord = 0;
    int wordCounter = 0;
    bool isInBannerdWord = false;
    string bannedWord[15] = {"that","his","is","to","at","an","on","in","the","he","of","she","He","a","The"};
    // ifstream question("questions.txt");
    ifstream question("questionsTest.txt");

    for (int i = 0; i < 62; i++){
        num_of_quests[i] = 0;
        
        for (int j = 0; j < 62; j++){
            quest_arr_2D[i][j] = "0";
        }

    }

    if(question.is_open()){
        while(question >> word){
            wordCounter++;
            /*for(int i = 0; i < 15; i++){
                if(word != bannedWord[i]){
                    isInBannerdWord=false;
                }
                else{
                    isInBannerdWord=true;
                    break;
                }
            }
            if(!isInBannerdWord){*/
            
                
            if(word.back() != '?'){
                quest_arr_2D[questionNumber][questionWord] = word;
                questionWord++;
                tempSentence += word + " ";
            }
            else{
                // cout << tempSentence << " " << endl;
                word.pop_back();
                quest_arr_2D[questionNumber][questionWord] = word;
                questionWord++;
                tempSentence += word + " ";
                tempSentence = "";
                num_of_quests[questionNumber] = wordCounter;
                questionNumber++;
                questionWord = 0;
                wordCounter = 0;
            }
            //}
        }
    }
    question.close();
    // arrayin icindekileri gormek icin kullanildi
    /*for (int i = 0; i < 62; i++){

        for (int j = 0; j < 62; j++){
           cout << quest_arr_2D[i][j] + " ";
        }
        cout << num_of_quests[i];
        cout << endl;
    }*/

}
