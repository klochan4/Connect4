#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "definitions.h"
#include "game.h"
#include "player.h"

unsigned char* gameArray;


int getStr(char* s){
        int index = 0;
    do{
        s[index++] = std::cin.get();
    }while(s[index - 1] != '\n');
    
    s[index++] = '\0';
    
    if(s[0] == ESC_VALUE){
        return ESC_VALUE;
    }
    return 0;
}

bool strToLong(char* s, long* n){
    char *p;
    
    
    *n = strtol(s, &p, 10);
    if (p == s || *p != '\n') {
        return false;
        
    }
    
    return true;
}

int main()
{
    PLAYER pl1(PLAYER1_SYMBOL);
    PLAYER pl2(PLAYER2_SYMBOL);
    int playerToPlay = 1;
    
    
    int tmp;
    
    int rowCount;
    int columnCount;
    
    while(1){
        printf("Pocet riadkov: \r\n");
        char s[100];
        long n;
        
        while(1){
            if(getStr(s) == ESC_VALUE){
                printf("Hra bola ukoncena\r\n");
                return 0;
            }
            
           
            if(!strToLong(s, &n)){
                printf("Zadajte cele cislo: \r\n");
                continue;
            }
            break;
        }
        
        if(n< ROW_MINCOUNT){
            printf("Zadaj vacsi pocet riadkov\r\n");
            continue;
        }
        
        if(n > ROW_MAXCOUNT){
            printf("Zadaj mensi pocet riadkov\r\n");
            continue;
        }
        
        rowCount = n;
        break;
    }
    
    while(1){
        printf("Pocet stlpcov: \r\n");
        
        char s[100];
        long n;
        
        while(1){
            if(getStr(s) == ESC_VALUE){
                printf("Hra bola ukoncena\r\n");
                return 0;
            }
            
           
            if(!strToLong(s, &n)){
                printf("Zadajte cele cislo: \r\n");
                continue;
            }
            break;
        }
        
        if(n < COLUMN_MINCOUNT){
            printf("Zadaj vacsi pocet stlpcov\r\n");
            continue;
        }
        
        if(n > COLUMN_MAXCOUNT){
            printf("Zadaj mensi pocet stlpcov\r\n");
            continue;
        }
        
        columnCount = n;
        break;
    }
    
    
    GAME g(rowCount, columnCount);
    g.printGameArea();


    
    while(1){
        while(1){
            printf("Na rade je hrac%d\r\n", playerToPlay);
            printf("Zadaj cislo stlpca: \r\n");
        
            char s[100];
            long n;
        
        while(1){
            if(getStr(s) == ESC_VALUE){
                printf("Hra bola ukoncena\r\n");
                return 0;
            }
            
           
            if(!strToLong(s, &n)){
                printf("Zadajte cele cislo: \r\n");
                continue;
            }
            break;
        }
        
        if(n < 1 || n > columnCount){
            printf("Zadal si nespravne cislo stlpca\r\n");
            continue;
        }
        
        bool tmp;
        
        if(playerToPlay == 1){
            tmp = g.setGameArea(n, pl1);
            playerToPlay = 2;
        }else{
            tmp = g.setGameArea(n, pl2);
            playerToPlay = 1;
        }
        
            if(!tmp){
                printf("Nastala chyba!\r\n");
                continue;
            }
            g.printGameArea();
            break;
        }
        
        
    }

    printf("Hra bola ukoncena\r\n");
    return 0;
}




