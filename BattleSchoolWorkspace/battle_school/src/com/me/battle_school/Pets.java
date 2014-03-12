package com.me.battle_school;

import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;
import com.me.battle_school.Player.State;

public class Pets {
	
	public static final float SPEED = 0.1f; //unit per second
	public static final float HEIGHT = 1f; //1 unit tall
	public static final float WIDTH = 1f; //1 unit fat
	
	Vector2 position;
	Rectangle bounds; 
	int petID;
	
	public Pets(Vector2 pos, int id){
		this.position = pos;
		this.petID = id;
		bounds=new Rectangle();
		this.bounds.height = HEIGHT; 
		this.bounds.width = WIDTH;
	}
	
	public Vector2 getPosition(){
		return position;
	}
	
	public Rectangle getBounds(){
		return bounds;
	}
}
