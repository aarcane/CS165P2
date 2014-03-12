package com.me.battle_school;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;

public class BagRenderer {
	private static final float CAMERA_WIDTH = 10f;
	private static final float CAMERA_HEIGHT = 7f;
	
	//pets pictures
	private Texture avatar1, avatar2, avatar3, avatar4, avatar5, avatar6, avatar7, avatar8, avatar9, avatar10;
	private Texture avatar11, avatar12, avatar13, avatar14, avatar15, avatar16, avatar17, avatar18, avatar19, avatar20;
	private Texture[] avatars;
	
	//health and mana bars
	private Texture health;
	private Texture mana;
	
	//prompts buttons
	private Texture back;
	//pets
	private Texture shark;
	
	//font is to right in the buttons.
	private BitmapFont font;
	
	private BagWorld world;
	ActionButton backAttack;
	
	private boolean debug;
	private int width;
	private int height;
	private SpriteBatch batch;
	private Database data;
	private Pet[] temp;
	OrthographicCamera camera;
	private boolean quit;
	
	
	public void setSize(int w, int h) {
		this.width = w;
		this.height = h;
	}
	
	public BagRenderer(BagWorld world, Database data, boolean debug) {
		this.world = world;
		this.debug = debug;
		batch=new SpriteBatch();
		this.data= new Database();
		this.data=data;
		quit=false;
		loadTextures();
	}
	
	public void loadTextures() {
		//load all the images of the pets
		avatar1 = new Texture(Gdx.files.internal("pets/bee.png"));
		avatar2 = new Texture(Gdx.files.internal("pets/bunny.png"));
		avatar3 = new Texture(Gdx.files.internal("pets/cat.png"));
		avatar4 = new Texture(Gdx.files.internal("pets/ghostFish.png"));
		avatar5 = new Texture(Gdx.files.internal("pets/gnome.png"));
		avatar6 = new Texture(Gdx.files.internal("pets/hellBat.png"));
		avatar7 = new Texture(Gdx.files.internal("pets/octopus.png"));
		avatar8 = new Texture(Gdx.files.internal("pets/owl.png"));
		avatar9 = new Texture(Gdx.files.internal("pets/pumpkin.png"));
		avatar10 = new Texture(Gdx.files.internal("pets/scareBear.png"));
		avatar11 = new Texture(Gdx.files.internal("pets/scarecrow.png"));
		avatar12 = new Texture(Gdx.files.internal("pets/seapanda.png"));
		avatar13 = new Texture(Gdx.files.internal("pets/shark.png"));
		avatar14 = new Texture(Gdx.files.internal("pets/snowman.png"));
		avatar15 = new Texture(Gdx.files.internal("pets/sword.png"));
		avatar16 = new Texture(Gdx.files.internal("pets/umbrellaLady.png"));
		avatar17 = new Texture(Gdx.files.internal("pets/voodoo.png"));
		avatar18 = new Texture(Gdx.files.internal("images/block.png"));
		avatar19 = new Texture(Gdx.files.internal("images/block.png"));
		avatar20 = new Texture(Gdx.files.internal("images/block.png"));
		
		avatars= new Texture[20];
		avatars[0]=avatar1;
		avatars[1]=avatar2;
		avatars[2]=avatar3;
		avatars[3]=avatar4;
		avatars[4]=avatar5;
		avatars[5]=avatar6;
		avatars[6]=avatar7;
		avatars[7]=avatar8;
		avatars[8]=avatar9;
		avatars[9]=avatar10;
		avatars[10]=avatar11;
		avatars[11]=avatar12;
		avatars[12]=avatar13;
		avatars[13]=avatar14;
		avatars[14]=avatar15;
		avatars[15]=avatar16;
		avatars[16]=avatar17;
		avatars[17]=avatar18;
		avatars[18]=avatar19;
		avatars[19]=avatar20;
		
		
		//load buttons
		back = new Texture(Gdx.files.internal("images/back.png"));
		
		//font minecraftia
		font = new BitmapFont(Gdx.files.internal("skin/font.fnt"),Gdx.files.internal("skin/font_0.png"), false);
		font.setColor(1.0f, 1.0f, 1.0f, 1.0f);
		font.setScale((float) 0.5);
		//pets
		temp = data.getPets();
		backAttack = world.getBack();
	}
		
	public void render(){
						
		batch.begin();
		
		drawPets();
		drawNames();
		drawBack();
		Vector2 touchPos = new Vector2();
		if(Gdx.input.isTouched()){
			touchPos.set(Gdx.input.getX(),Gdx.input.getY());
		}
		if(backAttack.getBounds().contains(touchPos)){
			quit = true;
		}
		
		batch.end();
	}
	
	private void drawPets(){
		int j=1;
		int k=1;
		for(int i=0; i<data.getPets().length;i++){
			if(j>5){
				k++;
				j=1;
			}
			System.out.println(data.getPets().length+ " "+ i);
			System.out.println(temp[0].getName());
			if(temp[i].isFriendly()){
				batch.draw(avatars[(i)], (30*j)+(50*(j-1)), 320 - (70*k));
			}
			j++;
		}
	}
	
	private void drawNames(){
		int j=1;
		int k=1;
		for(int i=0; i<data.getPets().length;i++){
			if(j>5){
				k++;
				j=1;
			}
			if(temp[i].isFriendly()){
				font.draw(batch, temp[i].getName(), (30*j)+(50*(j-1)), 320 - (70*k)-20);
			}
			j++;
		}
	}
	
	public boolean getQuit(){
		return quit;
	}
	
	private void drawBack(){
		batch.draw(back, 430, 0);
	}
	
	private void drawDebug(){
		System.out.println("debugging");
	}
	
	
}
