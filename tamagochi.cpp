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

using namespace std;

const int SEMAFORE_GET_FOOD_INFO = 2;
const int SEMAFORE_GET_TAMAGOCHI_INFO = 3;
const int SEMAFORE_DEFAULT = 0;
const int SEMAFORE_END = -1;
const int SEMAFORE_GET_HELP = 5;

string types_of_animals[3]{"fish", "homiak", "bird"};
int frame = 1;
string frame_1 = "                                                            \n                                       ,                    \n                                      .####%                \n                            *%*%%.  *%*//(.(*%(             \n                         .((*%*/////#&%...../*/(/,          \n                         *&#((., /%%##*.(((., (&&.          \n                         /&#(..,,,,.%&%(.((..,(##.          \n                         *&#(.(.(,,,.,(##/...(.,.*#%        \n                         .(.*%*.(...,,.((*%*((., *&#        \n                            /*///(((..,, /%%(..../**.(,     \n                              .#%*/(((.,,...(..((, ,%&* ,   \n                                 /&#((.,,,,,,,,,,,,,,,(##.  \n                              .%%/(/((.,,,,,,,,,,,,,/*/..*%%\n                              .#&/..((.,,./(,,,,,, ,%#*  *&#\n                              .##/.(((.,.*%*,,,,,...*%/,,*##\n                              .##*(((((..%&#,,,,,.(/,,,,,*#&\n                                 /##(.((.((((((.((((../##(  \n                            /*(  *&#%%%%%/((((((./%%%%%##.  \n                         .((*%/((/*%%****(,.((...%&#*/*##.  \n                         /#%/(*&&/.(...,,,,,(/(.,*&#.,(%%.  \n                            %#&##*..,,,,,,,.#########&/     \n                            ,,(##/..((.,,,,,../##/(/#&*     \n                              .&&/..((......,,/&#%**((.     \n                              .**/////////////****%*        \n                                 /&##########&*             ";
string frame_2 = "                                         (*//*(             \n                               .....  ,..*%%%%/..           \n                              (####%, (#&*.., (&&.          \n                            #&%((.,.%&&##/.(, (&&.          \n                            #&%((.,,../&#/(., (&&.          \n                            #&%((..., (&&/.(..(**/((        \n                            #&%(((((,,(%%/(/((.,,*&#        \n                            #&%(((((,,, ,*&#((., *&#        \n                              (&#/((.(.,,.(((((((.,.%#/     \n                               ../%%((.,,,,......,,,((/**,  \n                              ,../%%((. ,,,,,,,,,,,,..(%*(..\n                              (&&/..((.,,...,,,,,,,,%#/, *&&\n                              .&#/.(((.,,/%*,,,,,,,.#&*, *&#\n                              .&&/.((..(.%&#, ,.,.((... ,*&&\n                              ,///**(((((/**....,(((.,(*//((\n                                 /%*//(//(((((((.//(///%%.  \n                                    #&&&#/..(.(((%###&*     \n                            %&*  *&%((((((((,,,,,,,,,,(##.  \n                         (**///**///((.,,......, /%*, (&&(  \n                         (*/*/*&&/.(...,,,,,**/((%&#/(/**,  \n                            %##&#/((,,,,.,,,%##&&#%##&*     \n                              .&&/.(((.,,,,,, (##*.(#&*     \n                              .&&*.(..((....../&&##%,,,     \n                              ,((*%%*%%%%%**%%/(((((        \n                                 (*%*********%(             ";

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

class texture {
private:
    string type;
    FILE* animation_file[10];
};

class Food {
private:
    int hunger_restortion;
    int hp_affection;
    string type;

public:
    Food() {
        this->hunger_restortion = 50;
        this->hp_affection = 30;
        this->type = "base_food";
    }
    int get_hunger_restortion() {
        return this->hunger_restortion;
    }
    int get_hp_affection() {
        return this->hp_affection;
    }
    string get_type() {
        return this->type;
    }
};

class Care {
private:
    int mind_affection;
    string type;

public:
    Care() {
        this->mind_affection = 10;
        this->type = "base_care";
    }
    int get_mind_affection() {
        return this->mind_affection;
    }
    string get_type() {
        return this->type;
    }
};


class Tamagochi {
private:
    int hunger;
    int hp;
    int mind;
    string type;
    int state;
    chrono::system_clock::duration max_life = 10s;
    chrono::system_clock::time_point birth;
public:
    Tamagochi() {
        this->birth = chrono::system_clock::now();
        this->hunger = 100;
        this->hp = 100;
        this->mind = 100;
        this->type = "base";
        state = 1;
    }
    Tamagochi(int hung, int hps, chrono::system_clock::time_point b, int m, int s, string t) {
        this->birth = b;
        this->hunger = hung;
        this->hp = hps;
        this->mind = m;
        this->type = t;
        state = s;
    }
    string get_type() {
        return this->type;
    }
    int get_hp() {
        return this->hp;
    }
    int get_mind() {
        return this->mind;
    }
    int get_hunger() {
        return this->hunger;
    }


    Tamagochi operator + (Food& f) {
        if (this->state == 0) return Tamagochi(this->hunger = 0, this->hp = 0, this->birth, this->mind = 0, this->state, this->type);
        if (f.get_type() == "base_food") {
            this->hunger += f.get_hunger_restortion(); 
            this->hp += f.get_hp_affection();
            return Tamagochi(this->hunger, this->hp, this->birth, this->mind, this->state, this->type);
        }
        return Tamagochi();
    }

