#include <iostream>

using namespace std;

void bubblesort(int intArray[], int arraySize);
int factorial(int x);
int checkWord(string word1, string word2);
int checkWord(string word1, string word2, int x);

int main() {
    int arreglo[6] = {5, 4, 3, 2, 6};
    bubblesort(arreglo, 6);
    for(int i = 0; i < 6; i++)
        cout << arreglo[i] << endl;
    cout << factorial(5) << endl;
    cout << checkWord("hola", "holasssholadg") << endl;
    return 0;
}

//ordenar arreglo de menor a mayor
void bubblesort(int intArray[], int arraySize) {
    int temp;
    for(int i = 0; i < arraySize - 1; i++) {
        for(int j = 0; j < arraySize-i-1; j++) {
            if(intArray[j] > intArray[j+1]) {
                temp = intArray[j];
                intArray[j] = intArray[j+1];
                intArray[j+1] = temp;
            }
        }
    }
}

//calcular el factorial de un numero
int factorial(int x) {
    if(x == 0)
        return 1;
    return x * factorial(x-1);
}


//ver cuantas veces el string1 aparece en string2
int checkWord(string word1, string word2) {
    int x = 0;
    return checkWord(word1, word2, x);
}

int checkWord(string word1, string word2, int x) {

    if(word1 == word2)
        x++;
    if(word1.size() >= word2.size())
        return x;
    if(word1 == word2.substr(0, word1.size()))
        x++;
    return checkWord(word1, word2.substr(1, word2.size()-1), x);
}
