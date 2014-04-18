package com.me.battle_school;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.math.Vector2;

public class BattleRenderer {
	private static final float CAMERA_WIDTH = 10f;
	private static final float CAMERA_HEIGHT = 7f;
	
	//pets pictures
	private Texture allyTex1;
	private Texture allyTex2;
	private Texture allyTex3;
	private Texture enemyTex1;
	private Texture enemyTex2;
	private Texture enemyTex3;
	
	//health and mana bars
	private Texture health;
	private Texture mana;
	
	//prompts buttons
	private Texture pass;
	private Texture attack;
	private Texture forfeit;
	private Texture usure;
	private Texture yes;
	private Texture no;
	private Texture back;
	private Texture attackMove;
	private Texture textBox;
	private float delta;
	//pets
	private Texture shark;
	
	//font is to right in the buttons.
	private BitmapFont font;
	private BitmapFont fontGreen;
	private BitmapFont fontRed;
	
	private BattleWorld world;
	Pets ally1;
	Pets ally2;
	Pets ally3;
	Pets enemy1;
	Pets enemy2;
	Pets enemy3;
	ActionButton attack1;
	ActionButton attack2;
	ActionButton attack3;
	ActionButton attack4;
	ActionButton backAttack;
	ActionButton attackButton;
	ActionButton passButton;
	ActionButton forfeitButton;
	ActionButton text;
	ActionButton yesButton;
	ActionButton noButton;
	
	boolean menu;
	boolean attks;
	boolean sure;
	boolean txt;
	//false if passing, true if forfeiting
	boolean passFor;
	//false if pass, true if attack
	boolean patk;
	//quit battle
	boolean quit;
	boolean exit;
	//which attack
	int attackNO;
	
	private boolean debug;
	private int width;
	private int height;
	private SpriteBatch batch;
	OrthographicCamera camera;
	
	
	public void setSize(int w, int h) {
		this.width = w;
		this.height = h;
	}
	
	public BattleRenderer(BattleWorld world, boolean debug) {
		this.world = world;
		this.debug = debug;
		batch=new SpriteBatch();
		loadTextures();
		menu=true;
		attks=false;
		sure=false;
		txt=false;
		//false if passing, true if forfeiting
		passFor=false;
		//false if pass, true if attack
		patk=false;
		//quit battle
		quit=false;
		delta =0;
		exit=false;
	}
	
	public void loadTextures() {
		//load all the images of the pets
		allyTex1 = new Texture(Gdx.files.internal("images/block.png"));
		allyTex2 = new Texture(Gdx.files.internal("images/block.png"));
		allyTex3 = new Texture(Gdx.files.internal("images/block.png"));
		enemyTex1 = new Texture(Gdx.files.internal("images/block.png"));
		enemyTex2 = new Texture(Gdx.files.internal("images/block.png"));
		enemyTex3 = new Texture(Gdx.files.internal("images/block.png"));
		
		//load health and mana bars
		health = new Texture(Gdx.files.internal("images/health.png"));
		mana = new Texture(Gdx.files.internal("images/mana.png"));
		
		//load buttons
		pass = new Texture(Gdx.files.internal("images/pass.png"));
		attack = new Texture(Gdx.files.internal("images/attack.png"));
		forfeit = new Texture(Gdx.files.internal("images/forfeit.png"));
		usure = new Texture(Gdx.files.internal("images/uSure.png"));
		yes = new Texture(Gdx.files.internal("images/yes.png"));
		no = new Texture(Gdx.files.internal("images/no.png"));
		back = new Texture(Gdx.files.internal("images/back.png"));
		attackMove = new Texture(Gdx.files.internal("images/attackMove.png"));
		textBox = new Texture(Gdx.files.internal("images/textbox.png"));
		
		//font minecraftia
		font = new BitmapFont(Gdx.files.internal("skin/font.fnt"),Gdx.files.internal("skin/font_0.png"), false);
		fontGreen = new BitmapFont(Gdx.files.internal("skin/font.fnt"),Gdx.files.internal("skin/font_0.png"), false);
		fontRed = new BitmapFont(Gdx.files.internal("skin/font.fnt"),Gdx.files.internal("skin/font_0.png"), false);
		
		//pets
		shark=new Texture(Gdx.files.internal("pets/shark.png"));
		
		ally1=world.getPetAlly1();
		ally2=world.getPetAlly2();
		ally3=world.getPetAlly3();
		enemy1=world.getPetEnemy1();
		enemy2=world.getPetEnemy2();
		enemy3=world.getPetEnemy3();
		camera=world.getCamera();
			
		passButton=world.getPassCommand();
		attackButton=world.getAttackCommand();
		forfeitButton=world.getForfeitCommand();
		
		attack1=world.getAttack1();
		attack2=world.getAttack2();
		attack3=world.getAttack3();
		attack4=world.getAttack4();
		backAttack=world.getBack();
		
		yesButton=world.getYes();
		noButton=world.getNo();
		
		text=world.getMessage();
		
	}
		
