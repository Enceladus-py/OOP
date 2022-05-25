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
#include <fstream>

#include "pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---// 
// 
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---// 
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);
    

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: "; 
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
  
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readEnemyNames(const char* argv){

    fstream newFile; // a new file object created
    string* enemy_names = NULL; // string array
    int size = 0;
    newFile.open(argv, ios::in); // open for reading
    if(newFile.is_open()){
        string s;
        while(getline(newFile, s)){ 
            if(enemy_names == NULL){
                enemy_names = new string[stoi(s)];
            }
            else{
                enemy_names[size] = s;
                size++;
            }
        }
        newFile.close();
    }

    return enemy_names;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readPokemonNames(const char* argv){

    fstream newFile; // a new file object created
    string* pokemon_names = NULL; // string array
    int size = 0;
    newFile.open(argv, ios::in); // open for reading
    if(newFile.is_open()){
        string s;
        while(getline(newFile, s)){ 
            if(pokemon_names == NULL){
                pokemon_names = new string[stoi(s)];
            }
            else{
                pokemon_names[size] = s;
                size++;
            }
        }
        newFile.close();
    }

    return pokemon_names;
};
//-----------------------------------------------------//

player characterCreate(string playerName, int pokemonChoice){

    if(pokemonChoice == 1){
        pokemon newPokemon("Bulbasaur",PLAYER_POKEMON_ATTACK);
        player newPlayer(playerName, newPokemon);
        return newPlayer;
    }
    else if(pokemonChoice == 2){
        pokemon newPokemon("Charmender",PLAYER_POKEMON_ATTACK);
        player newPlayer(playerName, newPokemon);
        return newPlayer;
    }
    else if(pokemonChoice == 3){
        pokemon newPokemon("Squirtle",PLAYER_POKEMON_ATTACK);
        player newPlayer(playerName, newPokemon);
        return newPlayer;
    }
    else{
        cout << "Name set to Bulbasaur by default" << endl;
        pokemon newPokemon("Bulbasaur",PLAYER_POKEMON_ATTACK);
        player newPlayer(playerName, newPokemon);
        return newPlayer;
    }
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){

    enemy newEnemy(enemyNames[NAME_COUNTER],pokemon(pokemonNames[POK_COUNTER],10));

    cout << "You encounter with " << enemyNames[NAME_COUNTER] << " and his/hers pokemon " << pokemonNames[POK_COUNTER] << endl; 
    cout << pokemonNames[POK_COUNTER] << " Health: 100 Attack: 10 1- Fight 2- Runaway Choice: "<< endl;
    if(newPlayer->playerPokedex.checkPokedex(newEnemy.getPokemon())){
        cout << "You already have " << pokemonNames[POK_COUNTER] << " in your Pokedex" << endl;
    }
    else{
        newPlayer->playerPokedex.updatePokedex(newEnemy.getPokemon());
    }
    int input;
    cin >> input;
    while(input == 1){
        newPlayer->set_hp(newEnemy.getPokemon().get_atk()); 
        newEnemy.set_hp(newPlayer->getPokemon().get_atk());
        cout << "Your Pokemons Health: " << newPlayer->getPokemon().get_hp() << " " << newEnemy.getName() << " Pokemons Health: "<< newEnemy.getPokemon().get_hp() << endl;
        if(newPlayer->getPokemon().get_hp() > 0 && newEnemy.getPokemon().get_hp() > 0){
            cout << "1- Fight 2- Runaway Choice: " << endl;
            cin >> input;
        }
        else if(newPlayer->getPokemon().get_hp() > 0 && newEnemy.getPokemon().get_hp() <= 0){
            cout << "You Won!" << endl;
            newPlayer->battleWon();
            break;
        }
        else if(newPlayer->getPokemon().get_hp() <= 0 && newEnemy.getPokemon().get_hp() > 0){
            cout << "You Lose!" << endl;
            break;
        }
        else if(newPlayer->getPokemon().get_hp() <= 0 && newEnemy.getPokemon().get_hp() <= 0){
            cout << "Tie!" << endl;
            break;
        }

    }

    NAME_COUNTER++;
    POK_COUNTER++;
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player* newPlayer, string* pokemonNames){
    pokemon newPokemon(pokemonNames[POK_COUNTER],ENEMY_POKEMON_ATTACK);
    cout << "You encounter with " <<  pokemonNames[POK_COUNTER] << " Health: 100 Attack: 10 1- Catch 2- Runaway Choice: " << endl;
    int input;
    cin >> input;
    if(newPlayer->playerPokedex.checkPokedex(newPokemon)){
        cout << "You already have " << pokemonNames[POK_COUNTER] << " in your Pokedex" << endl;
    }
    else{
        newPlayer->playerPokedex.updatePokedex(newPokemon);
        if(input == 1)
            cout << "You catch " << pokemonNames[POK_COUNTER] << endl;
    }
    newPlayer->catchPokemon(input);
    POK_COUNTER++;
   
};
//--------------------------------------------//
