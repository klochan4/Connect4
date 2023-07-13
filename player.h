
#ifndef PLAYER_H
#define PLAYER_H



#define PLAYER1_SYMBOL 'x'
#define PLAYER2_SYMBOL 'o'


class PLAYER
{
private:
    char symbol;
    
public:
PLAYER(char s);

    char getSymbol();
  
};

#endif