	public void render(){
		Vector2 touchPos= new Vector2();
		//adds lag time between clicks
		if(Gdx.input.isTouched() && delta > 20.0f){
			touchPos.set(Gdx.input.getX(), 320-Gdx.input.getY());
		}
		else{
			touchPos.set(-100,-100);
		}
				
		batch.begin();
		//black font
		font.setColor(1.0f, 1.0f, 1.0f, 1.0f);
		font.setScale((float) 0.5);
		//green font
		fontGreen.setColor(0f, 1.0f, 0f, 1.0f);
		fontGreen.setScale((float) 0.5);
		//blue font
		fontRed.setColor(1.0f, 0f, 0f, 1.0f);
		fontRed.setScale((float) 0.5);
		
		drawPets();
		drawMana();
		drawHealth();
		if (menu){
			drawMenuButtons();
			//System.out.println(passButton.getBounds().contains(touchPos));
			if (passButton.getBounds().contains(touchPos)){
				menu=false;
				sure=true;
				passFor=false;
				delta=0;
			}
			else if(attackButton.getBounds().contains(touchPos)){
				menu=false;
				attks=true;
				delta=0;
			}
			else if(forfeitButton.getBounds().contains(touchPos)){
				menu=false;
				sure=true;
				passFor=true;
				delta=0;
			}
		}
		else if(sure){
			drawYesNo();
			if(yesButton.getBounds().contains(touchPos) && passFor==false){
				sure=false;
				txt=true;
				patk=false;
				delta=0;
			}
			else if(yesButton.getBounds().contains(touchPos) && passFor==true){
				sure=false;
				txt=true;
				quit=true;
				delta=0;
			}
			else if(noButton.getBounds().contains(touchPos)){
				sure=false;
				menu=true;
				delta=0;
			}
		}
		else if (attks){
			drawAttackChoices();
			drawAttacks();
			
			if(attack1.getBounds().contains(touchPos)){
				attks=false;
				txt=true;
				patk=true;
				attackNO=1;
				delta=0;
			}
			else if(attack2.getBounds().contains(touchPos)){
				attks=false;
				txt=true;
				patk=true;
				attackNO=2;
				delta=0;
			}
			else if(attack3.getBounds().contains(touchPos)){
				attks=false;
				txt=true;
				patk=true;
				attackNO=3;
				delta=0;
			}
			else if(attack4.getBounds().contains(touchPos)){
				attks=false;
				txt=true;
				patk=true;
				attackNO=4;
				delta=0;
			}
			else if(backAttack.getBounds().contains(touchPos)){
				attks=false;
				menu=true;
				delta=0;
			}
		}
		else if (txt){
			drawText();
			if(quit){
				if(text.getBounds().contains(touchPos)){
					exit=true;
				}
			}
			else if(patk==false){
				font.draw(batch, "XXXXXXXXX passed!", 50, 80);
				if(text.getBounds().contains(touchPos)){
					txt=false;
					menu=true;
					delta=0;
				}
			}
			else if(patk ==true){
				font.draw(batch, "XXXXXXXXXX used XXXXXXXXXXX on XXXXXXXXXX!", 50, 80);
				if(text.getBounds().contains(touchPos)){
					txt=false;
					menu=true;
					delta=0;
				}
			}
			
		}
		
		drawNames();
		delta++;
		if(debug){
			drawDebug();
		}
		batch.end();
	}
	
