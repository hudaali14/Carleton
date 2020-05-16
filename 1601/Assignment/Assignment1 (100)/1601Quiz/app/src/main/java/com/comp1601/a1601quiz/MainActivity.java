package com.comp1601.a1601quiz;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;
import java.util.ArrayList;

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
    private TextView mAnswer1TextView;
    private TextView mAnswer2TextView;
    private TextView mAnswer3TextView;
    private TextView mAnswer4TextView;
    private TextView mAnswer5TextView;
    private TextView mSubmitTextView;
    private int mCurrentQuestionIndex = 0;
    private ArrayList<Question> mQuestions;
    private int[] answers = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    private int[] options = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};



    // Displays formatted question and answers
    protected void displayQuestionAnswer(Question q, int[] options){
        ArrayList<String> randomOrderQuestion = q.getList();

        String answer1= "[A] " + randomOrderQuestion.get(0);
        String answer2= "[B] " + randomOrderQuestion.get(1);
        String answer3= "[C] " + randomOrderQuestion.get(2);
        String answer4= "[D] " + randomOrderQuestion.get(3);
        String answer5= "[E] " + randomOrderQuestion.get(4);
        String question= mCurrentQuestionIndex+1 + ". " + mQuestions.get(mCurrentQuestionIndex).getQuestion();

        // Sets question and answers text
        mQuestionTextView.setText(question);
        mAnswer1TextView.setText(answer1);
        mAnswer2TextView.setText(answer2);
        mAnswer3TextView.setText(answer3);
        mAnswer4TextView.setText(answer4);
        mAnswer5TextView.setText(answer5);

        // If answer had already been chosen before color option
        if(options[mCurrentQuestionIndex] == 1){
            mAButton.setBackgroundColor(Color.YELLOW);
        }else if(options[mCurrentQuestionIndex]==2){
            mBButton.setBackgroundColor(Color.YELLOW);
        }else if(options[mCurrentQuestionIndex]==3){
            mCButton.setBackgroundColor(Color.YELLOW);
        }else if(options[mCurrentQuestionIndex]==4){
            mDButton.setBackgroundColor(Color.YELLOW);
        }else if(options[mCurrentQuestionIndex]==5){
            mEButton.setBackgroundColor(Color.YELLOW);
        }else{
            // First time answering question set all options to blank
            resetColors();
        }
    }

    // Sets all buttons to default
    public void resetColors(){
        mAButton.setBackgroundResource(android.R.drawable.btn_default);
        mBButton.setBackgroundResource(android.R.drawable.btn_default);
        mCButton.setBackgroundResource(android.R.drawable.btn_default);
        mDButton.setBackgroundResource(android.R.drawable.btn_default);
        mEButton.setBackgroundResource(android.R.drawable.btn_default);
        mPrevButton.setBackgroundResource(android.R.drawable.btn_default);
        mNextButton.setBackgroundResource(android.R.drawable.btn_default);
        mSubmitButton.setBackgroundResource(android.R.drawable.btn_default);
    }


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
        mSubmitButton = findViewById(R.id.submit_button);
        mQuestionTextView = findViewById(R.id.question_text_view);
        mAnswer1TextView = findViewById(R.id.answer1_text_view);
        mAnswer2TextView = findViewById(R.id.answer2_text_view);
        mAnswer3TextView = findViewById(R.id.answer3_text_view);
        mAnswer4TextView = findViewById(R.id.answer4_text_view);
        mAnswer5TextView = findViewById(R.id.answer5_text_view);
        mSubmitTextView = findViewById(R.id.submit_text_view);

        resetColors();

        mQuestions = new ArrayList<>();

        mQuestions.add(new Question(getString(R.string.question1)));
        mQuestions.add(new Question(getString(R.string.question2)));
        mQuestions.add(new Question(getString(R.string.question3)));
        mQuestions.add(new Question(getString(R.string.question4)));
        mQuestions.add(new Question(getString(R.string.question5)));
        mQuestions.add(new Question(getString(R.string.question6)));
        mQuestions.add(new Question(getString(R.string.question7)));
        mQuestions.add(new Question(getString(R.string.question8)));
        mQuestions.add(new Question(getString(R.string.question9)));
        mQuestions.add(new Question(getString(R.string.question10)));

        // For each question object initialize answers in random order
        for(Question q : mQuestions){
            // Adds all answers to list
            ArrayList<String> randomOrderQuestion = q.getList();
            randomOrderQuestion.add(q.getAnswer());
            randomOrderQuestion.add(q.getNotAnswer1());
            randomOrderQuestion.add(q.getNotAnswer2());
            randomOrderQuestion.add(q.getNotAnswer3());
            randomOrderQuestion.add(q.getNotAnswer4());

            // Sets answers in random order in array
            int index = 5;
            while(index != 0){
                int random = (int) Math.floor(Math.random() * (index));
                index--;
                String str = randomOrderQuestion.get(index);
                randomOrderQuestion.set(index, randomOrderQuestion.get(random));
                randomOrderQuestion.set(random, str);
            }
            q.setList(randomOrderQuestion);
        }

        displayQuestionAnswer(mQuestions.get(mCurrentQuestionIndex), options);

        // For each button
        mAButton.setOnClickListener(v -> {
            // Handle the A button click
            resetColors();
            mAButton.setBackgroundColor(Color.YELLOW);
            // Sets options to 1 to represent A was chosen
            options[mCurrentQuestionIndex] = 1;
            // Gets list to find what option is in A's spot
            ArrayList<String> answersA = mQuestions.get(mCurrentQuestionIndex).getList();
            // If answer is right sets answers array to be 1, else 0
            String s = answersA.get(0);
            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals(s)){
                answers[mCurrentQuestionIndex] = 1;
            }else{
                answers[mCurrentQuestionIndex] = 0;
            }
        });

        mBButton.setOnClickListener(v -> {
            // Handle the B button click
            resetColors();
            mBButton.setBackgroundColor(Color.YELLOW);
            options[mCurrentQuestionIndex] = 2;
            ArrayList<String> answersB = mQuestions.get(mCurrentQuestionIndex).getList();
            String s = answersB.get(1);
            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals(s)){
                answers[mCurrentQuestionIndex] = 1;
            }else{
                answers[mCurrentQuestionIndex] = 0;
            }
        });

        mCButton.setOnClickListener(v -> {
            // Handle the C button click
            resetColors();
            mCButton.setBackgroundColor(Color.YELLOW);
            options[mCurrentQuestionIndex] = 3;
            ArrayList<String> answersC = mQuestions.get(mCurrentQuestionIndex).getList();
            String s = answersC.get(2);
            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals(s)){
                answers[mCurrentQuestionIndex] = 1;
            }else{
                answers[mCurrentQuestionIndex] = 0;
            }

        });

        mDButton.setOnClickListener(v -> {
            // Handle the D button click
            resetColors();
            mDButton.setBackgroundColor(Color.YELLOW);
            options[mCurrentQuestionIndex] = 4;
            ArrayList<String> answersD = mQuestions.get(mCurrentQuestionIndex).getList();
            String s = answersD.get(3);
            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals(s)){
                answers[mCurrentQuestionIndex] = 1;
            }else{
                answers[mCurrentQuestionIndex] = 0;
            }
        });

        mEButton.setOnClickListener(v -> {
            // Handle the E button click
            resetColors();
            mEButton.setBackgroundColor(Color.YELLOW);
            options[mCurrentQuestionIndex] = 5;
            ArrayList<String> answersE = mQuestions.get(mCurrentQuestionIndex).getList();
            String s = answersE.get(4);
            if(mQuestions.get(mCurrentQuestionIndex).getAnswer().equals(s)){
                answers[mCurrentQuestionIndex] = 1;
            }else{
                answers[mCurrentQuestionIndex] = 0;
            }
        });

        mPrevButton.setOnClickListener(v -> {
            // Handle the Prev button click
            resetColors();
            mCurrentQuestionIndex--;
            // Doesn't allow user to go past question 1
            if(mCurrentQuestionIndex == -1){
                mCurrentQuestionIndex = 0;
            }
            displayQuestionAnswer(mQuestions.get(mCurrentQuestionIndex), options);
        });

        mNextButton.setOnClickListener(v -> {
            // Handle the Next button click
            resetColors();
            mCurrentQuestionIndex++;
            //If user reaches the end go back to the beginning
            if(mCurrentQuestionIndex >= mQuestions.size()){
                mCurrentQuestionIndex = 0;

            }
            // After user finishes a quiz clear submit
            if(mCurrentQuestionIndex==1){
                mSubmitTextView.setText("");
            }
            displayQuestionAnswer(mQuestions.get(mCurrentQuestionIndex), options);
        });

        mSubmitButton.setOnClickListener(v -> {
            // Handle the Submit button click
            for(int i = 0; i < answers.length; i++){
                // Counts corrected answer
                if(answers[i] == 1){
                    answeredCorrect++;
                }
                // Reset answers and options
                answers[i] = 0;
                options[i] = 0;
            }

            // Displays grade
            String grade = answeredCorrect + "/10";
            mSubmitTextView.setText(grade);

            // Displays toast based on questions answered correctly
            if(answeredCorrect>=5){
                Toast.makeText(MainActivity.this,
                        R.string.correct_answer_toast,
                        Toast.LENGTH_SHORT).show();
            }else{
                Toast.makeText(MainActivity.this,
                        R.string.wrong_answer_toast,
                        Toast.LENGTH_SHORT).show();
            }
            //Resets index to 0 starts displays question and answer
            mCurrentQuestionIndex = 0;
            displayQuestionAnswer(mQuestions.get(mCurrentQuestionIndex), options);
        });
    }
}
