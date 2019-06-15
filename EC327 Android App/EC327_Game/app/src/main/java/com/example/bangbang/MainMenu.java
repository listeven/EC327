package com.example.bangbang;

import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainMenu extends AppCompatActivity {

    private Button playButton;
    private Button quitButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_menu);
        getSupportActionBar().hide();
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);

        playButton = (Button) findViewById(R.id.play_screen);
        quitButton = (Button) findViewById(R.id.quit_Button);

        View.OnClickListener listener1 = new View.OnClickListener(){
            @Override
            public void onClick(View v){
                launchPlayActivity();
            }
        };

        View.OnClickListener listener2 = new View.OnClickListener(){
            @Override
            public void onClick(View v){
                finish();
            }
        };

        playButton.setOnClickListener(listener1);
        quitButton.setOnClickListener(listener2);

    }

    private void launchPlayActivity(){
        Intent intent = new Intent(this, PlayScreen.class);
        startActivity(intent);
    }



}
