package com.me.battle_school;

import com.badlogic.gdx.scenes.scene2d.InputEvent;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.scenes.scene2d.ui.TextButton;
import com.badlogic.gdx.scenes.scene2d.utils.ClickListener;

public class MenuScreen extends AbstractScreen {
	public MenuScreen(BattleSchool game) {
		super(game);
	}

	@Override
	public void show() {
		super.show();

		// retrieve the default table actor
		Table table = super.getTable();
		table.add("Welcome to Battle University!").spaceBottom(50);
		table.row();

		// register the button "start game"
		TextButton startGameButton = new TextButton("Start game", getSkin());
		startGameButton.addListener(new ClickListener() {
//			@Override
//			public void touchUp(ActorEvent event, float x, float y,
//					int pointer, int button) {
//				super.touchUp(event, x, y, pointer, button);
//				game.setScreen(new WalkAroundScreen(game));
//			}
//
//			@Override
//			public boolean handle(Event event) {
//				// TODO Auto-generated method stub
//				return false;
//			}
			public void clicked(InputEvent event, float x, float y) {
				super.clicked(event, x, y); 
				game.setScreen(new WalkAroundScreen(game));
			}
		});
		table.add(startGameButton).size(300, 60).uniform().spaceBottom(10);
		table.row();
	}
}
