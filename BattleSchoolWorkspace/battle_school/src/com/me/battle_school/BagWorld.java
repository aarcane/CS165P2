package com.me.battle_school;

import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.math.Vector2;


public class BagWorld {
	private static final float CAMERA_WIDTH = 10f;
	private static final float CAMERA_HEIGHT = 7f;
	Pets avatar1, avatar2, avatar3, avatar4, avatar5, avatar6, avatar7, avatar8, avatar9, avatar10;
	Pets avatar11, avatar12, avatar13, avatar14, avatar15, avatar16, avatar17, avatar18, avatar19, avatar20;
	ActionButton back;
	OrthographicCamera camera;
	
	public Pets getPetAvatar1(){
		return avatar1;
	}
	public Pets getPetAvatar2(){
		return avatar2;
	}
	public Pets getPetAvatar3(){
		return avatar3;
	}
	public Pets getPetAvatar4(){
		return avatar4;
	}
	public Pets getPetAvatar5(){
		return avatar5;
	}
	public Pets getPetAvatar6(){
		return avatar6;
	}
	public Pets getPetAvatar7(){
		return avatar7;
	}
	public Pets getPetAvatar8(){
		return avatar8;
	}
	public Pets getPetAvatar9(){
		return avatar9;
	}
	public Pets getPetAvatar10(){
		return avatar10;
	}
	public Pets getPetAvatar11(){
		return avatar11;
	}
	public Pets getPetAvatar12(){
		return avatar12;
	}
	public Pets getPetAvatar13(){
		return avatar13;
	}
	public Pets getPetAvatar14(){
		return avatar14;
	}
	public Pets getPetAvatar15(){
		return avatar15;
	}
	public Pets getPetAvatar16(){
		return avatar16;
	}
	public Pets getPetAvatar17(){
		return avatar17;
	}
	public Pets getPetAvatar18(){
		return avatar18;
	}
	public Pets getPetAvatar19(){
		return avatar19;
	}
	public Pets getPetAvatar20(){
		return avatar20;
	}
	
	public ActionButton getBack(){
		return back;
	}

	public OrthographicCamera getCamera(){
		return camera;
	}
	
	public BagWorld(){
		createDemoWorld();
	}
	
	private void createDemoWorld() {
		
		//fire pets
		avatar1 = new Pets(new Vector2(30,250),0);
		avatar2 = new Pets(new Vector2(30,180),1);
		avatar3 = new Pets(new Vector2(30,110),2);
		avatar4 = new Pets(new Vector2(30,40),3);

		//fire pets
		avatar5 = new Pets(new Vector2(110,250),4);
		avatar6 = new Pets(new Vector2(110,180),5);
		avatar7 = new Pets(new Vector2(110,110),6);
		avatar8 = new Pets(new Vector2(110,40),7);
				
		//fire pets
		avatar9 = new Pets(new Vector2(190,250),8);
		avatar10 = new Pets(new Vector2(190,180),9);
		avatar11 = new Pets(new Vector2(190,110),10);
		avatar12 = new Pets(new Vector2(190,40),11);
				
		//fire pets
		avatar13 = new Pets(new Vector2(270,250),12);
		avatar14 = new Pets(new Vector2(270,180),13);
		avatar15 = new Pets(new Vector2(270,110),14);
		avatar16 = new Pets(new Vector2(270,40),15);
				
		//fire pets
		avatar17 = new Pets(new Vector2(350,250),16);
		avatar18 = new Pets(new Vector2(350,180),17);
		avatar19 = new Pets(new Vector2(350,110),18);
		avatar20 = new Pets(new Vector2(350,40),19);
				
		//button
		back= new ActionButton(new Vector2(430,0),6);
		
		camera = new OrthographicCamera(CAMERA_WIDTH, CAMERA_HEIGHT);
		camera.setToOrtho(false,CAMERA_WIDTH / 2f, CAMERA_HEIGHT / 2f);
		camera.update();
		
	}
}
