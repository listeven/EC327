package com.example.bangbang;

import android.app.DialogFragment;
import android.content.pm.ActivityInfo;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ImageView;
import android.os.CountDownTimer;

public class PlayScreen extends AppCompatActivity {

    private TextView Ammo;
    private TextView Ammo2;
    private TextView hp1;
    private TextView hp2;
    private Button attackButton;
    private Button defendButton;
    private Button reloadButton;
    private Button doubleButton;
    final gameEng engine = new gameEng();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_play_screen);
        getSupportActionBar().hide();
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);

        attackButton = (Button) findViewById(R.id.attackButton);
        defendButton = (Button) findViewById(R.id.defendButton);
        reloadButton = (Button) findViewById(R.id.reloadButton);
        doubleButton = (Button) findViewById(R.id.doubleButton);
        Ammo = (TextView) findViewById(R.id.Ammo_Amount);
        Ammo2 = (TextView) findViewById(R.id.compammo);
        hp1 = (TextView) findViewById(R.id.HP1);
        hp2 = (TextView) findViewById(R.id.health2);

        Ammo.setText("Ammo = " + "" + 1);
        Ammo2.setText("Ammo = " + "" + 1);
        hp1.setText("Health: " + "" + 5);
        hp2.setText("Health: " + "" + 5);
        View.OnClickListener attackListener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(engine.user_Ammo <= 0 ){
                    Toast toast = Toast.makeText(getApplicationContext(), "Not enough ammo", Toast.LENGTH_SHORT);
                    toast.setGravity(Gravity.CENTER, 0, 0);
                    toast.show();
                    return;
                }

                engine.User_Turn('A');
                engine.Comp_Turn();
                engine.compareActions();
                gameCheck(engine);

                ImageView img = (ImageView)findViewById(R.id.ninja);
                img.setImageResource(R.drawable.ninja_attack);

                new CountDownTimer(2000, 1000) {

                    public void onTick(long millisUntilFinished) {
                    }

                    public void onFinish() {
                        ImageView img = (ImageView)findViewById(R.id.ninja);
                        img.setImageResource(R.drawable.ninjas);
                    }
                }.start();
            }
        };

        View.OnClickListener defendListener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                engine.User_Turn('D');
                engine.Comp_Turn();
                engine.compareActions();
                gameCheck(engine);

                ImageView img = (ImageView)findViewById(R.id.ninja);
                img.setImageResource(R.drawable.ninja_defense);

                new CountDownTimer(2000, 1000) {

                    public void onTick(long millisUntilFinished) {
                    }

                    public void onFinish() {
                        ImageView img = (ImageView)findViewById(R.id.ninja);
                        img.setImageResource(R.drawable.ninjas);
                    }
                }.start();
            }
        };

        View.OnClickListener reloadListener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                engine.User_Turn('R');
                engine.Comp_Turn();
                engine.compareActions();
                gameCheck(engine);

                ImageView img = (ImageView)findViewById(R.id.ninja);
                img.setImageResource(R.drawable.ninja_reload);

                new CountDownTimer(2000, 1000) {

                    public void onTick(long millisUntilFinished) {
                    }

                    public void onFinish() {
                        ImageView img = (ImageView)findViewById(R.id.ninja);
                        img.setImageResource(R.drawable.ninjas);
                    }
                }.start();
            }
        };

       View.OnClickListener doubleListener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if(engine.user_Ammo <= 1 ){
                    Toast toast = Toast.makeText(getApplicationContext(), "Not enough ammo", Toast.LENGTH_SHORT);
                    toast.setGravity(Gravity.CENTER, 0, 0);
                    toast.show();
                    return;
                }

                engine.User_Turn('O');
                engine.Comp_Turn();
                engine.compareActions();
                gameCheck(engine);
            }
        };

        attackButton.setOnClickListener(attackListener);
        defendButton.setOnClickListener(defendListener);
        reloadButton.setOnClickListener(reloadListener);
        doubleButton.setOnClickListener(doubleListener);

    } //On create

    private void gameCheck(gameEng engine){

        if (engine.user_HP <= 0 || engine.comp_HP <= 0) {

            DialogFragment dlg = new dlgFragment();
            dlg.show(getFragmentManager(), "MyDialogFragmentTag");
            return;
        }

        if(engine.state == 'S'){

            Toast toast = Toast.makeText(getApplicationContext(), "Attack was successful!", Toast.LENGTH_SHORT);
            toast.setGravity(Gravity.CENTER, 0, 0);
            toast.show();
        }

        if(engine.state == 'D'){

            Toast toast = Toast.makeText(getApplicationContext(), "Attack was blocked!", Toast.LENGTH_SHORT);
            toast.setGravity(Gravity.CENTER, 0, 0);
            toast.show();
        }

        if(engine.state == 'N'){

            Toast toast = Toast.makeText(getApplicationContext(), "Nothing happened", Toast.LENGTH_SHORT);
            toast.setGravity(Gravity.CENTER, 0, 0);
            toast.show();
        }

        Ammo.setText("Ammo = " + "" + engine.user_Ammo);
        Ammo2.setText("Ammo = " + "" + engine.comp_Ammo);
        hp1.setText("Health: " + "" + engine.user_HP);
        hp2.setText("Health: " + "" + engine.comp_HP);
    }



}
