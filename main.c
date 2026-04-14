#include <stdio.h>

int main(){
    typedef enum{
        RED,
        RED_AMBER,
        GREEN,
        AMBER
    }State;
    
   State currentState = RED;
    
    for(int i=1;i<=8;i++){
    switch (currentState){
        case RED:
        printf("RED\n");
        currentState = RED_AMBER;
        break;
        
        case RED_AMBER:
        printf("RED_AMBER\n");
        currentState = GREEN;
        break;
        
        case GREEN:
        printf("GREEN\n");
        currentState = AMBER;
        break;
        
        case AMBER:
        printf("AMBER\n");
        currentState = RED;
        break;
    }
    }
    return 0;
}
