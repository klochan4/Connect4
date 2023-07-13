
#ifndef GAME_H
#define GAME_H

#include "player.h"


#define COLUMN_MINCOUNT 3
#define COLUMN_MAXCOUNT 10

#define ROW_MINCOUNT 3
#define ROW_MAXCOUNT 10

class GAME
{
private:

    
    int columnCount;
    int rowCount;
    char* gameArray;

public:
GAME(int rc, int cc);

    int getColumnCount();
    int getRowCount();
    void printGameArea();
    bool setGameArea(int columnIndex, PLAYER player);
    

};

#endif