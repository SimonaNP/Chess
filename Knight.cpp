#include "Knight.h"

ChessPosition* Knight::allowedMoves() const
{
    unsigned int size = numberOfAllowedMoves();
    ChessPosition* allowed = new ChessPosition[size];
    char x = this->getPosition().getX();
    char y = this->getPosition().getY();
    int k=0;
    for(char i = x-2; i<= x+2; i+=4)
    {
        if(isCorrectPosition(i, y-1))
        {
            ChessPosition p(i, y-1);
            allowed[k]=p;
            k++;
        }

        if(isCorrectPosition(i, y+1))
        {
            ChessPosition p(i, y+1);
            allowed[k]=p;
            k++;
        }
    }

    for(char i = x-1; i<= x+1; i+=2)
    {
        if(isCorrectPosition(i, y-2))
        {
            ChessPosition p(i, y-2);
            allowed[k]=p;
            k++;
        }

        if(isCorrectPosition(i, y+2))
        {
            ChessPosition p(i, y+2);
            allowed[k]=p;
            k++;
        }
    }
    return allowed;
}


unsigned int Knight::numberOfAllowedMoves() const
{
    unsigned int number =0;
    char x = this->getPosition().getX();
    char y = this->getPosition().getY();

    for(char i = x-2; i<= x+2; i+=4)
    {
        if(isCorrectPosition(i, y-1))
            number++;
        if(isCorrectPosition(i, y+1))
            number++;
    }

    for(char i = x-1; i<= x+1; i+=2)
    {

        if(isCorrectPosition(i, y-2))
            number++;
        if(isCorrectPosition(i, y+2))
            number++;
    }
    return number;
}

ChessPiece* Knight::clone() const {
    return new Knight(*this);
}
