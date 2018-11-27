package com.demo.dynamicjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    private DynamicTest dynamicTest;
    static {
        System.loadLibrary("dynamic");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        dynamicTest = new DynamicTest();
         Log.d(TAG,"dynamicTest test =  " + dynamicTest.doTwo(1,2));

    }

}