	private void drawPets(){
		batch.draw(shark,ally1.position.x,ally1.position.y);
		batch.draw(allyTex2,ally2.position.x,ally2.position.y);
		batch.draw(allyTex3,ally3.position.x,ally3.position.y);
		batch.draw(enemyTex1,enemy1.position.x,enemy1.position.y);
		batch.draw(enemyTex2,enemy2.position.x,enemy2.position.y);
		batch.draw(enemyTex3,enemy3.position.x,enemy3.position.y);
	
	}
	
	private void drawHealth(){
		fontRed.draw(batch, "100%", 20, 285);
		fontRed.draw(batch, "100%", 20, 225);
		fontRed.draw(batch, "100%", 20, 165);
		fontRed.draw(batch, "100%", 350, 285);
		fontRed.draw(batch, "100%", 350, 225);
		fontRed.draw(batch, "100%", 350, 165);
		
		/*batch.draw(health, 20, 280);
		batch.draw(health, 20, 220);
		batch.draw(health, 20, 160);
		batch.draw(health, 350, 280);
		batch.draw(health, 350, 220);
		batch.draw(health, 350, 160);*/
	}
	
	private void drawMana(){
		fontGreen.draw(batch, "100%", 70, 285);
		fontGreen.draw(batch, "100%", 70, 225);
		fontGreen.draw(batch, "100%", 70, 165);
		fontGreen.draw(batch, "100%", 400, 285);
		fontGreen.draw(batch, "100%", 400, 225);
		fontGreen.draw(batch, "100%", 400, 165);
		
		
		/*batch.draw(mana, 20, 265);
		batch.draw(mana, 20, 205);
		batch.draw(mana, 20, 145);
		batch.draw(mana, 350, 265);
		batch.draw(mana, 350, 205);
		batch.draw(mana, 350, 145);*/
	}
	
	private void drawMenuButtons(){
		batch.draw(pass, passButton.getPosition().x, passButton.getPosition().y);
		batch.draw(attack, attackButton.getPosition().x, attackButton.getPosition().y);
		batch.draw(forfeit, forfeitButton.getPosition().x, forfeitButton.getPosition().y);
	}
	
	private void drawYesNo(){
		batch.draw(usure, 0, 45);
		batch.draw(yes, yesButton.getPosition().x, yesButton.getPosition().y);
		batch.draw(no, noButton.getPosition().x, noButton.getPosition().y);
	}
		
	private void drawAttackChoices(){
		batch.draw(attackMove,attack1.getPosition().x,attack1.getPosition().y);
		batch.draw(attackMove,attack2.getPosition().x,attack2.getPosition().y);
		batch.draw(attackMove,attack3.getPosition().x,attack3.getPosition().y);
		batch.draw(attackMove,attack4.getPosition().x,attack4.getPosition().y);
		batch.draw(back, backAttack.getPosition().x,backAttack.getPosition().y);
	}
	
	
	private void drawNames(){
		font.draw(batch, "XXXXXXXXXXXXX", 20, 305);
		font.draw(batch, "XXXXXXXXXXXXX", 20, 245);
		font.draw(batch, "XXXXXXXXXXXXX", 20, 185);
		font.draw(batch, "XXXXXXXXXXXXX", 350, 305);
		font.draw(batch, "XXXXXXXXXXXXX", 350, 245);
		font.draw(batch, "XXXXXXXXXXXXX", 350, 185);
		
	}
	private void drawAttacks(){
		font.draw(batch, "ATTACK1", 30, 110);
		font.draw(batch, "ATTACK2", 270, 110);
		font.draw(batch, "ATTACK3", 30, 70);
		font.draw(batch, "ATTACK4", 270, 70);
	}
	
	private void drawText(){
		batch.draw(textBox, text.getPosition().x, text.getPosition().y);
	}
	
	private void drawDebug(){
		System.out.println("debugging");
	}
	
	public boolean exited(){
		return exit;
	}
}
