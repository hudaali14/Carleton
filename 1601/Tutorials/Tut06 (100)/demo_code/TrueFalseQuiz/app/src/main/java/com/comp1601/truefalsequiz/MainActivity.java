//package com.comp1601.truefalsequiz;
//
//import androidx.appcompat.app.AppCompatActivity;
//import android.os.Bundle;
//import android.view.View;
//import android.widget.Button;
//import android.widget.Toast;
//import android.widget.TextView;
//import java.util.ArrayList;
//
//public class MainActivity extends AppCompatActivity {
//
//    private Button mYesButton;
//    private Button mNoButton;
//    private TextView mQuestionTextView;
//    private int mCurrentQuestionIndex = 0;
//    private ArrayList<Question> mQuestions;
//
//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
//        mYesButton = findViewById(R.id.yes_button);
//        mNoButton = findViewById(R.id.no_button);
//
//        mQuestions = new ArrayList<Question>();
//        mQuestionTextView = (TextView) findViewById(R.id.question_text_view);
//
//        mQuestions.add(new Question(getString(R.string.question1)));
//        mQuestions.add(new Question(getString(R.string.question2)));
//        mQuestions.add(new Question(getString(R.string.question3)));
//        mQuestions.add(new Question(getString(R.string.question4)));
//        mQuestions.add(new Question(getString(R.string.question5)));
//
//        mQuestionTextView.setText(mQuestions.get(mCurrentQuestionIndex).getQuestion());
//
//        for(Question q : mQuestions){
//            System.out.println("Q: " + q.getQuestion() + "A: " + q.getAnswer());
//        }
//
//        mYesButton.setOnClickListener(v -> {
//            //Handle the yes button click
//            String s = getString(R.string.yes_button_label);
//            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals("Yes")){
//                Toast.makeText(MainActivity.this,
//                        R.string.correct_answer_toast,
//                        Toast.LENGTH_SHORT).show();
//            }else{
//                Toast.makeText(MainActivity.this,
//                        R.string.wrong_answer_toast,
//                        Toast.LENGTH_SHORT).show();
//            }
//            mCurrentQuestionIndex++;
//            if(mCurrentQuestionIndex >= mQuestions.size()){
//                mCurrentQuestionIndex = 0;
//            }
//            mQuestionTextView.setText(mQuestions.get(mCurrentQuestionIndex).getQuestion());
//        });
//
//        mNoButton.setOnClickListener(v -> {
//            //Handle the no button click
//            String s = getString(R.string.no_button_label);
//            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals("No")){
//                Toast.makeText(MainActivity.this,
//                        R.string.correct_answer_toast,
//                        Toast.LENGTH_SHORT).show();
//            }else{
//                Toast.makeText(MainActivity.this,
//                        R.string.wrong_answer_toast,
//                        Toast.LENGTH_SHORT).sh
//            }
//            mCurrentQuestionIndex++;
//            if(mCurrentQuestionIndex >= mQuestions.size()){
//                mCurrentQuestionIndex = 0;
//            }
//            mQuestionTextView.setText(mQuestions.get(mCurrentQuestionIndex).getQuestion());
//
//        });
//    }
//}

package com.comp1601.truefalsequiz;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import android.widget.TextView;
import java.util.ArrayList;
import java.util.Random;

public class MainActivity extends AppCompatActivity {

    private Button mAButton;
    private Button mBButton;
    private Button mCButton;
    private Button mDButton;
    private Button mEButton;
    private Button mPrevButton;
    private Button mNextButton;
    private Button mSubmitButton;
    private int answeredCorrect = 0;
    private TextView mQuestionTextView;
    private int mCurrentQuestionIndex = 0;
    private ArrayList<Question> mQuestions;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mAButton = findViewById(R.id.a_button);
        mBButton = findViewById(R.id.b_button);
        mCButton = findViewById(R.id.c_button);
        mDButton = findViewById(R.id.d_button);
        mEButton = findViewById(R.id.e_button);
        mPrevButton = findViewById(R.id.prev_button);
        mNextButton = findViewById(R.id.next_button);

        mQuestions = new ArrayList<Question>();
        mQuestionTextView = (TextView) findViewById(R.id.question_text_view);

        mQuestions.add(new Question(getString(R.string.question1)));
        mQuestions.add(new Question(getString(R.string.question2)));
        mQuestions.add(new Question(getString(R.string.question3)));
        mQuestions.add(new Question(getString(R.string.question4)));
        mQuestions.add(new Question(getString(R.string.question5)));

        mQuestionTextView.setText(mQuestions.get(mCurrentQuestionIndex).getQuestion());


        ArrayList<String> randomOrderQuestion = new ArrayList<String>();

        for(Question q : mQuestions){
            randomOrderQuestion.add(q.getAnswer());
            randomOrderQuestion.add(q.getNotAnswer1());
            randomOrderQuestion.add(q.getNotAnswer2());
            randomOrderQuestion.add(q.getNotAnswer3());
            randomOrderQuestion.add(q.getNotAnswer4());

            int index = 4;
            while(index != 0){
                int random = (int) Math.floor(Math.random() * (index));
                index--;
                String str = randomOrderQuestion.get(index);
                randomOrderQuestion.add(index, randomOrderQuestion.get(random));
                randomOrderQuestion.add(random, str);
            }

//            System.out.println(q.getQuestion());
//            System.out.println("[A]: " + randomOrderQuestion.get(0));
//            System.out.println("[B]: " + randomOrderQuestion.get(1));
//            System.out.println("[C]: " + randomOrderQuestion.get(2));
//            System.out.println("[D]: " + randomOrderQuestion.get(3));
//            System.out.println("[E]: " + randomOrderQuestion.get(4));
        }

        mAButton.setOnClickListener(v -> {
            //Handle the A button click
            String s = randomOrderQuestion.get(0);
            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals(s)){
                answeredCorrect++;
            }
        });

        mBButton.setOnClickListener(v -> {
            //Handle the B button click
            String s = randomOrderQuestion.get(1);
            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals(s)){
                answeredCorrect++;
            }
        });

        mCButton.setOnClickListener(v -> {
            //Handle the C button click
            String s = randomOrderQuestion.get(2);
            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals(s)){
                answeredCorrect++;
            }

        });

        mDButton.setOnClickListener(v -> {
            //Handle the D button click
            String s = randomOrderQuestion.get(3);
            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals(s)){
                answeredCorrect++;
            }
        });

        mEButton.setOnClickListener(v -> {
            //Handle the E button click
            String s = randomOrderQuestion.get(4);
            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals(s)){
                answeredCorrect++;
            }
        });

        mPrevButton.setOnClickListener(v -> {
            //Handle the Prev button click
            mCurrentQuestionIndex--;
            if(mCurrentQuestionIndex >= mQuestions.size()){
                mCurrentQuestionIndex = 0;
            }
            mQuestionTextView.setText(mQuestions.get(mCurrentQuestionIndex).getQuestion());
        });

        mNextButton.setOnClickListener(v -> {
            //Handle the Next button click
            mCurrentQuestionIndex++;
            if(mCurrentQuestionIndex >= mQuestions.size()){
                mCurrentQuestionIndex = 0;
            }
            mQuestionTextView.setText(mQuestions.get(mCurrentQuestionIndex).getQuestion());
        });

        mSubmitButton.setOnClickListener(v -> {
            //Handle the Next button click

            mQuestionTextView.setText(mQuestions.get(mCurrentQuestionIndex).getQuestion());
        });
    }
}

