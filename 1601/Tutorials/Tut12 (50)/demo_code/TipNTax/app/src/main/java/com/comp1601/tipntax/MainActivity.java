package com.comp1601.tipntax;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    private  final String TAG = this.getClass().getSimpleName() + " @" + System.identityHashCode(this);

    private Button mCalculateButton;
    private EditText mAmountView;
    private TipNTaxCalculator calculator;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mCalculateButton = (Button) findViewById(R.id.calculate_button);
        mAmountView = (EditText) findViewById(R.id.amount_edit_text);
        calculator = new TipNTaxCalculator();


        mCalculateButton.setOnClickListener((View v) -> {
            Log.i(TAG, "Calculate Button Clicked");
            String amountStr = mAmountView.getText().toString();
//            double amount = Double.parseDouble(amountSt r);
//            Log.i(TAG, "Amount = " + amount);
//            double total = calculator.calculate(amount);
//            Log.i(TAG, "Total = " + total);
//            mAmountView.setText("" + total);

            Intent intent = new Intent(MainActivity.this, TipCalcActivity.class);
            startActivity(intent);
        });
    }
}
