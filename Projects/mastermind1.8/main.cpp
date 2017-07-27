
/* 
 * File:   main.cpp
 * Author: Derek Earl
 * Purpose: Mastermind project
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
void scorSrt(int[],string[],int);//Sorting High Scores




int main(int argc, char** argv) {

    const int size=20,SIZE=4;// various sizes needed
    string name;//string for name and answer to determine replays
    int gmctr=0,numgues=8,trnctr=0,blkctr=0,whtctr=0,check,stpWht0=0,stpWht1=0,stpWht2=0,stpWht3=0; //game number counter, number of guesses
    char guess[SIZE]={'q','a','z','x'},correct[SIZE]={'q','a','z','x'},ans;//arrays for guesses and correct answers
    bool again=true;//boolean for while loop
    int wins=0,hiscore=11;//wins counter and high score!
    int rows=20,column=4;
    int x=0,y=0;
    char gameBrd [rows][column];

    
    intro();

    cout<<endl<<endl;

    cout<<"Please enter your first name (no spaces)\n";

    cin>>name;
    
    while (again){
        
        trnctr=0; //resets turns to zero
        gmctr++; //game counter to find win/loss ratio later
        srand(time(0));//setting time
        correct[0]='A';
        correct[1]='X';
        correct[2]='Q';
        correct[3]='V';
        for ( x=0;x<rows;x++){
        for( y=0;y<column;y++){
            gameBrd [x][y]=' ';                 
        }       
    }
        x=0;
        y=0;
        for (int i=0;i<4;i++){
        
        //selecting correct answers and establishing number counts
            
        int temp=(rand()%6+1);
        
         //establishing conditions to roll for a new set of correct answers
        switch (temp){
          //Determines correct peg color for position
            case 1: correct[i] = 'B'; break;

            case 2: correct[i] = 'G'; break;

            case 3: correct[i] = 'P'; break;

            case 4: correct[i] = 'O'; break;

            case 5: correct[i] = 'Y'; break;

            case 6: correct[i] = 'R'; break;

        }
        //If any pegs match it rerolls that peg
         if (correct[0]==correct[1]||

               correct[0]==correct[2]||

               correct[0]==correct[3]||

               correct[1]==correct[2]||

               correct[1]==correct[3]||

               correct[2]== correct[3]

               ){i--;} //This is so we re-roll duplicates      
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
            y=0;
            

            cout<<correct[0]<<correct[1]<<correct[2]<<correct[3]; //Correct answers shown for testing

            cout<<"You're on turn "<<trnctr<<endl;

            

            cout<<"you have "<<numgues-trnctr<<" turns after this one"<<endl;

            do{// BOTH input entry and entry validation!

                check=0;

                cout<<"Enter your guess: ";

            cin>>guess[0]>>guess[1]>>guess[2]>>guess[3];

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
            
            for (int i=0;i<4;i++){
                gameBrd[x][i]=guess[i];
            }     
                                  
            //This is to determine the number of correct color and positions
            for(int i=0;i<4;i++){

                if(guess[i]==correct[i]){
                    blkctr++;
                }
                }
            //This determines number of correct colors but wrong position
            if (guess[0]==correct[1]
                && correct[1]!=guess[1]
                && stpWht1<1){
                whtctr++;
                stpWht1++;
                }
            if(guess[0]==correct[2]&&
                    guess[2]!=correct[2]
                    &&stpWht2<1){
                whtctr++;
                stpWht2++;
                }
            if(guess[0]==correct[3]&&
                guess[3]!=correct[3]
                 &&stpWht3<1){
                whtctr++;
                stpWht3++;
                }
            if(guess[1]==correct[0]&&
               guess[0]!=correct[0]
               &&stpWht0<1){
                 whtctr++;
                stpWht0++;
                }
            if(guess[1]==correct[2]&&
               guess[2]!=correct[2]&&                    
               stpWht2<1){
                    whtctr++;
                    stpWht2++;
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
                stpWht0++;
                }
            if(guess[2]==correct[1]&&
                    guess[1]!=correct[1]
                    &&stpWht1<1){
                whtctr++;
                stpWht1++;
                }
            if(guess[2]==correct[3]&&
                    guess[3]!=correct[3]
                    &&stpWht3<1){
                whtctr++;
                stpWht3++;
            }
            if(guess[3]==correct[0]&&
                    guess[0]!=correct[0]&&
                    stpWht0<1){
                whtctr++;
                stpWht0++;
                }
            if(guess[3]==correct[1]&&
                    guess[1]!=correct[1]&&
                    stpWht1<1){
                whtctr++;
                stpWht1++;
                }
            if(guess[3]==correct[2]&&
                    guess[2]!=correct[2]&&
                    stpWht2<1){
                whtctr++;
                stpWht2++;
                }
            //cout<<"Y "<<y<<endl;
            //PRINT OUT W's
            for (int i=0;i<whtctr;i++){
                gameBrd[x+1][y]='W';
                y++;
                
            }
            //PRINT OUT B's
            for (int i=0;i<blkctr;i++){ 
                gameBrd[x+1][y]='B';
                y++;
            }
            cout<<"GAME BOARD"<<endl;
            //THIS IS HOW I WILL OUTPUT THE GAME BOARD 
            for(int i=19;i>-1;i--){
                for (int j=0;j<4;j++){
                    cout<<gameBrd[i][j];      
                }
                cout<<endl;
            }
            //cout<<"STOPWHITES "<<stpWht0<<" "<<stpWht1<<" "<<stpWht2<<" "<<stpWht3<<endl;
            //cout<<"BLACK COUNTER "<<blkctr<<endl;
            //cout<<"WHITE COUNTER "<<whtctr<<endl;
            //cout<<"Y again "<<y<<endl;
            cout<<endl;
            x+=2;
            
        } while(isless(trnctr,numgues)&& blkctr<4); //ends when turns are over or game is won
        cout<<"The correct code was: ";
        //to print correct code
        for(int i=0;i<4;i++){
        cout<<correct[i];
        }
        //for the laughs
        if (correct[0]=='O'&& correct[1]=='R'&& correct[2]=='G' &&correct[3]=='Y'){
            cout<<"  *ahem*  ...This is awkward...";
        }
        cout<<endl;
        //reflects win state
        if (blkctr==4){
            cout<<"YOU CRACKED THE CODE! It took you "<<trnctr<<" tries!"<<endl;
            wins++;
            if(trnctr<hiscore){
                hiscore=trnctr;
            }
            ofstream myfile;
            myfile.open("newfile.txt",ios::app);
            myfile<<endl<<name<<setw(10)<<trnctr;
            myfile.close();
        }
        //reflects lose state
        else{
            cout<<"Seems you couldn't crack the code after all. \n";
            cout<<"No need to give up though, you could always try again!\n";
        }

        
        //sets highscore if beaten and outputs that to file
        if (hiscore<11){
            cout<<"The best score this session is: "<<hiscore<<endl;
        }

        cout<<fixed<<setprecision(2)<<showpoint;
        
        cout<<setw(51)<<"High Scores"<<endl;
  cout<<setw(33)<<"Name"<<setw(30)<<"Turns used"<<endl;
  
    ifstream showBrd; 
    int SIZE=100;
    string names[SIZE]={};
    int scores[SIZE]={};
    showBrd.open("newfile.txt");

    
    for (int i=0;i<SIZE;i++){
        showBrd>>names[i];
        showBrd>>scores[i];
    }
    

    showBrd.close(); 
    //Sort and Display Leader Board
    scorSrt(scores,names,SIZE);
    for(int i=0;i<10;i++){
        if (scores[i]>0){
        cout<<setw(35)<<names[i];
        cout<<setw(25)<<scores[i]<<endl;
        }
    }


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
    cout<<"The number of whites signifies how many of your pegs are a color that's \n";
    cout<<"in the code but in the wrong place.\n";
    cout<<"In this version there will be no duplicate pegs involved in the code\n";
    cout<<"You will have 8 turns to crack the code.\n";   
    
}
//Sorting High scores
void scorSrt(int a[],string b[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]&& a[j]>0){
                int temp1=0;
                string temp2="";
                temp1=a[i];
                a[i]=a[j];
                a[j]=temp1;
                temp2=b[i];
                b[i]=b[j];
                b[j]=temp2;
                
            }
        }
    }
}