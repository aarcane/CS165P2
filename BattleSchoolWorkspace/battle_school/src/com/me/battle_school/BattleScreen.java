package com.me.battle_school;

import java.util.Random;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.InputProcessor;
import com.badlogic.gdx.graphics.GL10;

public class BattleScreen extends AbstractScreen implements InputProcessor{
	
	private Database data;
	
	public BattleScreen(BattleSchool game, Database data) {
		super(game);
		this.data = data;
		// TODO Auto-generated constructor stub
	}

	private BattleWorld world;
	private BattleRenderer renderer;
	private Pet pet1;
	private Pet pet2;
	private Pet pet3;
	
	private int width, height;
	
	//private WorldController controller; 
		
	//**Screen Methods**//
	@Override
	public void show() {
		
		world = new BattleWorld(); 
		renderer = new BattleRenderer(world, false);
		Gdx.input.setInputProcessor(this);
		
		Pet[] temp = new Pet[20];
		int x=0;
		//gather all pets you own
		for (int i=0; i<data.getPets().length;i++){
			Pet tempPet = data.getPets()[i];
			if(tempPet.isFriendly()){
				temp[x]=tempPet;
				x++;
			}
		}
		
		Random rand = new Random();
		pet1 = temp[rand.nextInt(x)];
		pet2 = temp[rand.nextInt(x)];
		pet3 = temp[rand.nextInt(x)];
		
	}

	
	@Override
	public void render(float delta){
		//System.out.println("Entered render");
		Gdx.gl.glClearColor(1, 1, 1, 1);
		Gdx.gl.glClear(GL10.GL_COLOR_BUFFER_BIT);
		if(!renderer.exited()){
			renderer.render();
		}
		else{
			game.setScreen(new WalkAroundScreen(game));
		}
		//System.out.println("Rendered!!!");
		//renderer.render();
	}

	@Override
	public void resize(int width, int height) {
		//renderer.setSize(width, height);
		this.width = width; 
		this.height = height; 
	}

	@Override
	public void hide() {
		Gdx.input.setInputProcessor(null); 
	}

	@Override
	public void pause() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void resume() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void dispose() {
		Gdx.input.setInputProcessor(null); 
	}


	@Override
	public boolean keyDown(int keycode) {
		return false;
		/*if(keycode == Keys.LEFT)
			controller.leftPressed(); 
		if(keycode == Keys.RIGHT)
			controller.rightPressed(); 
		if(keycode == Keys.UP)
			controller.upPressed();
		if(keycode == Keys.DOWN)
			controller.downPressed(); 
		if(keycode == Keys.X)
			controller.interactPressed(); 
		return true;*/
	}


	@Override
	public boolean keyUp(int keycode) {
		// TODO Auto-generated method stub
		return false;
	}


	@Override
	public boolean keyTyped(char character) {
		// TODO Auto-generated method stub
		return false;
	}


	@Override
	public boolean touchDown(int screenX, int screenY, int pointer, int button) {
		// TODO Auto-generated method stub
		return false;
	}


	@Override
	public boolean touchUp(int screenX, int screenY, int pointer, int button) {
		// TODO Auto-generated method stub
		return false;
	}


	@Override
	public boolean touchDragged(int screenX, int screenY, int pointer) {
		// TODO Auto-generated method stub
		return false;
	}


	@Override
	public boolean mouseMoved(int screenX, int screenY) {
		// TODO Auto-generated method stub
		return false;
	}


	@Override
	public boolean scrolled(int amount) {
		// TODO Auto-generated method stub
		return false;
	}
}
