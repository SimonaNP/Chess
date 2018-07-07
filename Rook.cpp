#include "Rook.h"

ChessPosition* Rook::allowedMoves() const{
    unsigned int size = numberOfAllowedMoves();
    ChessPosition* allowed = new ChessPosition[size];
    char x = this->getPosition().getX();
    char y = this->getPosition().getY();
    int k=0;
    for(char i='A'; i<='H'; i++){
        if(i!=x){
            allowed[k]=ChessPosition(i,y);
            k++;
        }
    }

    for(char i='1'; i<='8'; i++){
        if(i!=y){
            allowed[k]=ChessPosition(x,i);
            k++;
        }
    }

    return allowed;
}

ChessPiece* Rook::clone() const{
    return new Rook(*this);
}


