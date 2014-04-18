package com.me.battle_school;

import android.os.Bundle;

import com.badlogic.gdx.backends.android.AndroidApplication;
import com.badlogic.gdx.backends.android.AndroidApplicationConfiguration;


public class BattleSchoolActivity extends AndroidApplication {
/**called when activity is firste created*/
	
	public void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState); 
		AndroidApplicationConfiguration config = new AndroidApplicationConfiguration(); 
		config.useAccelerometer = false; 
		config.useCompass = false; 
		config.useWakelock = true; 
		config.useGL20 = true; 
		initialize(new BattleSchool(), config); 
	}
}
