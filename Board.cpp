#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <map>
#include <iostream>

using namespace std;

using ariel::Direction;
using std::string;


namespace ariel{ 
    
    struct vMap{
    char v = '_';
    };

    Board::Board(){
        u_int dRow = 0;
        u_int dColumn = 0;
        std::map<u_int, std::map<u_int, vMap>>my_board;
        my_board[dRow][dColumn].v = '_';
    }
    
    void Board::post(unsigned int row, unsigned int column, Direction direction ,string message){
        
        this -> dRow = max(dRow,row);
        this -> dColumn = max(dColumn,column);
        this -> my_board[dRow][dColumn].v = '_';
        
        unsigned int i =0;
        for(i = 0; i< message.size(); i++){
            this -> my_board[row][column].v = message.at(i);
            if(Direction::Horizontal == direction){
                column++;
            }else{
                row++ ;
            }
        }
    }

    string Board::read(unsigned int row, unsigned int column,Direction direction ,unsigned int length){
        string reader;
        this -> dRow = max(dRow,row);
        this -> dColumn = max(dColumn,column);
        this -> my_board[dRow+length][dColumn+length].v = '_';
        unsigned int i = 0;
        for(i = 0; i<length; i++){
            reader = reader + this -> my_board[row][column].v;
            if(Direction::Horizontal == direction){
                column++;
            }else{
                row++;
            }
        }
        return reader;
    }

    void Board::show(){
        unsigned int i = 0;
        unsigned int j = 0;
        unsigned int size = my_board.size();
        for (i = 0; i < size; i++){
            for(j = 0 ; j < my_board[i].size(); i++){
                cout << this -> my_board[i][j].v << " ";
            }
            cout << "\n";
        }
    }
}