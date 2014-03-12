package com.me.battle_school;


public class Pet {
	
	private String name;
	private String type;
	private int hitPoints;
	private int manaPoints;
	private int attack;
	private int defense;
	private int speed;
	private boolean isFriendly = true;
	private Ability[] abilities;
	private String imgName;
	
	
	public Pet(String name, String type, int hitPoints, int manaPoints, int attack, int defense,
			int speed, boolean isFriendly, Ability[] abilities, String imgName)
	{
		this.name = name;
		this.type = type;
		this.hitPoints = hitPoints;
		this.manaPoints = manaPoints;
		this.attack = attack;
		this.defense = defense;
		this.speed = speed;
		this.isFriendly = isFriendly;
		this.abilities = abilities;
		this.imgName = imgName;
	}

	public String getName(){
		return name;
	}
	
	public String getType(){
		return type;
	}
	
	public int getHitPoints(){
		return hitPoints;
	}
	
	public void setHitpoints(int hp){
		hitPoints = hp;
	}
	
	public int getManaPoints(){
		return manaPoints;
	}
	
	public void addManaPoints(int points){
		manaPoints  = manaPoints + points; 
	}
	public void setManaPoints(int mana){
		manaPoints = mana;
	}
	
	public int getAttack(){
		return attack;
	}
	
	public int getDefense(){
		return defense;
	}
	
	public int getSpeed(){
		return speed;
	}
	
	public boolean isFriendly(){
		return isFriendly;
	}
	
	public String getImgName(){
		return imgName;
	}
	
	public boolean isDead(){	
		if( hitPoints <= 0)
		{
			return true;
		}
		return false;
	}
	
	public void setAbilities(Ability a1, Ability a2, Ability a3, Ability a4){
		abilities[0]=a1;
		abilities[1]=a1;
		abilities[2]=a1;
		abilities[3]=a1;
	}
	
	public Ability[] getAbilities(){
		return abilities;
	}
	
	
	public void printPetStats(){
		System.out.format("%20s %10s %4d %4d %4d %4d %4d\n", name, type, hitPoints, manaPoints, attack, defense, speed);
		//I'm not sure what's the attack and defense for. 
	}
	
}
