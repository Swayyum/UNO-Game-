#include <iostream>
#include <vector>
#include <stdlib.h>
#include "card.h"



//RENDERING ISSUE CAUSES SOME CARDS NOT TOO LOAD WITH COLORS OCCASIONALLY THIS IS THE COMPUTERS FAULT
Color Card::getColor() const{
    return color;
}
    
int Card::getNumber() const{
    return number;
}

void Card::setColor(Color c){
    color = c;
}

void Card::setNumber(int n){
    number = n;
}

NumberCard::NumberCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

WildCard::WildCard(Color c) {
    setColor(c);
}

ReverseCard::ReverseCard(Color c) {
    setColor(c);
}

SkipCard::SkipCard(Color c) {
    setColor(c);
}

DrawTwoCard::DrawTwoCard(Color c) {
    setColor(c);
}

DrawFourCard::DrawFourCard(Color c) {
    setColor(c);
}


string NumberCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|     " <<  number << "     |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}


string DrawTwoCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|   " << "DRAW TWO" << "   |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
            int plus2;
        default:
            return " ";
    }
}


string ReverseCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|  " << "REVERSE" << "   |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        int reverse;
        default:
            return " ";
    }
}

string SkipCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|   " << "SKIP" << "   |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        int skip;
        default:
            return " ";
    }
}


string WildCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|           |";
                break;
            case BLUE:
                return "|           |";
                break;
            case GREEN:
                return "|           |";
                break;
            case YELLOW:
                return "|           |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|   " << "WILD" << "   |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

string DrawFourCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|           |";
                break;
            case BLUE:
                return "|           |";
                break;
            case GREEN:
                return "|           |";
                break;
            case YELLOW:
                return "|           |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|   " << "DRAW FOUR" << "   |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool NumberCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        return true;
    } else {
        return false;
    }
}


bool DrawTwoCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        gameState.currentPlayerIndex = 1;
        gameState.numCardsToDraw = 2;
        gameState.currentPlayerIndex = 0;
        return true;
    } else {
        return false;
    }
}




bool ReverseCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        gameState.currentPlayerIndex = 1;
        gameState.turnDirection;
        gameState.currentPlayerIndex = 0;
        return true;
        
    } else {
        return false;
    }
}




bool SkipCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        gameState.currentPlayerIndex = 1;
        gameState.skipTurn = true;
        gameState.currentPlayerIndex = 0;
        return true;
        
    } else {
        return false;
    }
}




bool WildCard::play(Card* discard, GameState &gameState) {
    char input;
    
    gameState.currentPlayerIndex = 1;
    cout << "What color? (R/B/G/Y)" << endl;
    cin >> input;
   
    switch(input){
        case 'R':
            discard->setColor(color = RED);
            break;
        case 'B':
            discard->setColor(color = BLUE);
            break;            
        case 'G':
            discard->setColor(color = GREEN);
            break;
        case 'Y':
            discard->setColor(color = YELLOW);
            break;
       break;
    }
    return true;
}

bool DrawFourCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        gameState.currentPlayerIndex = 1;
        gameState.numCardsToDraw = 4;
        gameState.currentPlayerIndex = 0;
        
        char input;
        cout << "What color? (R/B/G/Y)" << endl;
        cin >> input;
        
        switch(input){
            case 'R':
                discard->setColor(color = RED);
                break;
            case 'B':
                discard->setColor(color = BLUE);
                break;            
            case 'G':
                discard->setColor(color = GREEN);
                break;
            case 'Y':
                discard->setColor(color = YELLOW);
                break;
            break;
        }
        return true;
    }
}
