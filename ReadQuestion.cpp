#include <iostream>
#include "ReadQuestion.h"
#include <fstream>
#include <string>


using namespace std;



void readFromQuestion(){

    string word;
    string temp = "";
    int str_arr_limit = 0;
    int str_arr_limit_max = str_arr_limit;
    int num_of_quest = 0;
    bool isInBannerdWord = false;
    string bannedWord[16] = {"that","his","is","to","at","an","on","in","from","the","he","of","she","He","a","The"};
    // ifstream question("questions.txt");
    ifstream question("questionsTest.txt");

    if(question.is_open()){
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
                str_arr_limit++;
                if(word.back() == '?') {
                    if (str_arr_limit_max < str_arr_limit)
                    {
                        str_arr_limit_max = str_arr_limit;
                    }
                    
                    cout << temp << " " << endl;
                    temp = "";
                    num_of_quest++;
                    str_arr_limit = 0;
                }
            }
        }
        
        string quest_arr_2D[num_of_quest][str_arr_limit_max];
        int num_of_quests[num_of_quest];

        for (int i = 0; i < num_of_quest; i++)
        {
            num_of_quests[i] = 0;
            for (int j = 0; j < str_arr_limit_max; j++)
            {
                quest_arr_2D[i][j] = "0";
            }
        }
        
        for (int i = 0; i < num_of_quest; i++)
        {
            num_of_quests[i] = 0;
            for (int j = 0; j < str_arr_limit_max; j++)
            {
                cout << quest_arr_2D[i][j];
            }
            cout << endl;
        }
        
        //string quest_arr[num_of_quest];
    }
     question.close();
}



