package com.me.battle_school;

import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;

public class ActionButton {

	public static final float SPEED = 0.1f; //unit per second
	//0 for action(pass/attack/forfeit)
	//1 for attack(attack 1-4)
	//2 for back
	//3 for u sure?
	//4 for yes/no
	//5 messages
	//6 and all else for side back button

	int type;
	Vector2 position;
	Rectangle bounds;
	float stateTime = 0;
	
	
	public ActionButton(Vector2 position, int type){
		this.position = position;
		this.type=type;
		bounds=new Rectangle();
		bounds.setPosition(position);

		if(type==0){
			this.bounds.height = 125; 
			this.bounds.width = 160;
		}
		else if(type==1){
			this.bounds.height = 40; 
			this.bounds.width = 240;
		}
		else if(type==2){
			this.bounds.height = 45; 
			this.bounds.width = 480;
		}
		else if(type==3){
			this.bounds.height = 80; 
			this.bounds.width = 480;
		}
		else if (type==4){
			this.bounds.height = 45; 
			this.bounds.width = 240;
		}
		else if (type==5) {
			this.bounds.height = 125; 
			this.bounds.width = 480;
		}
		else if (type==6) {
			this.bounds.height = 320;
			this.bounds.width = 50;
		}
	}
	
	public Rectangle getBounds(){
		return bounds;
	}
	
	public Vector2 getPosition(){
		return position; 
	}
}
