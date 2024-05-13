#include <C:\Users\User\C C++ Projects\3_SEMESTR\TamagochiClass.h>

int frame = 1;


class Printer {
private:
    Animation a;
public:
    Printer(string t) {
        a.apply_animation(t);
    }
    
    int print_tamagochi(Tamagochi t) {
        cout << left;
        if (frame == 1) {
            cout << a.frames.frame_1 << "\n" << setw(20) << "Name: " << t.get_name() << "\n" << setw(20) << "Type: " << t.get_type() << "\n";
            frame = 2;
        }
        else {
            cout << a.frames.frame_2 << "\n" << setw(20) << "Name: " << t.get_name() << "\n" << setw(20) << "Type: " << t.get_type() << "\n";
            frame = 1;
        }
        return 0;
    };

    int print_tamagochi_info(Tamagochi t) {
        cout << left;
        cout << a.frames.frame_idle << "\n" << setw(20) << "Name: " << t.get_name() << "\n" << setw(20) << "Type: " << t.get_type() << "\n" << setw(20) << "Hunger: " << t.get_hunger() << "\n" << setw(20) << "Mind: " << t.get_mind() << "\n" << setw(20) << "HP: " << t.get_hp() << "\n";
        return 0;
    };


    int print_base_food(DogFood f) {
        cout << setw(20) << "Hunger restortion: " << f.get_hunger_restortion() << "\n" << setw(20) << "HP affection: " << f.get_hp_affection() << "\n" << setw(20) << "Type: " << f.get_type() << "\n";
        return 0;
    }

    int print_help() {
        cout << "To feed tamagochi enter 'f'.\nTo care about tamagochi enter 'c' and then choose the specification: 'pl' play with it, 'pe' pet it, 's' stare at it, 'w' walk with it.\nYou can get info about food and tamagochi by enter 'gf' and 'gt'.\nTo stop program enter 'b'.\n";
        return 0;
    }
};

