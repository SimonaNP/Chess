#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED
#include "ChessPiece.h"

class Knight : public ChessPiece{
public:
    Knight(char x, char y):ChessPiece(x,y){}

    ChessPosition* allowedMoves() const;

    ChessPiece* clone() const;

    unsigned int numberOfAllowedMoves() const;
};

#endif // KNIGHT_H_INCLUDED
