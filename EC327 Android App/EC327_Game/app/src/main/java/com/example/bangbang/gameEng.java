package com.example.bangbang;

import android.support.v7.app.AppCompatActivity;

import java.util.Random;

/**
 * Created by Steven on 12/5/2016.
 */

public class gameEng extends AppCompatActivity {

    public boolean userWin, userLose, userTurn;
    public char user1_Input; // A or D or R
    public char comp_input;
    public char[] inputarray;

    public  int user_HP = 5;
    public  int comp_HP = 5;
    public  int user_Ammo = 1;
    public  int comp_Ammo = 1;
    //public double points;
    //public int time;

    public char state;




    public void User_Turn(char input){

        user1_Input = input;

    };

    public void Comp_Turn(){

        Random r = new Random(System.nanoTime());

        int randaction = r.nextInt(3);
        while(comp_Ammo<=0 && randaction == 0){
            randaction = r.nextInt(3);
        }
        inputarray = new char [4];

        inputarray[0] = 'A';
        inputarray[1] = 'D';
        inputarray[2] = 'R';
        //inputarray[3] = 'O';


        comp_input = inputarray[randaction];



    };

    public void compareActions(){

        if ( user1_Input == comp_input ){

            state = 'N';

            // If same command

        }

        else if ((user1_Input == 'A' /*|| user1_Input == 'O'*/) && comp_input == 'D'){

            state = 'D';
            if(user1_Input == 'A'){

            }
            else{
                user_Ammo = user_Ammo - 2;
            }
            //Cancel attack
        }

        else if(user1_Input == 'A' && comp_input == 'R'){

            state = 'S';

            comp_HP = comp_HP - 3;

        }

        else if(user1_Input == 'D' && (comp_input == 'A' /*|| comp_input == 'O'*/)){
            if(comp_Ammo <= 0)
            {

            }
            state = 'D';
            //Cancel attack
        }

        else if(user1_Input == 'D' && comp_input == 'R'){

            state = 'N';

            //nothing happens
        }

        else if(user1_Input == 'R' && comp_input =='A'){

            state = 'S';

            user_HP = user_HP - 3;


        }

        else if(user1_Input == 'R' && comp_input == 'D'){

            state = 'N';


            //nothing happens
        }

        if (user1_Input == 'R')
        {
            user_Ammo++;
        }

        if (user1_Input == 'A')
        {
            user_Ammo--;
        }

        if (comp_input == 'A')
        {
            comp_Ammo--;
        }

        if (comp_input == 'R')
        {
            comp_Ammo++;
        }


    }
}
