#include <iostream>

using namespace std;

extern string types_of_animals[4];

class BaseFood {
protected:
    int hunger_restortion;
    int hp_affection;
    string type;

public:
    BaseFood() {
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

class FishFood : public BaseFood {
private:
    string animal_type;
    int BaseCoeff = 1;
    int FishCoeff = 2;
    int DogCoeff = 0;
    int BirdCoeff = 0;
    int RabbitCoeff = 0;
public:
    FishFood() {
        this->hunger_restortion = 25;
        this->hp_affection = 10;
        this->type = "Fish food";
    }
    int get_coeff_by_type(string type) {
        if (type == types_of_animals[0]) return FishCoeff;
        if (type == types_of_animals[1]) return DogCoeff;
        if (type == types_of_animals[2]) return BirdCoeff;
        if (type == types_of_animals[3]) return RabbitCoeff;
        return BaseCoeff;
    }
};

class DogFood : public BaseFood {
private:
    string animal_type;
    int BaseCoeff = 1;
    int FishCoeff = 0;
    int DogCoeff = 2;
    int BirdCoeff = 0;
    int RabbitCoeff = 0;
public:
    DogFood() {
        this->hunger_restortion = 31;
        this->hp_affection = 15;
        this->type = "Dog food";
    }
    int get_coeff_by_type(string type) {
        if (type == types_of_animals[0]) return FishCoeff;
        if (type == types_of_animals[1]) return DogCoeff;
        if (type == types_of_animals[2]) return BirdCoeff;
        if (type == types_of_animals[3]) return RabbitCoeff;
        return BaseCoeff;
    }
};

class BirdFood : public BaseFood {
private:
    string animal_type;
    int BaseCoeff = 1;
    int FishCoeff = 0;
    int DogCoeff = 0;
    int BirdCoeff = 2;
    int RabbitCoeff = 0;
public:
    BirdFood() {
        this->hunger_restortion = 15;
        this->hp_affection = 10;
        this->type = "Bird food";
    }
    int get_coeff_by_type(string type) {
        if (type == types_of_animals[0]) return FishCoeff;
        if (type == types_of_animals[1]) return DogCoeff;
        if (type == types_of_animals[2]) return BirdCoeff;
        if (type == types_of_animals[3]) return RabbitCoeff;
        return BaseCoeff;
    }
};


class RabbitFood : public BaseFood {
private:
    string animal_type;
    int BaseCoeff;
    int FishCoeff = 0;
    int DogCoeff = 1;
    int BirdCoeff = 0;
    int RabbitCoeff = 2;
public:
    RabbitFood() {
        this->hunger_restortion = 20;
        this->hp_affection = 15;
        this->type = "Bird food";
    }
    int get_coeff_by_type(string type) {
        if (type == types_of_animals[0]) return FishCoeff;
        if (type == types_of_animals[1]) return DogCoeff;
        if (type == types_of_animals[2]) return BirdCoeff;
        if (type == types_of_animals[3]) return RabbitCoeff;
        return BaseCoeff;
    }
};

class Foods {
public:
    RabbitFood rf;
    DogFood df;
    BirdFood bf;
    FishFood ff;
};