    Tamagochi operator + (Care& c) {
        if (this->state == 0) return Tamagochi(this->hunger = 0, this->hp = 0, this->birth, this->mind = 0, this->state, this->type);
        if (c.get_type() == "base_care") {
            this->mind += c.get_mind_affection();
            return Tamagochi(this->hunger, this->hp, this->birth, this->mind, this->state, this->type);
        }
        return Tamagochi();
    }
    Tamagochi operator -(int) {
        if (this->hp == 0) return Tamagochi(this->hunger = 0, this->hp, this->birth, this->mind = 0, this->state = 0, this->type);

        if (this->hunger == 0 && !(this->mind == 0)) return Tamagochi(this->hunger, this->hp - 1, this->birth, this->mind - 1, this->state, this->type);

        if (this->mind == 0 && !(this->hunger == 0)) return Tamagochi(this->hunger - 1, this->hp - 1, this->birth, this->mind, this->state, this->type);

        if (this->mind == 0 && this->hunger == 0) return Tamagochi(this->hunger, this->hp - 2, this->birth, this->mind, this->state, this->type);

        return Tamagochi(this->hunger - 1, this->hp, this->birth, this->mind - 1, this->state, this->type);
    }
};

class Printer {
public:
    int print_tamagochi(Tamagochi t) {
        cout << left;
        if (frame == 1){ 
            cout << frame_1 << "\n" << setw(20) << "Type: " << t.get_type() << "\n" << setw(20) << "Hunger: " << t.get_hunger() << "\n" << setw(20) << "Mind: " << t.get_mind() << "\n" << setw(20) << "HP: " << t.get_hp() << "\n";
            frame = 2;
        }
        else {
            cout << frame_2 << "\n" << setw(20) << "Type: " << t.get_type() << "\n" << setw(20) << "Hunger: " << t.get_hunger() << "\n" << setw(20) << "Mind: " << t.get_mind() << "\n" << setw(20) << "HP: " << t.get_hp() << "\n";
            frame = 1;
        }
        return 0;
    };

    int print_food(Food f) {
        cout << setw(20) << "Hunger restortion: " << f.get_hunger_restortion() << "\n" << setw(20) << "HP affection: " << f.get_hp_affection() << "\n" << setw(20) << "Type: " << f.get_type() << "\n";
        return 0;
    }
    
    int print_help() {
        cout << "To feed tamagochi enter 'f'.\nTo care about tamagochi enter 'c'.\nYou can get info about food and tamagochi by enter 'gf' and 'gt'.\nTo stop program enter 'b'.\n";
        return 0;
    }
};

struct Tamagochi_and_Food_and_Care {
    Tamagochi t;
    Food f;
    Care c;
};

HANDLE hTimer;
DWORD dwTimerThreadID;

DWORD dwInputThreadID;
HANDLE hInput;

short semaphore = 0;

DWORD WINAPI timer(LPVOID x) {
    Tamagochi_and_Food_and_Care* taf = (Tamagochi_and_Food_and_Care*)x;
    while (semaphore != -1) {
        this_thread::sleep_for(1s);
        taf->t = taf->t - 1;
    }
    return 0;
}

DWORD WINAPI input(LPVOID x) {
    Tamagochi_and_Food_and_Care * taf = (Tamagochi_and_Food_and_Care*)x;
    char c;
    while(1) {
        c = getchar();
        switch (c) {
        case 'f':
            taf->t = taf->t + taf->f;
            break;
        case 'b':
            semaphore = SEMAFORE_END;
            return 0;
        case 'c':
            taf->t = taf->t + taf->c;
            break;
        case 'g':
            c = getchar();
            switch (c) {
            case 'f':
                semaphore = SEMAFORE_GET_FOOD_INFO;
                break;
            case 't':
                semaphore = SEMAFORE_GET_TAMAGOCHI_INFO;
                break;
            break;
            }
        //case 'h':
        //    semaphore = SEMAFORE_GET_HELP;
        //    break;
        }
        
    }
}

int main()
{   
    Food f;
    Tamagochi t;
    Tamagochi_and_Food_and_Care *taf = new Tamagochi_and_Food_and_Care; 
    taf->t = t; taf->f = f;

    hInput = CreateThread(NULL, 0, input, taf, 0, &dwInputThreadID);
    hTimer = CreateThread(NULL, 0, timer, taf, 0, &dwTimerThreadID);

    while (semaphore != SEMAFORE_END) {
        Printer p;
        p.print_tamagochi(taf->t);
        cout << "\n";
        p.print_food(taf->f);

        this_thread::sleep_for(1s);
        system("cls");

        switch (semaphore) {
        case SEMAFORE_GET_FOOD_INFO:
            p.print_food(taf->f);
            semaphore = SEMAFORE_DEFAULT;
            this_thread::sleep_for(5s);
            system("cls");
            break;
        case SEMAFORE_GET_TAMAGOCHI_INFO:
            p.print_tamagochi(taf->t);
            semaphore = SEMAFORE_DEFAULT;
            this_thread::sleep_for(5s);
            system("cls");
            break;
        //case SEMAFORE_GET_HELP:
        //    p.print_help();
        //    semaphore = SEMAFORE_DEFAULT;
        //    this_thread::sleep_for(5s);
        //    system("cls");
        //    break;
        }
    }

    CloseHandle(hInput);
    CloseHandle(hTimer);

    return 0;
}

