#include <chrono>
#include <string>
#include <C:\Users\User\C C++ Projects\3_SEMESTR\FoodClass.h>
#include <C:\Users\User\C C++ Projects\3_SEMESTR\CareClass.h>
#include <C:\Users\User\C C++ Projects\3_SEMESTR\textures.h>

using namespace std;

class Tamagochi {
protected:
    string name;
    int hunger;
    int hp;
    int mind;
    string type;
    int state;
    chrono::system_clock::duration max_life = 10s;
    chrono::system_clock::time_point birth;
public:
    Tamagochi() {
        this->name = "default";
        this->birth = chrono::system_clock::now();
        this->hunger = 100;
        this->hp = 100;
        this->mind = 100;
        this->type = "base";
        state = 1;
    };
    Tamagochi(string n, string t) {
        this->name = n;
        this->birth = chrono::system_clock::now();
        this->hunger = 100;
        this->hp = 100;
        this->mind = 100;
        this->type = t;
        state = 1;
    }
    Tamagochi(string n, int hung, int hps, chrono::system_clock::time_point b, int m, int s, string t) {
        this->name = n;
        this->birth = b;
        this->hunger = hung;
        this->hp = hps;
        this->mind = m;
        this->type = t;
        this->state = s;
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
    int get_state() {
        return this->state;
    }
    string get_name() {
        return this->name;
    }


    Tamagochi operator + (DogFood& f) {
        if (this->state == 0) return Tamagochi(this->name, this->hunger = 0, this->hp = 0, this->birth, this->mind = 0, this->state, this->type);

        if (this->hunger + (f.get_hunger_restortion() * f.get_coeff_by_type(this->type)) > 100) this->hunger = 100;
        else this->hunger += (f.get_hunger_restortion() * f.get_coeff_by_type(this->type));

        if (this->hp + f.get_hp_affection() > 100) this->hp = 100;
        else this->hp += f.get_hp_affection();

        return Tamagochi(this->name, this->hunger, this->hp, this->birth, this->mind, this->state, this->type);
    }

    Tamagochi operator + (FishFood& f) {
        if (this->state == 0) return Tamagochi(this->name, this->hunger = 0, this->hp = 0, this->birth, this->mind = 0, this->state, this->type);

        if (this->hunger + (f.get_hunger_restortion() * f.get_coeff_by_type(this->type)) > 100) this->hunger = 100;
        else this->hunger += (f.get_hunger_restortion() * f.get_coeff_by_type(this->type));

        if (this->hp + f.get_hp_affection() > 100) this->hp = 100;
        else this->hp += f.get_hp_affection();

        return Tamagochi(this->name, this->hunger, this->hp, this->birth, this->mind, this->state, this->type);
    }

    Tamagochi operator + (RabbitFood& f) {
        if (this->state == 0) return Tamagochi(this->name, this->hunger = 0, this->hp = 0, this->birth, this->mind = 0, this->state, this->type);

        if (this->hunger + (f.get_hunger_restortion() * f.get_coeff_by_type(this->type)) > 100) this->hunger = 100;
        else this->hunger += (f.get_hunger_restortion() * f.get_coeff_by_type(this->type));

        if (this->hp + f.get_hp_affection() > 100) this->hp = 100;
        else this->hp += f.get_hp_affection();

        return Tamagochi(this->name, this->hunger, this->hp, this->birth, this->mind, this->state, this->type);
    }

    Tamagochi operator + (BirdFood& f) {
        if (this->state == 0) return Tamagochi(this->name, this->hunger = 0, this->hp = 0, this->birth, this->mind = 0, this->state, this->type);

        if (this->hunger + (f.get_hunger_restortion() * f.get_coeff_by_type(this->type)) > 100) this->hunger = 100;
        else this->hunger += (f.get_hunger_restortion() * f.get_coeff_by_type(this->type));

        if (this->hp + f.get_hp_affection() > 100) this->hp = 100;
        else this->hp += f.get_hp_affection();

        return Tamagochi(this->name, this->hunger, this->hp, this->birth, this->mind, this->state, this->type);
    }

    Tamagochi operator + (WalkCare& c) {
        if (this->state == 0) return Tamagochi(this->name, this->hunger = 0, this->hp = 0, this->birth, this->mind = 0, this->state, this->type);
        if (this->mind + (c.get_mind_affection() * c.get_coeff_by_type(this->type)) > 100) this->mind = 100;
        else this->mind += (c.get_mind_affection() * c.get_coeff_by_type(this->type));
        return Tamagochi(this->name, this->hunger, this->hp, this->birth, this->mind, this->state, this->type);
    }
    Tamagochi operator + (StareCare& c) {
        if (this->state == 0) return Tamagochi(this->name, this->hunger = 0, this->hp = 0, this->birth, this->mind = 0, this->state, this->type);
        if (this->mind + (c.get_mind_affection() * c.get_coeff_by_type(this->type)) > 100) this->mind = 100;
        else this->mind += (c.get_mind_affection() * c.get_coeff_by_type(this->type));
        return Tamagochi(this->name, this->hunger, this->hp, this->birth, this->mind, this->state, this->type);
    }
    Tamagochi operator + (PetCare& c) {
        if (this->state == 0) return Tamagochi(this->name, this->hunger = 0, this->hp = 0, this->birth, this->mind = 0, this->state, this->type);
        if (this->mind + (c.get_mind_affection() * c.get_coeff_by_type(this->type)) > 100) this->mind = 100;
        else this->mind += (c.get_mind_affection() * c.get_coeff_by_type(this->type));
        return Tamagochi(this->name, this->hunger, this->hp, this->birth, this->mind, this->state, this->type);
    }
    Tamagochi operator + (PlayCare& c) {
        if (this->state == 0) return Tamagochi(this->name, this->hunger = 0, this->hp = 0, this->birth, this->mind = 0, this->state, this->type);
        if (this->mind + (c.get_mind_affection() * c.get_coeff_by_type(this->type)) > 100) this->mind = 100;
        else this->mind += (c.get_mind_affection() * c.get_coeff_by_type(this->type));
        return Tamagochi(this->name, this->hunger, this->hp, this->birth, this->mind, this->state, this->type);
    }
    Tamagochi operator -(int) {

        if (this->hp == 0) return Tamagochi(this->name, this->hunger = 0, this->hp, this->birth, this->mind = 0, this->state = 0, this->type);

        if (this->hunger == 0 && !(this->mind == 0)) return Tamagochi(this->name, this->hunger, this->hp - 1, this->birth, this->mind - 1, this->state, this->type);

        if (this->mind == 0 && !(this->hunger == 0)) return Tamagochi(this->name, this->hunger - 1, this->hp - 1, this->birth, this->mind, this->state, this->type);

        if (this->mind == 0 && this->hunger == 0) return Tamagochi(this->name, this->hunger, this->hp - 2, this->birth, this->mind, this->state, this->type);

        return Tamagochi(this->name, this->hunger - 1, this->hp, this->birth, this->mind - 1, this->state, this->type);
    }
};

struct Tamagochi_And_Food_And_Care {
    Tamagochi t;
    Foods f;
    Cares c;
};
