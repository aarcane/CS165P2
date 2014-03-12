package com.me.battle_school;

import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.math.Vector2;


public class BattleWorld {
	private static final float CAMERA_WIDTH = 10f;
	private static final float CAMERA_HEIGHT = 7f;
	Pets ally1;
	Pets ally2;
	Pets ally3;
	Pets enemy1;
	Pets enemy2;
	Pets enemy3;
	ActionButton attack;
	ActionButton pass;
	ActionButton forfeit;
	ActionButton attack1;
	ActionButton attack2;
	ActionButton attack3;
	ActionButton attack4;
	ActionButton back;
	ActionButton yes;
	ActionButton no;
	ActionButton message;
	OrthographicCamera camera;
	
	public ActionButton getMessage(){
		return message;
	}
	
	public Pets getPetAlly1(){
		return ally1;
	}
	public Pets getPetAlly2(){
		return ally2;
	}
	public Pets getPetAlly3(){
		return ally3;
	}
	public Pets getPetEnemy1(){
		return enemy1;
	}
	public Pets getPetEnemy2(){
		return enemy2;
	}
	public Pets getPetEnemy3(){
		return enemy3;
	}
	public ActionButton getAttack1(){
		return attack1;
	}
	public ActionButton getAttack2(){
		return attack2;
	}
	public ActionButton getAttack3(){
		return attack3;
	}
	public ActionButton getAttack4(){
		return attack4;
	}
	public ActionButton getBack(){
		return back;
	}
	public ActionButton getAttackCommand(){
		return attack;
	}
	public ActionButton getPassCommand(){
		return pass;
	}
	public ActionButton getForfeitCommand(){
		return forfeit;
	}
	public ActionButton getYes(){
		return yes;
	}
	public ActionButton getNo(){
		return no;
	}
	public OrthographicCamera getCamera(){
		return camera;
	}
	
	public BattleWorld(){
		createDemoWorld();
	}
	
	private void createDemoWorld() {
		
		ally1 = new Pets(new Vector2(150,260),1);
		ally2 = new Pets(new Vector2(150,200),1);
		ally3 = new Pets(new Vector2(150,140),1);
		enemy1 = new Pets(new Vector2(270, 260),1);
		enemy2 = new Pets(new Vector2(270,200),1);
		enemy3 = new Pets(new Vector2(270,140),1);
		
		//menu
		pass= new ActionButton(new Vector2(0,0),0);
		attack= new ActionButton(new Vector2(160,0),0);
		forfeit= new ActionButton(new Vector2(320,0),0);
		
		//attacks
		attack1= new ActionButton(new Vector2(0,85),1);
		attack2= new ActionButton(new Vector2(240,85),1);
		attack3= new ActionButton(new Vector2(0,45),1);
		attack4= new ActionButton(new Vector2(240,45),1);
		back= new ActionButton(new Vector2(0,0),2);
		
		//yes no
		yes= new ActionButton(new Vector2(0,0),4);
		no= new ActionButton(new Vector2(240,0),4);
		
		//messages
		message= new ActionButton(new Vector2(0,0),5);
		
		camera = new OrthographicCamera(CAMERA_WIDTH, CAMERA_HEIGHT);
		camera.setToOrtho(false,CAMERA_WIDTH / 2f, CAMERA_HEIGHT / 2f);
		camera.update();
		
	}
}
