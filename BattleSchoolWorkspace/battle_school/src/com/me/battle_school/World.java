package com.me.battle_school;

import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.utils.Array;

public class World {
	
	private static final float CAMERA_WIDTH = 10f;
	private static final float CAMERA_HEIGHT = 7f;
	
	Array<Block> blocks = new Array<Block>(); // block make up the world
	Player player;
	Bag bag;
	OrthographicCamera camera;

	// getters
	public OrthographicCamera getCamera(){
		return camera;
	}
	
	public Array<Block> getBlocks() {
		return blocks;
	}

	public Player getPlayer() {
		return player;
	}

	public World() {
		createDemoWorld();
	}
	
	public Bag getBag(){
		return bag;
	}
	
	private void createDemoWorld() {

		player = new Player(new Vector2(3, 3));
		bag = new Bag(new Vector2(0, 0));
		camera = new OrthographicCamera(CAMERA_WIDTH, CAMERA_HEIGHT);
		camera.setToOrtho(false,CAMERA_WIDTH / 2f, CAMERA_HEIGHT / 2f);
		camera.update();
		System.out.println("Made camera");

		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 7; j++){
				blocks.add(new Block(new Vector2(i,j))); 
			}
		}
	}

}
