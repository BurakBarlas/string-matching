#include <iostream>
#include "ReadParagraph.h"
#include "ReadQuestion.h"
#include <fstream>
#include <string>

using namespace std;

string hashedText[1000];

void readFromParagraph(){

    string word;
    string tempSentence = "";
    int numberOfWord = 0;
    int tempIndex = 0;
    //deneme sil
    int testIndex = 0;

    bool isInWhile = true;

    ifstream mainText("the_truman_show_script.txt");
    //ifstream mainText("test.txt");

    for (int i = 0; i < 1000; i++){
        hashedText[i] = "NULL";
    }
    
    
    while(mainText >> word){
        tempSentence += word + " ";
        numberOfWord++;
        
        
        if(word.size() >= 2 &&(word[0] >= 'a' && word[0] <= 'z') && word.back() == '.'){
            tempIndex = numberOfWord;

            if (hashedText[tempIndex] == "NULL"){

            }
            else{
                while(hashedText[tempIndex] != "NULL"){
                tempIndex ++;
                }
            }
        
            hashedText[tempIndex] = tempSentence;
            tempSentence = "";
            numberOfWord = 0;
        }
    }

    for (int i = 0; i < 1000; i++){
        cout << i << ") " << hashedText[i] << endl;
    }
    
    // for (int i = 0; i < hashIndex-1; i++)
    // {
    //     cout << i << " " << hashedText[i] << endl;
    // }
}

void sentencesCompare(){
    hashedText[0];
    quest_arr_2D[3][3];
    num_of_quests[4];
    int sentenceIndex = 0;
    string searchingWord;
    string lookingSentence;
    int tempIndex = 0;
    bool isCorrectSentence = false;
    int correctWordCount = 0;
    int incorrectWordLimit = 4;
    
    for (int i = 0; i < 62; i++){
        for (int j = 0; j < 62; j++){
            isCorrectSentence = false;
            searchingWord = quest_arr_2D[i][j];
            lookingSentence = hashedText[sentenceIndex];
            //looking sentence icine bakip kelimenin olup olmadigi kontrol ediliyor
            for (int z = 0; z < lookingSentence.size(); z++){
                
                if (searchingWord[tempIndex] == lookingSentence[z] && tempIndex < searchingWord.size() && lookingSentence[z] != ' '){
                    tempIndex++;
                }
                else{
                    if (tempIndex == (searchingWord.size()-1)){
                        isCorrectSentence = true;
                        break;
                    }
                    else{
                        tempIndex = 0;
                    }
                    
                    tempIndex = 0;
                }
            }
            if(isCorrectSentence){
                correctWordCount++;
            }
            // BURADA KALDIK OÇ
            else{
                incorrectWordLimit--;
                if(incorrectWordLimit == 0){
                    sentenceIndex++;
                    if (sentenceIndex == 999){
                        //answer not found!
                    }
                    
                }
                if(correctWordCount >= num_of_quests[i]-3){
                    //dogru cumleyi bulmus oluyoruz
                }
                correctWordCount = 0;
            }
    
        }
        
    }


    
    cout << quest_arr_2D[0][0];
    
}

