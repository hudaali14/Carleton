package com.comp1601.truefalsequiz;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import android.content.Context;

public class MainActivity extends AppCompatActivity {

    private Button mYesButton;
    private Button mNoButton;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mYesButton = findViewById(R.id.yes_button);
        mNoButton = findViewById(R.id.no_button);

        mYesButton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                //Handle the yes button click
                Toast.makeText(MainActivity.this, R.string.correct_answer_toast, Toast.LENGTH_SHORT).show();
            }
        });
        mNoButton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                Toast.makeText(MainActivity.this, R.string.wrong_answer_toast, Toast.LENGTH_SHORT).show();
                //Handle the no button click
            }
        });
    }
}
