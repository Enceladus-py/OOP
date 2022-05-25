//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Berat Dalsuna
//---Student Number: 150200002
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//


// FOR POKEMON CLASS

//GETTERS for pokemon
string pokemon::get_name() const{
    return name;
}
int pokemon::get_hp() const {
    return hpValue;
}
int pokemon::get_atk() const {
    return atkValue;
}
//SETTERS for pokemon
void pokemon::set_hp(int dmg){
    hpValue -= dmg;
}
void pokemon::reset_hp(){
    hpValue = 100;
}

// FOR POKEDEX CLASS

// Updates the pokedex array
void pokedex::updatePokedex(const pokemon &p){
    pokedexArray[value] = p;
    value++;
}
// Print pokemon names
void pokedex::printPokedex() const{
    for(int i=0;i<value;i++){
        cout << pokedexArray[i].get_name() << endl;
    }
}

// Check if a pokemon exists
bool pokedex::checkPokedex(const pokemon &p) const{
    for(int i=0; i<value;i++){
        if(pokedexArray[i].get_name() == p.get_name()){
            return true;
        }
    }
    return false;
}

// FOR PLAYER CLASS

// Return pokemon number
int player::showPokemonNumber() const{
    return pokemonNumber;
} 
// Return pokeball number
int player::showPokeballNumber() const{
    return pokeballNumber;
} 
// Return badge number
int player::showBadgeNumber() const{
    return badgeNumber;
} 
// Return player pokemon object
pokemon player::getPokemon() const{
    return playerPokemon;
} 
// Update pokemon number and pokeball number if player selects to catch
void player::catchPokemon(int option){
    if(option==1){
        pokemonNumber++;
        pokeballNumber--;
    }

}
// Update badge number and pokeball number
void player::battleWon(){
    badgeNumber++;
    pokeballNumber += 3;
    this->reset_hp();
}
// Set the hp of the pokemon
void player::set_hp(int dmg){
    playerPokemon.set_hp(dmg);
}
// Reset the hp of the pokemon
void player::reset_hp(){
    playerPokemon.reset_hp();
}

// FOR ENEMY CLASS

// Return enemyPokemon object
pokemon enemy::getPokemon() const{
    return enemyPokemon;
}
// Return name of the enemy
string enemy::getName() const{
    return name;
}
// set hp of pokemon
void enemy::set_hp(int dmg){
    enemyPokemon.set_hp(dmg);
}