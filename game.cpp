
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

        
GAME::GAME(int rc, int cc){
    rowCount = rc;
    columnCount = cc;
    gameArray = (char*)malloc(rowCount * columnCount);
}

int GAME::getColumnCount(){
    return columnCount;
}

int GAME::getRowCount(){
    return rowCount;
}


bool GAME::setGameArea(int columnIndex, PLAYER player){
    int indexToSet = columnCount * rowCount - (columnCount - columnIndex) - 1;
    
    while(indexToSet >= 0){
        
        if(!gameArray[indexToSet]){
            gameArray[indexToSet] = player.getSymbol();
            return true;
        }
        indexToSet -= columnCount;
    }
    
    return false;
}


void GAME::printGameArea(){
    for(int i = 0; i < columnCount * rowCount; i++){
        printf("|");
        if(!gameArray[i]){
            if(i > columnCount * (rowCount - 1) - 1){
                printf("_");
            }else{
                printf(" ");
            }
        }else{
            printf("%c", gameArray[i]);
        }
        
        if(i % columnCount == columnCount - 1){
            printf("|\r\n");
        }
    }
    
    for(int i = 1; i <= columnCount; i++){
        printf(" %d", i);
    }
    
    printf("\r\n");
}