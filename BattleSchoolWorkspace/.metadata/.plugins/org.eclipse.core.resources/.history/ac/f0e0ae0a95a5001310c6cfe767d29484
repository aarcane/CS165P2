package com.me.controller;

import java.util.HashMap;
import java.util.Map;

import com.me.battle_school.Player;
import com.me.battle_school.Player.State;
import com.me.battle_school.World;

public class WorldController {

	enum Keys{ 
		LEFT, RIGHT, UP, DOWN, INTERACT
	}
	
	private World world; 
	private Player player; 
	
	static Map<Keys, Boolean> keys = new HashMap<WorldController.Keys, Boolean>(); 
	static {
		keys.put(Keys.LEFT, false); 
		keys.put(Keys.RIGHT, false); 
		keys.put(Keys.UP, false); 
		keys.put(Keys.DOWN, false); 
		keys.put(Keys.INTERACT, false); 
	};
	
	public WorldController(World world){
		this.world = world; 
		this.player = world.getPlayer(); 
	}

	//** Key presses and touches ***//
	
	public void leftPressed(){
		keys.get(keys.put(Keys.LEFT, true)); 
	}
	
	public void rightPressed(){
		keys.get(keys.put(Keys.RIGHT, true)); 
	}
	
	public void upPressed(){
		keys.get(keys.put(Keys.UP, true));
	}
	
	public void downPressed(){
		keys.get(keys.put(Keys.DOWN, true)); 
	}
	
	public void interactPressed(){
		keys.get(keys.put(Keys.INTERACT, true)); 
	}
	
	public void leftReleased(){
		keys.get(keys.put(Keys.LEFT, false)); 
	}
	
	public void rightReleased(){
		keys.get(keys.put(Keys.RIGHT, false));
	}

	public void upReleased(){
		keys.get(keys.put(Keys.UP, false));
	}

	public void downReleased(){
		keys.get(keys.put(Keys.DOWN, false));
	}

	public void interactReleased(){
		keys.get(keys.put(Keys.INTERACT, false));
	}

	//*the main update method**//
	public void update(float delta){
		processInput(); 
		player.update(delta);
	}
	
	//**change player's state and params based on input controls **//
	private void processInput(){
		if(keys.get(Keys.LEFT)); {
			//left is pressed
			player.setFacingLeft(true);
			player.setFacingUp(false);
			player.setState(State.WALKING_X); 
			player.getVelocity().x = -Player.SPEED;
			player.getVelocity().y = 0; 			
		}
		if(keys.get(Keys.RIGHT)){
			//right is pressed
			player.setFacingLeft(false); 
			player.setFacingUp(false);
			player.setState(State.WALKING_X); 
			player.getVelocity().x = Player.SPEED; 
			player.getVelocity().y = 0; 
		}
		//**NEED TO IMPLEMENT Y DIRECTION**//
		if(keys.get(Keys.UP)){
			//up is pressed
			player.setFacingUp(true); 
			player.setFacingLeft(false);
			player.setState(State.WALKING_Y);
			player.getVelocity().y = Player.SPEED; 
			player.getVelocity().x = 0;	
		}
		if(keys.get(Keys.DOWN)){
			player.setFacingUp(false); 
			player.setFacingLeft(false);
			player.setState(State.WALKING_Y); 
			player.getVelocity().y = -Player.SPEED; 
			player.getVelocity().x = 0;
		}
		
		//need to check if both or none are pressed then player is idle
		if((keys.get(Keys.LEFT) && keys.get(Keys.RIGHT)) ||
				(keys.get(Keys.UP) && keys.get(Keys.DOWN)) || 
				(keys.get(Keys.LEFT) && keys.get(Keys.UP)) ||
				(keys.get(Keys.LEFT) && keys.get(Keys.DOWN)) ||
				(keys.get(Keys.UP) && keys.get(Keys.RIGHT)) ||
				(keys.get(Keys.DOWN) && keys.get(Keys.RIGHT)) ||
				(!keys.get(Keys.LEFT) && !keys.get(Keys.RIGHT) &&!keys.get(Keys.UP) && !keys.get(Keys.DOWN))){
			player.setState(State.IDLE); 
			player.getVelocity().x = 0; 
			player.getVelocity().y = 0; 
		}
		
	}
}
