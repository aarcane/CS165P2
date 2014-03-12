package com.me.battle_school;

import com.badlogic.gdx.Game;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.FPSLogger;
import com.badlogic.gdx.graphics.Texture;

public class BattleSchool extends Game {

	public static final String LOG = "BattleSchool Log: ";
	public static final boolean DEV_MODE = false; 
	FPSLogger fpsLogger; 

	@Override
	public void create() {
		Texture.setEnforcePotImages(false);
		
		Gdx.app.log(BattleSchool.LOG, "creating game");
		fpsLogger = new FPSLogger(); 
//		setScreen(new WalkAroundScreen(this)); 
		setScreen(getKeyScreen()); 
	}
	
	public KeyScreen getKeyScreen() {
		return new KeyScreen(this); 
	}

}
