/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on July 19, 2017, 3:11 PM
 */
//Libraries
#include <iostream>//Input output file
#include <iomanip>//for manipulating values
#include <cmath>//math functions
#include <cstdlib>//time
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

//functional prototypes
void intro(); //This Function will display the intro to the game, explaining rules


int main(int argc, char** argv) {
    const int size=20,SIZE=4;// various sizes needed
    char name[size],ans;
    int gmctr=0,numgues=10,trnctr=0,blkctr=0,whtctr=0,check,stpWht0,stpWht1,stpWht2,stpWht3; //game number counter, number of guesses
    char guess[SIZE],correct[size];
    bool again=true;
    int wins=0,hiscore=11;//wins counter and high score!
    


    intro();
    cout<<endl<<endl;
    cout<<"Please enter your name\n";
    cin.getline(name,size);
    cin.clear();
    
    while (again){
        trnctr=0; //resets turns to zero
        gmctr++; //game counter to find win/loss ratio later
        srand(time(0));//setting time
        
        correct[size]=(1,2,3,4); //this allows the for a future re-rolling mechanic
        //to stop duplicates.
        for (int i=0;i<4;i++){
        //selecting correct answers and establishing number counts
        int temp=(rand()%6+1);
        switch (temp){
            case 1: correct[i] = 'B'; break;
            case 2: correct[i] = 'G'; break;
            case 3: correct[i] = 'P'; break;
            case 4: correct[i] = 'O'; break;
            case 5: correct[i] = 'Y'; break;
            case 6: correct[i] = 'R'; break;
        }
            if (correct[0]==correct[1]||
               correct[0]==correct[2]||
               correct[0]==correct[3]||
               correct[1]==correct[2]||
               correct[1]==correct[3]||
               correct[2]== correct[3]
               )
            {i--;} //This is so we re-roll duplicates 
        }
        
       
        cout<<"\nAlright "<<name<<" the game is starting now\n";
        
        do{
            whtctr=0;
            blkctr=0;
            stpWht0=0;
            stpWht1=0;
            stpWht2=0;
            stpWht3=0;
                    
            trnctr++;
            cout<<correct[0]<<correct[1]<<correct[2]<<correct[3];
            cout<<"You're on turn "<<trnctr<<endl;
            
            cout<<"you have "<<numgues-trnctr<<" turns after this one"<<endl;
            do{// BOTH input entry and entry validation!
                check=0;
                cout<<"Enter your guess: ";
            cin>>guess[0]>>guess[1]>>guess[2]>>guess[3];
            cout<<guess[0]<<guess[1]<<guess[2]<<guess[3]<<endl;
            
            for(int i=0;i<4;i++){
                if (guess[i]=='B'||guess[i]=='G'||guess[i]=='P'
                        ||guess[i]=='O'||guess[i]=='Y'||guess[i]=='R'){
                    check++;
                }
                else{
                    cout<<guess[i]<<" is an invalid entry "<<name<<"!"<<endl;
                    
                }
            }
            } while(check<4);
            
            cout<<setw(40);
            
            for(int i=0;i<4;i++){
        cout<<guess[i];
        }
            cout<<endl<<setw(40);
            for(int i=0;i<4;i++){
                if(guess[i]==correct[i]){
                    blkctr++;
                }
                }
            //This determines number of correct colors 
            if (guess[0]==correct[1]
            && correct[1]!=guess[1]){
                whtctr++;
                stpWht1++;
                }
            if(guess[0]==correct[2]&&
                    guess[2]!=correct[2]){
                whtctr++;
                stpWht2++;
                }
            if(guess[0]==correct[3]&&
                    guess[3]!=correct[3]){
                whtctr++;
                stpWht3++;
                }
            if(guess[1]==correct[0]&&
                    guess[0]!=correct[0]){
                whtctr++;
                stpWht0++;
                }
            if(guess[1]==correct[2]&&
                    guess[2]!=correct[2]){
                whtctr++;
                }
            if(guess[1]==correct[3]&&
                    guess[3]!=correct[3]
                    &&stpWht3<1){
                whtctr++;
                stpWht3++;
                }
            if(guess[2]==correct[0]&&
                    guess[0]!=correct[0]
                    && stpWht0<1){
                whtctr++;
                }
            if(guess[2]==correct[1]&&
                    guess[1]!=correct[1]
                    &&stpWht1<1){
                whtctr++;
                stpWht1++;
                }
            if(guess[2]==correct[3]&&
                    guess[3]!=correct[3]){
                whtctr++;
                stpWht3++;
                }
            if(guess[3]==correct[0]&&
                    guess[0]!=correct[0]
                    &&stpWht0<1){
                whtctr++;
                stpWht0++;
                }
            if(guess[3]==correct[1]&&
                    guess[1]!=correct[1]){
                whtctr++;
                stpWht1++;
                }
            if(guess[3]==correct[2]&&
                    guess[2]!=correct[2]){
                whtctr++;
                stpWht2++;
                }
            //PRINT OUT W's
            for (int i=0;i<whtctr;i++){
                cout<<"W";
            }
            //PRINT OUT B's
            for (int i=0;i<blkctr;i++){ 
                cout<<"B";
            }
            
            cout<<endl;
            
            
        } while(isless(trnctr,numgues)&& blkctr<4); //ends when turns are over or game is won
        
        cout<<"The correct code was: ";
        //to print correct code
        for(int i=0;i<4;i++){
        cout<<correct[i];
        }
        cout<<endl;
        
        if (blkctr=4){
            if(trnctr<hiscore){
                hiscore=trnctr;
            }
            cout<<"YOU CRACKED THE CODE! It took you "<<trnctr<<" tries!"<<endl;
            wins++;
            
        }
        else{
            cout<<"Seems you couldn't crack the code after all. \n";
            cout<<"No need to give up though, you could always try again!\n";
        }
        
        if (hiscore<11){
            cout<<"The best score this session is: "<<hiscore<<endl;
        }
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<"Your current win to loss ratio is "<<static_cast<float>(wins)/gmctr<<endl;
        
        cout<<"Would you like to play again?(Y/N)"<<endl;
        cin>>ans;
        
        again=(ans=='Y'||ans=='y')? true:false;
    }
            
   
    
    
    return 0;
}

void intro(){
    cout<<"******************************<<MasterMind!!>>************************************"<<endl;
    cout<<endl<<endl<<endl;
    cout<<"Master mind is a code breaking game!\n";
    cout<<"In this game you must use logic to determine the four color combination\n";
    cout<<"of pegs made by the computer by placing your own and getting results. \n";
    cout<<"The colors possible are Blue,Green,Purple,Orange,Yellow and Red\n";
    cout<<"You will be prompted for your attempt at the code.\n";
    cout<<"Sample input would be: GRYP (Green Red Yellow Purple)\n";
    cout<<"The computer will then tell you how close you are by outputting\n";
    cout<<"B's and W's (signifying Black and White pegs)\n";
    cout<<"The number of blacks signifies how many of your pegs are \n";
    cout<<"both the right color AND in the correct position \n";
    cout<<"The number of reds signifies how many of your pegs are a color that's \n";
    cout<<"in the code but in the wrong place.\n";
    cout<<"You will have 10 turns to crack the code. Good luck!\n";
    
    
}

    
      
    
