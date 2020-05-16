package com.comp1601.truefalsequiz;

import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;
import android.util.Log;
import androidx.appcompat.app.AppCompatActivity;
import java.util.ArrayList;
import android.os.Build;


public class MainActivity extends AppCompatActivity {

    private  final String TAG = this.getClass().getSimpleName() + " @" + System.identityHashCode(this);

    private Button mYesButton;
    private Button mNoButton;
    private TextView mQuestionTextView;
    private ArrayList<Question> mQuestions = new ArrayList<Question>();
    private int mCurrentQuestionIndex = 0;

    public String getDeviceInfo(){
        String s = "Device Info:";
        try{
            s += "\n OS Version: " + System.getProperty("os.version") + "(" + android.os.Build.VERSION.INCREMENTAL + ")";
            s += "\n OS API Level: " + android.os.Build.VERSION.SDK_INT;
            s += "\n Device: " + android.os.Build.DEVICE;
            s += "\n Model (and Product): " + android.os.Build.MODEL + "(" + android.os.Build.PRODUCT + ")";
            s += "\n RELEASE: " + android.os.Build.VERSION.RELEASE;
            s += "\n Device: " + android.os.Build.BRAND;
            s += "\n DISPLAY: " + android.os.Build.DISPLAY;
            s += "\n HARDWARE: " + android.os.Build.HARDWARE;
            s += "\n Build ID: " + android.os.Build.ID;
            s += "\n MANUFACTURER: " + android.os.Build.MANUFACTURER;
            s += "\n USER: " + android.os.Build.USER;
            s += "\n HOST: " + android.os.Build.HOST;
        }catch (Exception e){
            Log.e(TAG, "Error getting Device INFO");
        }

        return s;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mYesButton = (Button) findViewById(R.id.yes_button);
        mNoButton = (Button) findViewById(R.id.no_button);
        mQuestionTextView = (TextView) findViewById(R.id.question_text_view);

        mQuestions.add(new Question(getString(R.string.question1)));
        mQuestions.add(new Question(getString(R.string.question2)));
        mQuestions.add(new Question(getString(R.string.question3)));
        mQuestions.add(new Question(getString(R.string.question4)));
        mQuestions.add(new Question(getString(R.string.question5)));

        for(Question q : mQuestions)
            System.out.println("Q: " + q.getQuestion() + " A: " + q.getAnswer());

        mQuestionTextView.setText(mQuestions.get(mCurrentQuestionIndex).getQuestion());

        Log.i(TAG, getDeviceInfo());

        mYesButton.setOnClickListener(v -> {
            //Handle the yes button click
            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals("Yes")) {
                Toast.makeText(MainActivity.this,
                        R.string.correct_answer_toast,
                        Toast.LENGTH_SHORT).show();
            }
            else{
                Toast.makeText(MainActivity.this,
                        R.string.wrong_answer_toast,
                        Toast.LENGTH_SHORT).show();

            }
            mCurrentQuestionIndex++;
            if(mCurrentQuestionIndex >= mQuestions.size()) mCurrentQuestionIndex = 0;
            mQuestionTextView.setText(mQuestions.get(mCurrentQuestionIndex).getQuestion());
            //System.out.println("Yes button was clicked");
            Log.i(TAG, "Yes Button Pressed");

        });
        mNoButton.setOnClickListener(v -> {
            //Handle the no button click
            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals("No")) {
                Toast.makeText(MainActivity.this,
                        R.string.correct_answer_toast,
                        Toast.LENGTH_SHORT).show();
            }
            else{
                Toast.makeText(MainActivity.this,
                        R.string.wrong_answer_toast,
                        Toast.LENGTH_SHORT).show();

            }
            mCurrentQuestionIndex++;
            if(mCurrentQuestionIndex >= mQuestions.size()) mCurrentQuestionIndex = 0;
            mQuestionTextView.setText(mQuestions.get(mCurrentQuestionIndex).getQuestion());
            //System.out.println("No button was clicked");
            Log.i(TAG, "No Button Clicked");

        });
    }
}
