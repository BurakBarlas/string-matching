#include <iostream>
#include <chrono>
#include "ReadQuestion.cpp"
// #include "ReadQuestion.h"
#include "ReadParagraph.cpp"

int main() {

    auto start = chrono::steady_clock::now();

     readFromQuestion();
     readFromParagraph();



    auto end = chrono::steady_clock::now();

    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;

    return 0;
}
