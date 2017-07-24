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

bool true2(int [],int );

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
    
    
    if (true2(array,n)== true){
        cout<<"The array begins or ends with 2"<<endl;
    }
    else{
        cout<<"neither "<<array[0]<<" or "<<array[n]<<" equal two"<<endl;
    }
    return 0;
}


bool true2(int array[],int n){
    if (array[0]==2 || array[n]==2){
        return true;
    }
    else{return false;}
}