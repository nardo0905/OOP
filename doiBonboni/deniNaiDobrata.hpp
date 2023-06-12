#ifndef _PLAYER_
#define _PLAYER_
#include <string>
#include <iostream>

class ChessPlayer{ 

    unsigned int id;
    static int generateId;
    std::string name;

    public:

    ChessPlayer(const std::string &name);
    bool operator==(const ChessPlayer&);
    
};

int ChessPlayer::generateId = 0;

ChessPlayer::ChessPlayer(const std::string &name){
    this->id = generateId;
    generateId++;
    this->name = name;
}

bool ChessPlayer::operator==(const ChessPlayer& other){
    return this->id==other.id && this->name == other.name;
}


#endif