package com.me.battle_school;

import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;
import com.me.battle_school.Player.State;

public class Player {

	public enum State{
		IDLE, WALKING_X, WALKING_Y, INTERACT
	}
	
	public static final float SPEED = 0.1f; //unit per second
	public static final float HEIGHT = 1f; //1.5 unit tall
	public static final float WIDTH = 1f; //1 unit fat
	
	Vector2 position = new Vector2(); 
	Vector2 velocity = new Vector2(); 
	Rectangle bounds = new Rectangle(); 
	State state = State.IDLE; 
	boolean facingLeft = true; 
	boolean facingUp = false; 
	
	float stateTime = 0; 
	
	public Player(Vector2 position) {
		this.position = position; 
		this.bounds.height = HEIGHT; 
		this.bounds.width = WIDTH; 
	}
	
	public Rectangle getBounds(){
		return bounds; 
	}
	
	public Vector2 getPosition(){
		return position; 
	}

	public void update(float delta) {
		stateTime = stateTime + delta; 
		position.add(velocity).cpy().scl(delta); 
	}

	public Vector2 getVelocity(){
		return velocity; 
	}

	public void setFacingUp(boolean bool) {
		facingUp = bool; 
	}

	public void setFacingLeft(boolean bool) {
		facingLeft = bool; 
	}

	public void setState(State newState) {
		state = newState; 
	}

	public boolean isFacingLeft() {
		// TODO Auto-generated method stub
		return facingLeft;
	}

	public float getStateTime() {
		// TODO Auto-generated method stub
		return stateTime;
	}

	public Object getState() {
		// TODO Auto-generated method stub
		return state;
	}

	public boolean isFacingUp() {
		// TODO Auto-generated method stub
		return facingUp;
	}

}
