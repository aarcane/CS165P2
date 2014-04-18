package com.me.battle_school;

public class Ability {
	
	private String name;
	private int accuracy;
	private int manaCost;
	private int damage;
	private String type;
	private boolean AOE;
	private boolean heal;
	
	
	public Ability(String name, int damage, int manaCost, int accuracy, String type, boolean AOE, boolean heal)
	{
		this.name = name;
		this.accuracy = accuracy;
		this.manaCost = manaCost;
		this.damage = damage;
		this.type = type;	
		this.AOE = AOE;
		this.heal= heal;
	}
	
	
	public String getName(){
		return name;
	}
	
	public int getAccuracy(){
		return accuracy;
	}
	
	public int getManaCost(){
		return manaCost;
	}
	
	public int getDamage(){
		return damage;
	}
	
	public String getType(){
		return type;		
	}
	
	public boolean isAOE(){
		return AOE;
	}
	public boolean isHeal(){
		return heal;
	}
}
