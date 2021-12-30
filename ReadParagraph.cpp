#include <iostream>
#include "ReadParagraph.h"
#include <fstream>
#include <string>

using namespace std;

void readFromParagraph(){
    string word;
    string temp = "";
    // ifstream main_Text("the_truman_show_script.txt");
    ifstream main_Text("test.txt");
    if(main_Text.is_open()){
        while (main_Text >> word)
        {
            temp += word + " ";

            if(word.size() >= 2 &&(word[0] > 'a' && word[0] < 'z') && word.back() == '.') 
                {
                    cout << temp << " " << endl;
                    temp = "";
                }
        } 
    }
}
