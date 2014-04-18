package com.me.battle_school;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Animation;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.graphics.glutils.ShapeRenderer;
import com.badlogic.gdx.graphics.glutils.ShapeRenderer.ShapeType;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;
import com.me.battle_school.Player.State;

public class WorldRenderer {
	
	public enum WalkDirection {
		UP, DOWN, RIGHT, LEFT
	}

	private static final float CAMERA_WIDTH = 10f;
	private static final float CAMERA_HEIGHT = 7f;

	private World world;
	//private OrthographicCamera cam;

	/* for debug rendering */
	ShapeRenderer debugRenderer = new ShapeRenderer();

	/** Textures **/
	private Texture playerTexture; // player walking texture
	private Texture blockTexture;
	private Texture bagTexture;
	Animation walkingUp;
	Animation walkingDown;
	Animation walkingRight;
	Animation walkingLeft;
	TextureRegion[] walkFramesUp;
	TextureRegion[] walkFramesDown;
	TextureRegion[] walkFramesLeft;
	TextureRegion[] walkFramesRight;
	TextureRegion stance;
	OrthographicCamera camera;
	Player player;
	Database data;
	boolean bagOpen;
	int row = 4;
	int col = 4;

	private SpriteBatch spriteBatch;
	private boolean debug = false;
	private int width;
	private int height;
	private float ppuX; // pixels per unit on the X axis
	private float ppuY; // pixels per unit on Y axis
	private float stateTime;
	
	private Bag bag;
	
	public void setSize(int w, int h) {
		this.width = w;
		this.height = h;
		ppuX = (float) width / CAMERA_WIDTH;
		ppuY = (float) height / CAMERA_HEIGHT;
		
	}

	public WorldRenderer(World world, Database data, boolean debug) {
		this.world = world;
		this.debug = debug;
		this.data = data;
		spriteBatch = new SpriteBatch();
		loadTextures();
		bagOpen=false;
	}

	public void loadTextures() {
		bagTexture = new Texture(Gdx.files.internal("images/bag.png"));
		playerTexture = new Texture(Gdx.files.internal("images/walk.png"));
		TextureRegion[][] temp = TextureRegion
				.split(playerTexture, playerTexture.getWidth() / col,
						playerTexture.getHeight() / row);
		walkFramesUp = new TextureRegion[row];
		walkFramesDown = new TextureRegion[row];
		walkFramesLeft = new TextureRegion[row];
		walkFramesRight = new TextureRegion[row];
		for (int i = 0; i < row; i++) {
			walkFramesUp[i] = temp[3][i];
			walkFramesDown[i] = temp[0][i];
			walkFramesLeft[i] = temp[1][i];
			walkFramesRight[i] = temp[2][i];
		}
		walkingDown = new Animation(.025f, walkFramesDown);
		walkingUp = new Animation(.025f, walkFramesUp);
		walkingRight = new Animation(.025f, walkFramesRight);
		walkingLeft = new Animation(.025f, walkFramesLeft);
		stance = walkingDown.getKeyFrame(0); 
		stateTime = 0f; 
		camera = world.getCamera();
		player = world.getPlayer();
		//block texture
		blockTexture = new Texture(Gdx.files.internal("images/road.png"));
		bag=world.getBag();
	}

	public void render() {
		
		spriteBatch.begin();
		drawBlocks();
		drawPlayer();
		if (debug){
		drawDebug();}
		camera.position.set(player.getPosition().x, player.getPosition().y, 0);
		//System.out.println("X:"+player.getPosition().x+" Y:"+player.getPosition().y);
		camera.update();
		//world.camera.update();
		Vector2 touchPos = new Vector2();
		
		if(Gdx.input.isTouched()){
			touchPos.set(Gdx.input.getX(), 320 -Gdx.input.getY());
		}
		else{
			touchPos.set(100000, 1000000);
		}
//		System.out.println(Gdx.input.getX()+" "+Gdx.input.getY());
//		System.out.println(touchPos.x+" "+touchPos.y);
		spriteBatch.draw(bagTexture, bag.getPosition().x, bag.getPosition().y);
		if((bag.getBounds().getWidth()*ppuX)>touchPos.x&&(bag.getBounds().getHeight()*ppuY)>(touchPos.y)){
			bagOpen=true;
		}
		
		spriteBatch.end();
//		cam.position.set(world.getPlayer().getPosition().x+Player.HEIGHT/2, world.getPlayer().getPosition().y+Player.WIDTH/2, 0);
	}

	private void drawPlayer() {
		if (player.getState().equals(State.WALKING_X)) {
			stance = player.isFacingLeft() ? walkingLeft.getKeyFrame(
					player.getStateTime()/4, true) : walkingRight.getKeyFrame(
					player.getStateTime()/4, true);
		}
		if (player.getState().equals(State.WALKING_Y)) {
			stance = player.isFacingUp() ? walkingUp.getKeyFrame(
					player.getStateTime()/4, true) : walkingDown.getKeyFrame(
					player.getStateTime()/4, true);
		}
		spriteBatch.draw(stance, player.getPosition().x * ppuX, player.getPosition().y * ppuY, Player.WIDTH * ppuX, Player.HEIGHT * ppuY);
		
		
	}
	
	private void drawBlocks() {
		for (Block block : world.getBlocks()) {
			spriteBatch.draw(blockTexture, block.getPosition().x * ppuX,
					block.getPosition().y * ppuY, Block.SIZE * ppuX, Block.SIZE
							* ppuY);
		}
	}

	public boolean isBagOpen(){
		return bagOpen;
	}
	
	public void drawDebug() {
		// render blocks
		debugRenderer.setProjectionMatrix(world.camera.combined);
		debugRenderer.begin(ShapeType.Line);
		for (Block block : world.getBlocks()) {
			Rectangle rect = block.getBounds();
			float x1 = block.getPosition().x + rect.x;
			float y1 = block.getPosition().y + rect.y;
			debugRenderer.setColor(new Color(1, 0, 0, 1));
			debugRenderer.rect(x1, y1, rect.width, rect.height);
		}

		// render player
		Player player = world.getPlayer();
		Rectangle rect = player.getBounds();
		float x1 = player.getPosition().x + rect.x;
		float y1 = player.getPosition().y + rect.y;
		debugRenderer.setColor(new Color(0, 1, 0, 1));
		debugRenderer.rect(x1, y1, rect.width, rect.height);
		debugRenderer.end();

	}
	


}
