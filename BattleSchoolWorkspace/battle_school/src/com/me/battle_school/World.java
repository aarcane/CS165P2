package com.me.battle_school;

import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.utils.Array;

public class World {

	Array<Block> blocks = new Array<Block>(); // block make up the world
	Player player;

	// getters
	public Array<Block> getBlocks() {
		return blocks;
	}

	public Player getPlayer() {
		return player;
	}

	public World() {
		createDemoWorld();
	}

	private void createDemoWorld() {

		player = new Player(new Vector2(7, 2));

//		for (int i = 0; i < 10; i++) {
//			blocks.add(new Block(new Vector2(i, 0)));
//			blocks.add(new Block(new Vector2(i, 6)));
//			if (i > 2) {
//				blocks.add(new Block(new Vector2(i, 1)));
//			}
//		}
//		for (int i = 2; i < 6; i++) {
//			blocks.add(new Block(new Vector2(9, i)));
//		}
//		for (int i = 3; i < 6; i++) {
//			blocks.add(new Block(new Vector2(6, i)));
//		}
		
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 7; j++){
				blocks.add(new Block(new Vector2(i,j))); 
			}
		}
	}

}
