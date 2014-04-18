package com.me.battle_school;

import com.badlogic.gdx.Application.ApplicationType;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input.Keys;
import com.badlogic.gdx.InputProcessor;
import com.badlogic.gdx.graphics.GL10;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.scenes.scene2d.ui.ImageButton;
import com.badlogic.gdx.scenes.scene2d.utils.TextureRegionDrawable;
import com.me.controller.WorldController;

public class WalkAroundScreen extends AbstractScreen implements InputProcessor{


	private World world; 
	private WorldRenderer renderer; 
	private WorldController controller; 
	
	private int width, height;
	private static int screenWidth, screenHeight; 

	
	public WalkAroundScreen(BattleSchool game) {
		super(game);
		// TODO Auto-generated constructor stub
	}
	
	//**Screen Methods**//
	@Override
	public void show() {
		super.show(); 
		world = new World(); 
		renderer = new WorldRenderer(world, false);
		controller = new WorldController(world);    
		Gdx.input.setInputProcessor(this);
	}

	@Override
	public void render(float delta){
		super.render(delta); 
		Gdx.gl.glClearColor(0.1f,  0.1f, 0.1f, 1); 
		Gdx.gl.glClear(GL10.GL_COLOR_BUFFER_BIT); 
		
		controller.update(delta); 
		renderer.render(); 
	}

	@Override
	public void resize(int width, int height) {
		super.resize(width, height); 		
		renderer.setSize(width, height);
		this.width = width; 
		this.height = height; 
		screenHeight = height; 
		screenWidth = width; 
	}

	@Override
	public void hide() {
		super.hide(); 
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

	//**Input Processor Methods**//
	@Override
	public boolean keyDown(int keycode) {
		if(keycode == Keys.LEFT)
			controller.leftPressed(); 
		if(keycode == Keys.RIGHT)
			controller.rightPressed(); 
		if(keycode == Keys.UP)
			controller.upPressed();
		if(keycode == Keys.DOWN)
			controller.downPressed(); 
		if(keycode == Keys.X)
			controller.interactPressed(); 
		return true;
	}

	@Override
	public boolean keyUp(int keycode) {
		if(keycode == Keys.LEFT)
			controller.leftReleased(); 
		if(keycode == Keys.RIGHT)
			controller.rightReleased(); 
		if(keycode == Keys.UP)
			controller.upReleased();
		if(keycode == Keys.DOWN)
			controller.downReleased(); 
		if(keycode == Keys.X)
			controller.interactReleased(); 
		return true;
	}

	@Override
	public boolean keyTyped(char character) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean touchDown(int screenX, int screenY, int pointer, int button) {
//		if (!Gdx.app.getType().equals(ApplicationType.Android))
//			return false;
		int x_width = width/3; 
		int y_width = height/3;
		if(screenX < x_width && screenY > y_width && screenY < 2*y_width){
			controller.leftPressed();
		}
		else if(screenX > 2*x_width && screenY > y_width && screenY < 2*y_width){
			controller.rightPressed(); 
		}
		else if(screenX > x_width && screenX < 2*x_width && screenY < y_width) {
			controller.upPressed(); 
		}
		else if(screenX > x_width && screenX < 2*x_width && screenY > 2*y_width) {
			controller.downPressed(); 
		}
		return true;
	}

	@Override
	public boolean touchUp(int screenX, int screenY, int pointer, int button) {
//		if (!Gdx.app.getType().equals(ApplicationType.Android))
//			return false;
		//BAG: if click at certain area 
		int x_width = width/3; 
		int y_width = height/3;
		if(screenX < x_width && screenY > y_width && screenY < 2*y_width){
			controller.leftReleased();
		}
		else if(screenX > 2*x_width && screenY > y_width && screenY < 2*y_width){
			controller.rightReleased(); 
		}
		else if(screenX > x_width && screenX < 2*x_width && screenY < y_width) {
			controller.upReleased(); 
		}
		else if(screenX > x_width && screenX < 2*x_width && screenY > 2*y_width) {
			controller.downReleased(); 
		}
		return true;	
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
	
	//for controller to check for screen boundary
	public static int getScreenWidth(){
		return screenWidth; 
	}
	public static int getScreenHeight(){
		return screenHeight; 
	}

}
