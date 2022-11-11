#include <iostream>
#include "Status.h"
#include "Cook.h"

using namespace std;

//Default
Status::Status(){
    int rooms_ = 0;
    int key_ = 0;
    int anger_ = 0;
    int gold_ = 0;

    Cook cook_;

    for (int i = 0; i < 5; i++){
        weapons_[i] = 0;
    }
    for (int i = 0; i < 5; i++){
        treasures_[i] = 0;
    }    
    for (int i = 0; i < 5; i++){
        party_[i] = "";
    }
    int armor_ = 0;
    int ingredients_ = 0;
};
//Setters
void Status::setKey(int key){
    key_ = key;
};
void Status::setRooms(int rooms){
    rooms_ = rooms;
};
void Status::setAnger(int anger){
    anger_ = anger;
};
void Status::setGold(int gold){
    gold_ = gold;
};
void Status::setArmor(int armor){
    armor_ = armor;
};
void Status::setTreasures(int treasures[]){
    for (int i = 0; i < 5; i++){
        treasures_[i] = treasures[i];
    }
};
void Status::setWeapons(int weapons[]){
    for (int i = 0; i < 5; i++){
        weapons_[i] = weapons[i];
    }
};
void Status::setParty(string party[]){
    for (int i = 0; i < 5; i++){
        party_[i] = party[i];
    }
};
void Status::setFullness(int fullness[]){
    for (int i = 0; i < 5; i++){
        fullness_[i] = fullness[i];
    }
};
//Getters
int Status::getKey(){
    return key_;
};
int Status::getRooms(){
    return rooms_;
};
int Status::getAnger(){
    return anger_;
};
int Status::getGold(){
    return gold_;
};
int Status::getArmor(){
    return armor_;
};
/*
int Status::getIngredients(){
    return ingredients_;
};
int Status::getTreasuresAt(int index){
    return treasures_[index];
};
int Status::getCookwareAt(int index){
    return cookware_[index];
};
*/
int Status::getWeaponAt(int index){
    return weapons_[index];
};
string Status::getPartyAt(int index){
    return party_[index];
};
int Status::getFullnessAt(int index){
    return fullness_[index];
};

//Display status
//prints out statuses using the variables in the class
void Status::printFullStatus(){
cout << "+-------------+" << endl;
cout << "| STATUS      |" << endl;
cout << "+-------------+" << endl;
cout << "| Rooms Cleared: " << rooms_ << " | Keys: " << key_ << " | Anger Level: " << anger_ << endl;
cout << "+-------------+" << endl;
cout << "| INVENTORY   |" << endl;
cout << "+-------------+" << endl;
cout << "| Gold        | " << gold_ << endl;
cout << "| Ingredients | " << cook.getIngredients() << " kg" << endl;
cout << "| Cookware    | " "P: " << cook.getCookware("pots") << " | F: "<< cook.getCookware("pans]") << " | C: " << cook.getCookware("cauldrons") << endl;
cout << "| Weapons     | " << "C: " << weapons_[0] << " | S: "<< weapons_[1] << " | R: " << weapons_[2] << " | B: " << weapons_[3] << " | L: " << weapons_[4] << endl;
cout << "| Armor       | " << armor_ << endl;
cout << "| Treasures   | " << "R: " << treasures_[0] << " | N: "<< treasures_[1] << " | B: " << treasures_[2] << " | C: " << treasures_[3] << " | G: " << treasures_[4] << endl;
cout << "+-------------+" << endl;
cout << "| PARTY       |" << endl;
cout << "+-------------+" << endl;
cout << "| " << party_[0] << " | Fullness: " << fullness_[0] << endl; 
cout << "| " << party_[1] << " | Fullness: " << fullness_[1] << endl;
cout << "| " << party_[2] << " | Fullness: " << fullness_[2] << endl;
cout << "| " << party_[3] << " | Fullness: " << fullness_[3] << endl;
cout << "| " << party_[4] << " | Fullness: " << fullness_[4] << endl;
cout << "+-------------+" << endl;

};

void Status::printInventory(){
cout << "+-------------+" << endl;
cout << "| INVENTORY   |" << endl;
cout << "+-------------+" << endl;
cout << "| Gold        | " << gold_ << endl;
cout << "| Ingredients | " << cook.getIngredients() << " kg" << endl;
cout << "| Cookware    | " << "P: " << cook.getCookware("pots") << " | F: "<< cook.getCookware("pans]") << " | C: " << cook.getCookware("cauldrons") << endl;
cout << "| Weapons     | " << "C: " << weapons_[0] << " | S: "<< weapons_[1] << " | R: " << weapons_[2] << " | B: " << weapons_[3] << " | L: " << weapons_[4] << endl;
cout << "| Armor       | " << armor_ << endl;
cout << "| Treasures   | " << "R: " << treasures_[0] << " | N: "<< treasures_[1] << " | B: " << treasures_[2] << " | C: " << treasures_[3] << " | G: " << treasures_[4] << endl;
cout << "+-------------+" << endl;
}
void Status::printParty(){
cout << "| PARTY       |" << endl;
cout << "+-------------+" << endl;
cout << "| " << party_[0] << " | Fullness: " << fullness_[0] << endl; 
cout << "| " << party_[1] << " | Fullness: " << fullness_[1] << endl;
cout << "| " << party_[2] << " | Fullness: " << fullness_[2] << endl;
cout << "| " << party_[3] << " | Fullness: " << fullness_[3] << endl;
cout << "| " << party_[4] << " | Fullness: " << fullness_[4] << endl;
cout << "+-------------+" << endl;
}