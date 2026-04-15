#include <stdio.h>
#include <unistd.h>

    typedef enum{
        RED,
        RED_AMBER,
        GREEN,
        AMBER
    }State;

void printState(State currentState);
int getDelay(State currentState);
State updateState(State currentState);

int main(){
   State currentState = RED;
   int pedestrianRequest = 0;
   char userInput = 'n';
    
    for(int i=1;i<=10;i++){
    printState(currentState);
        
    if(currentState == GREEN){    
    printf("Activate pedestrian button?: \n");
    scanf(" %c", &userInput);
    
    if(userInput == 'y'){
    pedestrianRequest = 1;
    printf("Pedestrian Access Requested\n");
    }
    }
    
    sleep(getDelay(currentState));
    
    if(pedestrianRequest == 1 && currentState == RED){
    printf("Walk\n");
    sleep(5);
    pedestrianRequest = 0;
    }
    
    currentState = updateState(currentState);
    }
    return 0;
}

void printState(State currentState){
    switch(currentState){
        case RED:
            printf("RED\n");
            break;

        case RED_AMBER:
            printf("RED_AMBER\n");
            break;
        
        case GREEN:
            printf("GREEN\n");
            break;
        
        case AMBER:
            printf("AMBER\n");
            break;
    }
}

int getDelay(State currentState){
    switch(currentState){
        case RED:
        return 5;
        
        case RED_AMBER:
        return 1;
        
        case GREEN:
        return 5;
        
        case AMBER:
        return 2;
    }
    return 0;
}

State updateState(State currentState){
    switch(currentState){
        case RED:
            currentState = RED_AMBER;
            break;

        case RED_AMBER:
            currentState = GREEN;
            break;
        
        case GREEN:
            currentState = AMBER;
            break;
        
        case AMBER:
            currentState = RED;
            break;
    }
    return currentState;
}
