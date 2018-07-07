#ifndef CHESSPIECE_H_INCLUDED
#define CHESSPIECE_H_INCLUDED
#include "ChessPosition.h"

class ChessPiece
{
public:
    ChessPiece(char x, char y)
    {
        ChessPosition p(x,y);
        position = p;
    }

    virtual ~ChessPiece() {};

    ChessPosition getPosition() const
    {
        return position;
    }

    virtual ChessPosition* allowedMoves() const = 0;

    bool captures(ChessPosition pos)
    {
        unsigned int size = numberOfAllowedMoves();
        for(unsigned int i=0; i<size; i++)
        {
            if (allowedMoves()[i]==pos)
                return true;
        }
        return false;
    }

    virtual unsigned int numberOfAllowedMoves() const = 0;

    virtual ChessPiece* clone() const =0;

    bool isCorrectPosition(char x, char y) const
    {
        return x >='A' && x<='H' && y>='1' && y<='8';
    }

    friend bool isEmpty(ChessPiece** arr,int size, const ChessPosition& pos)
    {
        for(int i=0; i<size; i++)
        {
            if(arr[i]->getPosition()==pos)
                return false;
        }
        return true;
    }

    bool operator==(ChessPiece* other){
        return this==other;
    }

    bool operator!=(ChessPiece* other){
        return this!=other;
    }



private:

    ChessPosition position;
};

#endif // CHESSPIECE_H_INCLUDED
