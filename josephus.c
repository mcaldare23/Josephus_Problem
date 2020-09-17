//UCI FALL 2017   EECS 22       Assignment 1
						                	
//Josephus Problem

//author: Martino Caldarella	

//Date completed: 10/07/2017

#include<stdio.h>

int main(){

        int numOfPeople;

        printf("How many people are in the circle? ");
        scanf("%d",&numOfPeople);                               //input

        int circle[numOfPeople];                                //array that simulates circle of people
        int killed = 0;                                         //initial number of killed people
        int newCircle[numOfPeople-killed];                      //temporary array
        int i;                                                  //counter for array
        int j;                                                  //counter for temorary array
        int rounds = 0;                                         //counter for rounds (used to calculate max kills per person)

        for(i = 0; i < numOfPeople; i++){
                circle[i] = i+1; //rof                            //fills the array
        }

        while(numOfPeople > 1){                                  //stops when 1 person is left

                for(i = 0; i < numOfPeople; i++){

                        if(i%2 == 1){                           //assign '0' to killed people
                                circle[i] = 0;
                                killed++; //fi
                        }
                } //rof

                rounds++;
                j = 0;

                for(i = 0; i < numOfPeople; i++){              //copy soldiers not killed to temp array
                        if(circle[i] != 0){
                                newCircle[j] = circle[i];
                                j++; //fi
                        }
                } //rof

                numOfPeople = numOfPeople - killed;             //reduces size of array
                j = 0;

                if(numOfPeople == killed){
                        for(i = 0; i < numOfPeople; i++){      //copy temp array to array
                                circle[i] = newCircle[j];       //keeps same positions
                                j++;
                        } //rof
                }

                else{
                        for(i = 0; i < numOfPeople; i++){      //last position becomes first
                                circle[i+1] = newCircle[j];
                                j++;
                        }
                        circle[0] = newCircle[numOfPeople-1];
                } //fi

                killed = 0;                                     //reset number of kills for next rounds

        } //elihw

        printf("The spot %d is safe.\n", circle[0] );           //output
        printf("Most executions by an individual are %d. \n", rounds - 1);

return 0;
}


