package com.me.battle_school;

import com.badlogic.gdx.scenes.scene2d.InputEvent;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.scenes.scene2d.ui.TextButton;
import com.badlogic.gdx.scenes.scene2d.utils.ClickListener;

public class BagScreen extends AbstractScreen{

	public BagScreen(BattleSchool game) {
		super(game);
		// TODO Auto-generated constructor stub
	}
	
	@Override
	public void show() {
		super.show();

		// retrieve the default table actor
		Table table = super.getTable();
		table.add("BagScreen").spaceBottom(50);
		table.row();

		// register the button "start game"
		TextButton startGameButton = new TextButton("Back", getSkin());
		startGameButton.addListener(new ClickListener() {
			public void clicked(InputEvent event, float x, float y) {
				super.clicked(event, x, y); 
				game.setScreen(new WalkAroundScreen(game));
			}
		});
		table.add(startGameButton).size(300, 60).uniform().spaceBottom(10);
		table.row();
	}

}
