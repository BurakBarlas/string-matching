#include <iostream>
#include "ReadParagraph.h"
#include <fstream>
#include <string>

using namespace std;

void readFromParagraph(){
    string word;
    string temp = "";
    int hashIndex = 0;
    int numberOfWord = 0;
   

    string hashedText[1000];

    ifstream mainText("the_truman_show_script.txt");
    //ifstream mainText("test.txt");

    for (int i = 0; i < 1000; i++)
        {
            hashedText[i] = "0";
        }

    if(mainText.is_open()){
        while (mainText >> word)
        {
            temp += word + " ";
            numberOfWord++;
            
            

            if(word.size() >= 2 &&(word[0] >= 'a' && word[0] <= 'z') && word.back() == '.') 
                {
                    
                    // while(hashedText[numberOfWord] != "0"){
                    //     numberOfWord++; 
                    //     cout << "while ici";
                    // }

                    hashedText[numberOfWord] = temp;
                    cout << hashedText[numberOfWord] << endl;
                    temp = "";
                    hashIndex++;
                    numberOfWord = 0;
                }
        } 
    }

    for (int i = 0; i < 1000; i++)
    {
        cout << hashedText[i] << endl;
    }
    
    // for (int i = 0; i < hashIndex-1; i++)
    // {
    //     cout << i << " " << hashedText[i] << endl;
    // }
    
}

