/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on July 24, 2017, 12:33 PM
 */

#include <iostream>

using namespace std;

void count2(int [],int );

int main(int argc, char** argv) {
    int SIZE=100;
    int array[SIZE];
    int n=10;
    
    cout<<"Enter the amount of entries you will be putting into the array"<<endl;
    cin>>n;
    
    for (int i=0;i<n;i++){
        cout<<"Enter value "<<endl;;
        cin>>array[i];
    }
    
    count2(array,n);
    
   
    return 0;
}


void count2(int array[],int n){
    int count=0;
    for (int i=0;i<n;i++){
        if(array[i]==2){
            count++;
        }
    }
    cout<<"There are "<<count<<" twos in the array";
}