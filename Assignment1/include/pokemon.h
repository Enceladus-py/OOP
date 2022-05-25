//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Berat Dalsuna
//---Student Number: 150200002
//--------------------------//

#ifndef _H
#define _H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//-------------Do Not Add Any New Class(es)-------------//

class pokemon{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        int hpValue;
        int atkValue;
    public:
        // Default Constructor
        pokemon(){
            name = "";
            hpValue = 0;
            atkValue = 0;
        }
        // Parametrized Constructor
        pokemon(string n, int atk){
            name = n;
            hpValue = 100;
            atkValue = atk;
        }
        // Copy Constructor
        pokemon(const pokemon &p){
            name = p.name;
            hpValue = p.hpValue;
            atkValue = p.atkValue;
        }
        // Getters
        string get_name() const;
        int get_hp() const;
        int get_atk() const;
        // Setters
        void set_hp(int);
        void reset_hp();
};

class pokedex{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        pokemon pokedexArray[100];
        int value;
    public:
        // Constructor
        pokedex(){
            value = 0;
        }
        // Updates the pokedex array
        void updatePokedex(const pokemon &p);
        // Print pokemon names
        void printPokedex() const;
        // Check if a pokemon exists
        bool checkPokedex(const pokemon &p) const;
       
};

class player{
    private:
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
        string name;
        int pokemonNumber;
        int pokeballNumber;
        int badgeNumber;
        pokemon playerPokemon;
    public:
        pokedex playerPokedex;
        // Default Constructor
        player(){
            name = "";
            pokemonNumber = 0;
            pokeballNumber = 0;
            badgeNumber = 0;
        }
        // Parametrized Constructor
        player(string n, const pokemon &p){
            name = n;
            pokemonNumber = 0;
            pokeballNumber = 10;
            badgeNumber = 0;
            playerPokemon = p;
        }
        // Return pokemon number
        int showPokemonNumber() const;
        // Return pokeball number
        int showPokeballNumber() const;
        // Return badge number
        int showBadgeNumber() const;
        // Return player pokemon object
        pokemon getPokemon() const;
        // Update pokemon number and pokeball number if player selects to catch
        void catchPokemon(int);
        // Update badge number and pokeball number
        void battleWon();
        // Set the hp of the pokemon
        void set_hp(int);
        // Reset the hp of the pokemon
        void reset_hp();
        
};

class enemy{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        pokemon enemyPokemon;
    public:
        // Default Constructor
        enemy(){
            name = "";
        }
        // Parametrized Constructor
        enemy(string n, const pokemon &p){
            name = n;
            enemyPokemon = p;
        }
        // Return enemyPokemon object
        pokemon getPokemon() const;
        // Return name of the enemy
        string getName() const;
        // set hp of pokemon
        void set_hp(int);
        
};

#endif