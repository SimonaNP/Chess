#ifndef ROOK_H_INCLUDED
#define ROOK_H_INCLUDED

#include "ChessPiece.h"

class Rook :public ChessPiece{
public:
    Rook(char x, char y):ChessPiece(x,y){}

    ChessPosition* allowedMoves() const;

    ChessPiece* clone() const;

    unsigned int numberOfAllowedMoves() const{return 14;} ;
};

#endif // ROOK_H_INCLUDED
