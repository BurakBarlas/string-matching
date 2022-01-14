#include <iostream>
#include "ReadParagraph.h"
#include "ReadQuestion.h"
#include <fstream>
#include <string>

using namespace std;

string hashedText[100];

void readFromParagraph(){

    string word;
    string tempSentence = "";
    int numberOfWord = 0;
    int tempIndex = 0;
    //deneme sil
    int testIndex = 0;

    bool isInWhile = true;

    //ifstream mainText("the_truman_show_script.txt");
    ifstream mainText("test.txt");

    for (int i = 0; i < 100; i++){
        hashedText[i] = "NULL";
    }
    
    
    while(mainText >> word){
        tempSentence += word + " ";
        numberOfWord++;
        
        
        if(word.size() >= 2 &&(word[0] >= 'a' && word[0] <= 'z') && word.back() == '.'){
            tempIndex = numberOfWord;

//buradaki if gereksiz if'i kontrol et sil
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

    for (int i = 0; i < 100; i++){
        cout << i << ") " << hashedText[i] << endl;
    }
    

    sentencesCompare();
}

void sentencesCompare(){

    string searchingWord;
    string lookingSentence;
    bool isCorrectSentence = false;
    int blankIndex;
    int sentenceIndex = 0;
    int tempIndex = 0;
    int correctWordCount = 0;
    int incorrectWordLimit = 4;

    
    for (int i = 0; i < 62; i++){
        for (int j = 0; j < num_of_quests[i]; j++){
            isCorrectSentence = false;
            searchingWord = quest_arr_2D[i][j];
            
            lookingSentence = hashedText[sentenceIndex];

            for (int i = 0; i < lookingSentence.size(); i++){
                cout << lookingSentence[i];
            }
            cout << endl;
            
            cout << searchingWord << " " << lookingSentence << " " << sentenceIndex << endl;
            //looking sentence icine bakip kelimenin olup olmadigi kontrol ediliyor
            for (int z = 0; z <= lookingSentence.size(); z++){
                cout << z << " z " << endl;
                //cout << "for ici " << tempIndex << endl;
                if (searchingWord[tempIndex] == lookingSentence[z] && tempIndex < searchingWord.size() && lookingSentence[z] != ' '){
                    tempIndex++;
                    cout << " harfler ayni " << endl;
                }else{
                    //cout << "89else "<< endl;
                    if (tempIndex == searchingWord.size()){
                        isCorrectSentence = true;
                        cout << " correct word " << endl;
                        break;
                    }
                    else{
                        //cout << tempIndex << " " << searchingWord.size() << endl;
                        blankIndex = z;
                        //baktigimiz kelime aradigimiz kelime olmadigi icin o kelimeyi atliyoruz
                         while (lookingSentence[blankIndex] != ' '){
                            if(blankIndex == 99){
                                break;
                            }
                            blankIndex++;
                        }
                        z = blankIndex + 1;
                        //cout << "95satir else" << endl;
                        tempIndex = 0; 
                    }
                    
                }
            }
            if(isCorrectSentence){
                correctWordCount++;
            }
            // BURADA KALDIK OÇ
            
            incorrectWordLimit--;
            cout << " incorrectWord " << incorrectWordLimit << endl;
            if(incorrectWordLimit == 0){
                sentenceIndex++;
                incorrectWordLimit = 4;
                j--;
                
            }
            if(correctWordCount >= num_of_quests[i]-3){
                //dogru cumleyi bulmus oluyoruz
                //cout << hashedText[sentenceIndex] << endl;
            }
            correctWordCount = 0;
        
    
        }
        
    }
    
}

