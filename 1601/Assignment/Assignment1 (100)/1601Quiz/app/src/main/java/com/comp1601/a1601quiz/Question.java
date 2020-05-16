package com.comp1601.a1601quiz;

import java.util.ArrayList;

public class Question {
    private String mQuestion;
    private String mAnswer;
    private ArrayList<String> mNotAnswer;
    private ArrayList<String> randomOrderQuestion = new ArrayList<String>();


    //Parses into question and answers
    public Question(String aQuestionAnswerString){
        //aQuestionAnswerString is expected to be of the form:
        //"Is Java an Object-Oriented Language?[Yes][No][Maybe][Probably][Not sure]"
        int indexStart = aQuestionAnswerString.indexOf("[");
        mQuestion = aQuestionAnswerString.substring(0, indexStart);
        int indexEnd = aQuestionAnswerString.indexOf("]");
        mAnswer = aQuestionAnswerString.substring(indexStart+1, indexEnd);

        // Parses not answer string and puts each answer into array
        String mNotAnswerString = aQuestionAnswerString.substring(indexEnd+2, aQuestionAnswerString.length());
        mNotAnswer = new ArrayList<String>();
        int counter = 0;
        while(counter<=mNotAnswerString.length()-1){
            String s = "";
            while(mNotAnswerString.charAt(counter)!=']'){
                s += Character.toString(mNotAnswerString.charAt(counter));
                counter++;
            }
            counter+=2;
            mNotAnswer.add(s);
        }
    }

    // Get lists of answers in random order
    public ArrayList getList(){
        return randomOrderQuestion;
    }

    // Sets list in random order
    public void setList(ArrayList list){
        randomOrderQuestion = list;
    }

    public String getQuestion(){ return mQuestion;}
    public String getAnswer() { return mAnswer;}
    public String getNotAnswer1(){ return mNotAnswer.get(0);}
    public String getNotAnswer2(){ return mNotAnswer.get(1);}
    public String getNotAnswer3(){ return mNotAnswer.get(2);}
    public String getNotAnswer4(){ return mNotAnswer.get(3);}
}
