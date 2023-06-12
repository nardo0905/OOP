#ifndef __TOURN_H__
#define __TOURN_H__

#include <iostream>
#include "deniNaiDobrata.hpp"


class ChessTournament{

 ChessPlayer** players;
 float* points;
 unsigned num;
 void deleteMem();
 void copy(const ChessTournament&);

public:

 ChessTournament(ChessPlayer** players, unsigned num);
 ChessTournament();
 ~ChessTournament();
 ChessTournament(ChessTournament&);
 ChessTournament& operator=(ChessTournament&);


 virtual bool finished() const= 0;
 int addGame(ChessPlayer&, ChessPlayer&, short);
 ChessPlayer& getLeader();
 ChessPlayer& getWinner();
 void print() const;

};

void ChessTournament::deleteMem(){

    for(int i = 0; i<num; i++ ){
        delete players[i];
    }
    delete[] players;
    delete[] points;
    
}


void ChessTournament::copy(const ChessTournament& other) {

    this->players = new ChessPlayer*[other.num];
    this->num = other.num;
    this->points = new float(num);

    for (int i = 0; i < num; i++) {

        this->players[i] = new ChessPlayer{*(other.players[i])};

    }

    for(int i = 0; i<num; i++){
        this->points[i] = other.points[i];
    }

    
}

ChessTournament::ChessTournament(){
    players = nullptr;
    points = nullptr;
}

ChessTournament::~ChessTournament(){
    deleteMem();
}

 ChessTournament::ChessTournament(ChessTournament& other){
    copy(other);
 }


 ChessTournament& ChessTournament::operator=(ChessTournament&other){
    if(this != &other){
        deleteMem();
        copy(other);
    }
 }

ChessTournament::ChessTournament(ChessPlayer** players, unsigned num){

    this->players = new ChessPlayer*[num];
    this->num = num;
    this->points = new float(num);

    for (int i = 0; i < num; i++) {

        this->players[i] = new ChessPlayer{*(players[i])};

    }

    for(int i = 0; i<num; i++){
        this->points[i] = 0;
    }

}


int ChessTournament::addGame(ChessPlayer& white , ChessPlayer& black, short doni) {
    switch(doni) {

        case -1:
            int indexOfWinner = 0;
            for(int i = 0; i<num; i++){
                if(*players[i]==black){
                    indexOfWinner = i;
                    break;
                }
            }
            points[indexOfWinner]++;
            break;
        case 1:
            int indexOfWinner = 0;
            for(int i = 0; i<num; i++){
                if(*players[i]==white){
                    indexOfWinner = i;
                    break;
                }
            }
            points[indexOfWinner]++;
            break;
        case 0:
            int index1 = 0;
            int index2 = 0;
            for(int i = 0; i<num; i++){
                if(*players[i]==black || *players[i] == white && index1 == 0){
                    index1 = i;
                }
                else if (*players[i]==black || *players[i] == white && index2 == 0) {

                    index2 = i;
                    break;

                }
            }
            points[index1] += 0.5;
            points[index2] += 0.5;
            break;

    }
}

void ChessTournament::print() const{
    for(int i = 0; i<num; i++){
        std::cout<<players[i]<<points[i];
    }
}
#endif // __TOURN_H__