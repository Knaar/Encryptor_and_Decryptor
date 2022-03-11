#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#define Size_Of_Alfavit 26
using namespace std;

void Else();
void Encryption(char* Alfavit, int Step);
void Decryption(char* Alfavit);
void AskUser();



void Encryption(char *Alfavit, int Step ) { //Зашифровываем
    char MixedAlfavit[Size_Of_Alfavit];
    string InputWord;
    cout << "Input word :";
    cin >> InputWord;
        
    int TempVal = 0;
    for (size_t i = Size_Of_Alfavit - Step; i < Size_Of_Alfavit; i++)//мы добавили в конец смешанного алфавита ндостающие буквы
    {
        MixedAlfavit[i] = Alfavit[TempVal];
        TempVal++;   
    }


    int TempVal2 = 0 + Step;
    for (int i = 0; i < Size_Of_Alfavit - Step; i++)//хочу заменить буквы после шага Step
    {
        MixedAlfavit[i] = Alfavit[TempVal2];
        
        TempVal2++;
    }
    cout << endl;
    for (size_t x = 0; x < InputWord.size(); x++)//проверяем каждую буквув слове
    {
        for (size_t i = 0; i < Size_Of_Alfavit; i++)
        {
            if (InputWord[x] == Alfavit[i])//когда он находит букву из слова в алфавите
            {
                InputWord[x] = MixedAlfavit[i];//он заменяет эту букву на такую-же из подменного алфавита
                break;
            }
        }
    }
    cout << "Important! Remember your step : " << Step << " Encrypted Word : " << InputWord << endl << "Something Else?[Y/N]";
    Else();
}
void Decryption(char* Alfavit) { //расшифровка

    char MixedAlfavit[Size_Of_Alfavit];
    int Step;
    string InputWord;
    cout << "Input word :";
    cin >> InputWord;
    cout << "Enter Step :";
    cin >> Step;
    
    int TempVal = 0;
    for (size_t i = Size_Of_Alfavit - Step; i < Size_Of_Alfavit; i++)//мы добавили в конец смешанного алфавита ндостающие буквы
    {
        MixedAlfavit[i] = Alfavit[TempVal];
        TempVal++;
    }
    cout << endl;
    int TempVal2 = 0 + Step;
    for (int i = 0; i < Size_Of_Alfavit - Step; i++)//хочу заменить буквы после шага Step
    {
        MixedAlfavit[i] = Alfavit[TempVal2];
        TempVal2++;
    }
    for (size_t x = 0; x < InputWord.size(); x++)//проверяем каждую буквув слове
    {
        for (size_t i = 0; i < Size_Of_Alfavit; i++)//
        {
            if (InputWord[x] == MixedAlfavit[i])//когда он находит букву из слова в подменном алфавите
            {
                InputWord[x] = Alfavit[i];//он заменяет эту букву на такую-же из  алфавита
                break;
            }
        }
    }
    cout  << "Decrypted word : " << InputWord<<endl<<"Something Else?[Y/N]";//выдаёт ответ
    Else();//отправляемся в ф-ю Else
}


void AskUser() {//программа сперва спрашивает у пользователя, а чего он от неё хочет

    int Step = rand() % 26;//рандом для шага смещения алфафита
    
    char Alfavit[Size_Of_Alfavit] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','z','y','z' };

    cout << "Hi!";
    int Question;
    

    for (size_t i = 0; i < 1;)//Поставил ввод через цикл фор, чтобы он повторялся до тел пор, пока пользовател не введет 
    {
        cout<<"I can:\n1. Encrypt\n2. Decrypt\nWhat you need?"; 
        cin >> Question;
        if (Question == 1)
        {
            i++;
            Encryption(Alfavit, Step);//идём в зашифровку
        }
        else if (Question == 2)
        {
            i++;
            Decryption(Alfavit);//идём а расгифровку
        }
        else {
            i--;
            cin.clear();//очищаем ввод и повторяем
            cout << "I don't understand!\n";
        }
    }
   
}
void Else() {//эта ф-я для того, чтобы можно было продолжить работу
    char Else;
    cin >> Else;
    for (size_t i = 0; i < 1; i++)
    {
        if (Else == 'Y' || Else == 'y') {
            AskUser();
        }
        else if (Else == 'N' || Else == 'n') {
            cout << "Bye!";
        }
        else {
            cout << "Looks like you have some problem with your fingers";
        }
    }
}

int main(){
    srand(time(NULL));
    AskUser();
    return 0;
}
