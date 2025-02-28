/*
 * Nome: Rodrigo de Freitas Lima
 * NUSP: 12547510
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void insertWordInOrder(vector<string> &orderedWords, string word){
    if(orderedWords.size() == 0){
        orderedWords.push_back(word);
        return;
    }

    for(size_t i = 0; i < orderedWords.size(); i++){
        if(word < orderedWords[i]){
            orderedWords.insert(orderedWords.begin() + i, word);
            return;
        }
    }

    orderedWords.push_back(word);
}

int main(){
    string text; // Texto a ser analisado

    getline(cin, text);

    // Cortar pontuação e numeros e transformar em minuscula
    for(size_t i = 0; i < text.size(); i++){
        if(isalpha(text[i]) || text[i] == ' ')
        {
            text[i] = tolower(text[i]);
            continue;
        }
        else
        {
            text[i] = ' ';
        }
    }

    unordered_map<string, int> freq; // Frequência de cada palavra 
    vector<string> orderedWords; // Palavras ordenadas

    string word = ""; // Palavra atual
    
    for(size_t i = 0; i <= text.size(); i++){
        if(text[i] == ' ' || i == text.size())
        {
            if(word.size() > 0){
                // Verifica se a palavra já foi inserida no map
                if(freq.find(word) == freq.end()){
                    freq[word] = 1;
                    insertWordInOrder(orderedWords, word); // Insere a palavra na lista ordenada
                }
                else
                {
                    freq[word]++;
                }

                word = "";
            }

            continue;
        } 

        word += text[i];
    }

    int sum = 0;

    for(size_t i = 0; i < orderedWords.size(); i++){
        sum += freq[orderedWords[i]];
    }

    cout << sum << endl;

    for(size_t i = 0; i < orderedWords.size(); i++){
        if(i == orderedWords.size() - 1){
            cout << orderedWords[i] << endl;
            break;
        }
        cout << orderedWords[i] << ", ";
    }

    for(size_t i = 0; i < orderedWords.size(); i++){
        cout << orderedWords[i] << " " << freq[orderedWords[i]] << endl;
    }

    return 0;
}