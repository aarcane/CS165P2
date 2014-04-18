package com.me.battle_school;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.Texture.TextureFilter;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.scenes.scene2d.Action;
import com.badlogic.gdx.scenes.scene2d.actions.Actions;
import com.badlogic.gdx.scenes.scene2d.ui.Image;

public class LibgdxScreen extends AbstractScreen{

	private Texture libTexture; 
	
	public LibgdxScreen(BattleSchool game) {
		super(game);
	}

	public void show() {
		super.show();
		libTexture = new Texture("images/libgdx.png");
		libTexture.setFilter(TextureFilter.Linear, TextureFilter.Linear); 
	}
	
	public void resize(int width, int height) {
        super.resize( width, height );
        stage.clear();
        // here we create the splash image actor and set its size
        Image libImage = new Image( new TextureRegion(libTexture));
        libImage.setWidth(width);
        libImage.setHeight(height);

        // this is needed for the fade-in effect to work correctly; we're just
        // making the image completely transparent
        libImage.getColor().a = 0f;

        // configure the fade-in/out effect on the splash image
       libImage.addAction( Actions.sequence( Actions.fadeIn( 0.75f ), Actions.delay( 1.75f ), Actions.fadeOut( 0.75f ),
            new Action() {
                @Override
                public boolean act(float delta)
                {
                    // the last action will move to the next screen
                    game.setScreen( new SplashScreen(game) );
                    return true;
                }
            } ) );

        // and finally we add the actors to the stage, on the correct order
        stage.addActor( libImage );
	}
}
