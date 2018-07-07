#include <iostream>
#include "ChessPosition.h"
#include "ChessPiece.h"
#include "Knight.h"
#include "Rook.h"
void printAllowedPositions(ChessPiece& p)
{
    for (unsigned int i=0; i<p.numberOfAllowedMoves(); i++)
        p.allowedMoves()[i].print();
        std::cout<<std::endl;

}


bool isCapturedBy(ChessPiece* current,ChessPosition pos, ChessPiece* piece)
    {
        ChessPiece* newPiece;
        if (Knight* knightPtr = dynamic_cast<Knight*>(piece))
            newPiece = new Knight(pos.getX(), pos.getY());
        else
             newPiece = new Rook(pos.getX(), pos.getY());

        unsigned int size = newPiece->numberOfAllowedMoves();
        for( unsigned int i=0; i<size; i++)
        {
            if (newPiece->allowedMoves()[i]==current->getPosition())
                return true;
        }
        return false;
    }


//we don't have the problem with the rook not being able to jump over other pieces
//because even if it jumps over it will be in a position that attacks them
//which will be excluded from the result anyways

//we also think of pieces as an already stable configuration
void allMoves(ChessPiece** pieces,int size)
{
    for(int i =0; i<size; i++)
    {
        for(unsigned int j=0; j<pieces[i]->numberOfAllowedMoves(); j++)
        {
            if(isEmpty(pieces,size,pieces[i]->allowedMoves()[j]))
            {
                bool flag=0;
                for(int k = 0; k<size; k++)
                {
                    if(k!=i)
                        if(pieces[k]->captures(pieces[i]->allowedMoves()[j]) || isCapturedBy(pieces[k],pieces[i]->allowedMoves()[j],pieces[i])){
                            flag++;
                    }
                }
                if(flag == 0){
                    if (Knight* knightPtr = dynamic_cast<Knight*>(pieces[i]))
                            std::cout<<"Knight ";
                        else

                           std::cout<<"Rook ";
                        pieces[i]->getPosition().print();
                        std::cout<<" -> ";
                        pieces[i]->allowedMoves()[j].print();
                        std::cout<<std::endl;
                }
            }
        }
    }
}


int main()
{
    Knight kon('B', '6');
    Knight kon2('D', '2');
    Rook top('A', '8');
    Rook top2('H', '7');
    Rook top3('G', '3');
    ChessPiece** figures = new ChessPiece*[5];
    figures[0] = kon.clone();
    figures[1] = kon2.clone();
    figures[2] = top.clone();
    figures[3] = top2.clone();
    figures[4] = top3.clone();
    allMoves(figures,5);


    return 0;
}
