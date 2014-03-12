package com.me.battle_school;

import java.util.Random;

public class Commands {

	public void attack(Pet attacker, Pet defender, Pet[] friendlyPets, Pet[] enemyPets)
	{
		Ability[] moveList = attacker.getAbilities();
		Random rng = new Random();
		
		int moveChoice = rng.nextInt(moveList.length);
		//System.out.println("moveChoice " + moveChoice);
		
		Ability moveToUse = moveList[moveChoice];
		
		while (moveToUse.getManaCost() > attacker.getManaPoints())
		{
			moveChoice = rng.nextInt(3);
			moveToUse = moveList[moveChoice];
		}
		
		if (moveToUse.getAccuracy() > rng.nextInt(100))
			{
				if(moveToUse.isAOE())
				{
					if(attacker.isFriendly())
					{
						for(int i = 0; i < enemyPets.length; i++)
						{
							if(!enemyPets[i].isDead())
							{
								System.out.println(attacker.getName() + " has attacked " + 
								enemyPets[i].getName() + " with " + moveToUse.getName() + 
								" for " + moveToUse.getDamage()+ " damage");
								
								enemyPets[i].setHitpoints(enemyPets[i].getHitPoints() - moveToUse.getDamage());
								
								//System.out.println(enemyPets.get(i).getName() + " has " + enemyPets.get(i).getHitPoints() + " health points remaining");
								
								if(enemyPets[i].isDead())
								{
									enemyPets[i].setHitpoints(0);
									System.out.println("\t" + enemyPets[i].getName() + " has died.");
								}
							}
						}
					}
					
					if(!attacker.isFriendly())
					{
						for(int i = 0; i < friendlyPets.length; i++)
						{
							if(!friendlyPets[i].isDead())
							{
								System.out.println(attacker.getName() + " has attacked " + 
								friendlyPets[i].getName() + " with " + moveToUse.getName() + 
								" for " + moveToUse.getDamage()+ " damage");
								
								friendlyPets[i].setHitpoints(friendlyPets[i].getHitPoints() - moveToUse.getDamage());
								
								//System.out.println(friendlyPets.get(i).getName() + " has " + friendlyPets.get(i).getHitPoints() + " health points remaining");
								
								if(friendlyPets[i].isDead())
								{
									friendlyPets[i].setHitpoints(0);
									System.out.println("\t" + friendlyPets[i].getName() + " has died.");
								}
							}
						}
					}
					
				}
				else
				{
					System.out.println(attacker.getName() + " has attacked " + defender.getName() + 
					" with " + moveToUse.getName() + " for " + moveToUse.getDamage()+ " damage");
					defender.setHitpoints(defender.getHitPoints() - moveToUse.getDamage());
					
					//System.out.println(defender.getName() + " has " + defender.getHitPoints() + " health points remaining");
				}
				
				//if hitpoints go below zero, that pet is now dead.
				if(defender.isDead())
				{
					defender.setHitpoints(0);
					System.out.println("\t" + defender.getName() + " has died.");
				}
			}
		else
		{
			System.out.println(attacker.getName() + " missed " + defender.getName() + " with " + moveToUse.getName());
		}
		
		attacker.setManaPoints(attacker.getManaPoints() - moveToUse.getManaCost());
	}
	
	public void pass(Pet attacker)
	{
		System.out.println(attacker.getName() + " has passed");
	}
}
