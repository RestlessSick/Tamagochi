#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <direct.h>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <C:\Users\User\C C++ Projects\3_SEMESTR\Printer.h>

using namespace std;

extern string types_of_animals[4] = {"fish", "dog", "bird", "rabbit"};

const int SEMAFORE_GET_FOOD_INFO = 2;
const int SEMAFORE_GET_TAMAGOCHI_INFO = 3;
const int SEMAFORE_DEFAULT = 0;
const int SEMAFORE_END = -1;
const int SEMAFORE_GET_HELP = 5;
const int SEMAFORE_MENU = 10;

//class User {
//public:
//    char zoo[4][32];
//    FILE* all_user;
//    FILE* user;
//    int user_id = 1;
//    int last_user_id;
//    int create_user() {
//        char username[32];
//        char catalogue[128] = "D:\\";
//        all_user = fopen("D:\\all_user_ids.txt", "a+");
//        fseek(all_user, -3, SEEK_END);
//        if(fscanf(this->all_user, "%d", &last_user_id) == 0) fprintf(this->all_user, "%d\n", this->user_id);
//        else {
//            user_id = last_user_id + 1;
//            fprintf(this->all_user, "%d ", user_id);
//        }
//        cout << "Enter username: ";
//        
//        cin >> username;
//        strcat(catalogue, username);
//        strcat(catalogue, "\\");
//        int x = _mkdir(catalogue);
//        strcat(catalogue, username);
//        strcat(catalogue, ".txt");
//        printf("%s\n", catalogue);
//        this->user = fopen(catalogue, "w");
//        return 0;
//    };
//
//};

struct NameAndType {
    string name;
    string type;
};

HANDLE hTimer;
DWORD dwTimerThreadID;

DWORD dwInputThreadID;
HANDLE hInput;

short semaphore = 0;

DWORD WINAPI timer(LPVOID x) {
    Tamagochi_And_Food_And_Care* taf = (Tamagochi_And_Food_And_Care*)x;
    while (semaphore != -1) {
        this_thread::sleep_for(1s);
        taf->t = taf->t - 1;
    }
    return 0;
}

DWORD WINAPI input(LPVOID x) {
    Tamagochi_And_Food_And_Care * taf = (Tamagochi_And_Food_And_Care*)x;
    char c;
    while(1) {
        c = _getch();
        switch (c) {
        case 'f':
            c = _getch();
            if (c == 'f') {
                taf->t = taf->t + taf->f.ff;
            }
            if (c == 'd') {
                taf->t = taf->t + taf->f.df;
            }
            if (c == 'b') {
                taf->t = taf->t + taf->f.bf;
            }
            if (c == 'r') {
                taf->t = taf->t + taf->f.rf;
            }
            break;
        case 'm':
            semaphore = SEMAFORE_MENU;
            break;
        case 'b':
            semaphore = SEMAFORE_END;
            break;
        case 'c':
            c = _getch();
            if (c == 'w') {
                taf->t = taf->t + taf->c.cw;
            }
            if (c == 's') {
                taf->t = taf->t + taf->c.cs;
            }
            if (c == 'p') {

                c = _getch();

                if (c == 'l') taf->t = taf->t + taf->c.playc;

                if (c == 'e') taf->t = taf->t + taf->c.petc;
            }
            break;
        case 'g':
            c = _getch();
            if (c == 'f') {
                semaphore = SEMAFORE_GET_FOOD_INFO;
                break;
            }
            if (c == 't') {
                semaphore = SEMAFORE_GET_TAMAGOCHI_INFO;
                break;
            }
            break;
        case 'h':
            semaphore = SEMAFORE_GET_HELP;
            break;
        }
        
    }
}

int main()
{   
    while (1) {
        string name, type;
        cout << "Enter the tamagochi type (dog || fish || bird || rabbit): ";
        cin >> type;
        cout << "Enter name of your tamagochi: ";
        cin >> name;
        Tamagochi_And_Food_And_Care taf;
        Tamagochi tam(name, type);
        taf.t = tam;
        Tamagochi_And_Food_And_Care* tafp = &taf;
        system("cls");
        hInput = CreateThread(NULL, 0, input, tafp, 0, &dwInputThreadID);
        hTimer = CreateThread(NULL, 0, timer, tafp, 0, &dwTimerThreadID);

        while (semaphore != SEMAFORE_END) {

            Printer p(taf.t.get_type());

            p.print_tamagochi(taf.t);

            this_thread::sleep_for(250ms);
            system("cls");

            switch (semaphore) {
            case SEMAFORE_GET_FOOD_INFO:
                p.print_base_food(taf.f.df);
                semaphore = SEMAFORE_DEFAULT;
                this_thread::sleep_for(5s);
                system("cls");
                break;
            case SEMAFORE_GET_TAMAGOCHI_INFO:
                p.print_tamagochi_info(taf.t);
                semaphore = SEMAFORE_DEFAULT;
                this_thread::sleep_for(5s);
                system("cls");
                break;
            case SEMAFORE_GET_HELP:
                p.print_help();
                semaphore = SEMAFORE_DEFAULT;
                this_thread::sleep_for(5s);
                system("cls");
                break;
            case SEMAFORE_MENU:
                system("cls");
                goto restart;

            case SEMAFORE_END:
                system("cls");
                exit(0);
                break;
            }
            
        }

        restart:

        CloseHandle(hInput);
        CloseHandle(hTimer);
        semaphore = SEMAFORE_DEFAULT;
    }

    return 0;
}

