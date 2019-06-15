package com.example.bangbang;

import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Win extends AppCompatActivity {

    private Button proceedButton;

    @Override
    protected void onCreate(Bundle savedInstanceState)   {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_win);
        getSupportActionBar().hide();
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);

        proceedButton = (Button) findViewById(R.id.proceedButton);
        View.OnClickListener proceedListener = new View.OnClickListener(){
            @Override
            public void onClick(View v){
                relaunchPlayActivity();
            }
        };

        proceedButton.setOnClickListener(proceedListener);
    }
    @Override
    public void onBackPressed(){
    }

    private void relaunchPlayActivity(){
        Intent intent = new Intent(this, PlayScreen.class);
        startActivity(intent);
    }
}
