package com.me.battle_school;

import com.badlogic.gdx.Application.ApplicationType;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input.Keys;
import com.badlogic.gdx.InputProcessor;
import com.badlogic.gdx.graphics.GL10;
import com.badlogic.gdx.scenes.scene2d.InputEvent;
import com.badlogic.gdx.scenes.scene2d.ui.Button;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.scenes.scene2d.ui.TextButton;
import com.badlogic.gdx.scenes.scene2d.utils.ClickListener;
import com.me.controller.WorldController;

public class BagScreen extends AbstractScreen implements InputProcessor{
	
	private Database data;
	private WalkAroundScreen wScreen;
	
	public BagScreen(BattleSchool game, Database data, WalkAroundScreen wScreen) {
		super(game);
		this.data=data;
		this.wScreen=wScreen;
		// TODO Auto-generated constructor stub
	}

	private BagWorld world;
	private BagRenderer renderer; 
	private int width, height;
		
	//**Screen Methods**//
	@Override
	public void show() {
		
		world = new BagWorld(); 
		renderer = new BagRenderer(world, data, false);
		Gdx.input.setInputProcessor(this);
	}

	
	@Override
	public void render(float delta){
		Gdx.gl.glClearColor(1, 1, 1, 1);
		Gdx.gl.glClear(GL10.GL_COLOR_BUFFER_BIT);
		if(!renderer.getQuit()){
			renderer.render();
		}
		else{
			game.setScreen(wScreen);
		}
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
