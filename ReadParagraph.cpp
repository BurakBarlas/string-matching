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
    // ifstream mainText("test.txt");

    for (int i = 0; i < 1000; i++){
        hashedText[i] = "NULL";
    }
    
    
    while(mainText >> word){
        tempSentence += word + " ";
        numberOfWord++;
        
        
        // if(word.size() >= 2 && ((int(word[0]) >= 48 && int(word[0]) <= 57) || (int(word[0]) >= 97 && int(word[0]) <= 122)) && word.back() == '.'){
        if(word.size() >= 2 && ((word[0] >= 'a' && word[0] <= 'z' ) || (int(word[0]) >= 48 && int(word[0]) <= 57))&& word.back() == '.'){
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

    /*for (int i = 0; i < 1000; i++){
        cout << i << ") " << hashedText[i] << endl;
    }*/
    

    sentencesCompare();
}

void sentencesCompare(){

    string searchingWord;
    string lookingSentence;
    bool isCorrectWord = false;
    int blankIndex;
    int sentenceIndex = 0;
    int tempIndex = 0;
    int correctWordCount = 0;
    int incorrectWordLimit = 4;

    
    for (int i = 0; i < 62; i++){
        sentenceIndex = 0;
        tempIndex = 0;
        correctWordCount = 0;
        incorrectWordLimit = 4;
        for (int j = 0; j < num_of_quests[i]; j++){
            isCorrectWord = false;
            searchingWord = quest_arr_2D[i][j];
            
            lookingSentence = hashedText[sentenceIndex];
            if (sentenceIndex == 1000){
                break;
            }
            

            /*for (int i = 0; i < lookingSentence.size(); i++){
                cout << lookingSentence[i];
            }
            cout << endl;*/
            
            //cout << searchingWord << " " << lookingSentence << " " << sentenceIndex << endl;
            //looking sentence icine bakip kelimenin olup olmadigi kontrol ediliyor
            for (int z = 0; z <= lookingSentence.size(); z++){
                // cout << z << " z " << endl;
                //cout << "for ici " << tempIndex << endl;
                if (searchingWord[tempIndex] == lookingSentence[z] && tempIndex < searchingWord.size() && lookingSentence[z] != ' '){
                    tempIndex++;
                    // cout << " harfler ayni " << endl;
                }else{
                    
                    //cout << "89else "<< endl;
                    if (tempIndex == searchingWord.size()){
                        isCorrectWord = true;
                        //cout << " correct word " << endl;
                        tempIndex = 0;
                        break;
                    }
                    else{
                        tempIndex = 0;
                        //cout << tempIndex << " " << searchingWord.size() << endl;
                        blankIndex = z;
                        //baktigimiz kelime aradigimiz kelime olmadigi icin o kelimeyi atliyoruz
                         while (lookingSentence[blankIndex] != ' '){
                            if(blankIndex >= 99){
                                break;
                            }
                            else{
                                blankIndex++;
                            }
                        }
                        z = blankIndex;
                        //cout << "95satir else" << endl;
                    }
                    
                }
            }
            if(isCorrectWord){
                correctWordCount++;
                //cout << "correctWordCount: " << correctWordCount << endl;
            }
            else{
                incorrectWordLimit--;
            }
            
            
            //cout << " incorrectWord " << incorrectWordLimit << endl;
            if(correctWordCount >= num_of_quests[i]-3){
                
                cout << hashedText[sentenceIndex] << endl;
                break;
                //dogru cumleyi bulmus oluyoruz
                
                /*i = 100;
                j = 100;*/
                //cout << "dogru cumle bu";
                cout << "153 correctWordCount: " << correctWordCount << endl;
            }
            else{
                if ((correctWordCount == 2) && (hashedText[sentenceIndex].size() <= 6*num_of_quests[i]))
                {
                    cout << hashedText[sentenceIndex] << endl;
                    cout << "else correctWordCount: " << correctWordCount << endl;
                    break;
                }
            }
            if(incorrectWordLimit == 0){
                sentenceIndex++;
                correctWordCount = 0;
                incorrectWordLimit = 4;
                j=-1;
                
            }


            
            // if(correctWordCount <= num_of_quests[i]/2){
            //     if (hashedText[sentenceIndex].size() <= 7*num_of_quests[i])
            //     {
            //         cout << hashedText[sentenceIndex] << endl;
            //         //break;
            //     }
                
            //     //dogru cumleyi bulmus oluyoruz
                
            //     /*i = 100;
            //     j = 100;*/
            //     //cout << "dogru cumle bu";
            // }
        
    
        }
        
    }
    
}

