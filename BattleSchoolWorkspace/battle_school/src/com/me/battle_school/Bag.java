package com.me.battle_school;

import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;
import com.me.battle_school.Player.State;

public class Bag {
	public static final float SPEED = 0.1f; //unit per second
	public static final float HEIGHT = 1f; //1 unit tall
	public static final float WIDTH = 1f; //1 unit fat
	
	Vector2 position;
	Rectangle bounds = new Rectangle(); 
	Pets[] own = new Pets[15];
	int tracker;
	
	public Bag(Vector2 position){
		this.position = position; 
		this.bounds.height = HEIGHT; 
		this.bounds.width = WIDTH;
		tracker=0;
	}
	
	public Rectangle getBounds(){
		return bounds; 
	}
	
	public Vector2 getPosition(){
		return position; 
	}

	public void update(float delta) {
		 
	}
	public void addTo(Pets pet){
		own[tracker]=pet;
		tracker++;
	}
	
}
