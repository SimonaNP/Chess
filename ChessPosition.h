#ifndef CHESSPOSITION_H_INCLUDED
#define CHESSPOSITION_H_INCLUDED
#include<iostream>

class ChessPosition{
public:
    ChessPosition(char x='A', char y='1'){
        setX(x);
        setY(y);
    }

    char getX() const {return x;}
    char getY() const {return y;}


    void setX(char l){
        while (!(l>='A' && l<='H')){
            std::cout<<"Incorrect position! Should be between A and H."<<std::endl<<"Try again!"<<std::endl;
            std::cin>>l;
        }
        x=l;
    }

    void setY(char n){
        while (n<'1' || n>'8'){
            std::cout<<"Incorrect position! Should be between 1 and 8."<<std::endl<<"Try again!"<<std::endl;
            std::cin>>n;
        }
        y=n;
    }



    void print(){std::cout<<x<<y;}

    bool operator==(const ChessPosition& p){
        return x==p.x && y == p.y;
    }




private:
    char x;
    char y;
};


#endif // CHESSPOSITION_H_INCLUDED
