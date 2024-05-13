extern string types_of_animals[4];

class BaseCare {
protected:
    int mind_affection;
    string type;

public:
    BaseCare() {
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

class WalkCare : public BaseCare{
private:
    int mind_affection;
    string type;
    int BaseCoeff = 1;
    int DogCoeff = 2;
    int BirdCoeff = 1;
    int FishCoeff = -1;
    int RabbitCoeff = 0;
public:
    WalkCare() {
        this->mind_affection = 20;
        this->type = "Caring by walking!";
    }
    int get_coeff_by_type(string t) {
        if (t == types_of_animals[0]) return FishCoeff;
        if (t == types_of_animals[1]) return DogCoeff;
        if (t == types_of_animals[2]) return BirdCoeff;
        if (t == types_of_animals[3]) return RabbitCoeff;
        return BaseCoeff;
    }
};

class PetCare : public BaseCare {
private:
    int mind_affection;
    string type;
    int BaseCoeff = 2;
    int DogCoeff = 2;
    int BirdCoeff = 1;
    int FishCoeff = -1;
    int RabbitCoeff = 1;
public:
    PetCare() {
        this->mind_affection = 5;
        this->type = "Caring by petting!";
    }
    int get_coeff_by_type(string t) {
        if (t == types_of_animals[0]) return FishCoeff;
        if (t == types_of_animals[1]) return DogCoeff;
        if (t == types_of_animals[2]) return BirdCoeff;
        if (t == types_of_animals[3]) return RabbitCoeff;
        return BaseCoeff;
    }
};

class StareCare : public BaseCare {
private:
    int mind_affection;
    string type;
    int BaseCoeff = 1;
    int DogCoeff = 0;
    int BirdCoeff = 0;
    int FishCoeff = 3;
    int RabbitCoeff = 0;
public:
    StareCare() {
        this->mind_affection = 10;
        this->type = "Caring by staring!";
    }
    int get_coeff_by_type(string t) {
        if (t == types_of_animals[0]) return FishCoeff;
        if (t == types_of_animals[1]) return DogCoeff;
        if (t == types_of_animals[2]) return BirdCoeff;
        if (t == types_of_animals[3]) return RabbitCoeff;
        return BaseCoeff;
    }
};

class PlayCare : public BaseCare {
private:
    int mind_affection;
    string type;
    int BaseCoeff = 1;
    int DogCoeff = 3;
    int BirdCoeff = 1;
    int FishCoeff = 0;
    int RabbitCoeff = 1;
public:
    PlayCare() {
        this->mind_affection = 30;
        this->type = "Caring by plaing!";
    }
    int get_coeff_by_type(string t) {
        if (t == types_of_animals[0]) return FishCoeff;
        if (t == types_of_animals[1]) return DogCoeff;
        if (t == types_of_animals[2]) return BirdCoeff;
        if (t == types_of_animals[3]) return RabbitCoeff;
        return BaseCoeff;
    }
};

class Cares {
public:
    WalkCare cw;
    PetCare petc;
    StareCare cs;
    PlayCare playc;
};