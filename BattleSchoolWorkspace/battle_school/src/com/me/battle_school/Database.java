package com.me.battle_school;

public class Database {
	
	
	private Pet[] petList;
	private Ability[] abilityList;
	
	public Database(){
		petList=new Pet[20];
		abilityList=new Ability[50];
		
		//pets
		//Pet(String name, String type, int hitPoints, int manaPoints, int attack, int defense,
		//		int speed, boolean isFriendly, Ability[] abilities, String imgName)
		petList[0]=new Pet("Beexity", "electricity", 300, 100, 100, 100, 100, true, null,"bee.png");
		petList[1]=new Pet("Bunnign", "air", 300, 100, 100, 100, 100, true, null,"bunny.png");
		petList[2]=new Pet("Blackachu", "electricity", 300, 100, 100, 100, 100, true, null,"cat.png");
		petList[3]=new Pet("Coy", "air", 300, 100, 100, 100, 100, false, null,"ghostFish.png");
		petList[4]=new Pet("Dnome", "earth", 300, 100, 100, 100, 100, false, null,"gnome.png");
		petList[5]=new Pet("Ramfish", "air", 300, 100, 100, 100, 100, false, null,"goat.png");
		petList[6]=new Pet("Hollow Bat", "fire", 300, 100, 100, 100, 100, false, null,"hellBat.png");
		petList[7]=new Pet("Octobaby", "water", 300, 100, 100, 100, 100, false, null,"octopus.png");
		petList[8]=new Pet("Stowel", "air", 300, 100, 100, 100, 100, false, null,"owl.png");
		petList[9]=new Pet("PumpinAxe", "fire", 300, 100, 100, 100, 100, false, null,"pumpkin.png");
		petList[10]=new Pet("Unbearable", "earth", 300, 100, 100, 100, 100, false, null,"scareBear.png");
		petList[11]=new Pet("Scarecrow", "fire", 300, 100, 100, 100, 100, false, null,"scarecrow.png");
		petList[12]=new Pet("Seapanda", "electricity", 300, 100, 100, 100, 100, false, null,"seapanda.png");
		petList[13]=new Pet("Stark", "water", 300, 100, 100, 100, 100, false, null,"shark.png");
		petList[14]=new Pet("Frosty", "water", 300, 100, 100, 100, 100, false, null,"snowman.png");
		petList[15]=new Pet("Shangri La", "fire", 300, 100, 100, 100, 100, false, null,"sword.png");
		petList[16]=new Pet("Umbrelldandy", "water", 300, 100, 100, 100, 100, false, null,"umbrellaLady.png");
		petList[17]=new Pet("Swordoo", "earth", 300, 100, 100, 100, 100, false, null,"voodoo.png");
		petList[18]=new Pet("ERROR", "error", 0, 0, 0, 0, 0, false, null,"hellBat.png");
		petList[19]=new Pet("ERROR", "error", 0, 0, 0, 0, 0, false, null,"hellBat.png");
		
		//abilities
		//fire
		abilityList[0]=new Ability("SEAR", 35, 20, 100,"fire",false, false);
		abilityList[1]=new Ability("FLAME VORTEX", 45, 25, 95,"fire",false, false);
		abilityList[2]=new Ability("INCINERATE", 60, 40, 85,"fire",false, false);
		abilityList[3]=new Ability("TORCH", 75, 50, 80,"fire",false, false);
		abilityList[4]=new Ability("DRAGONFIRE", 100, 60, 70,"fire",false, false);
		abilityList[5]=new Ability("FLARE", 15, 25, 90,"fire",true, false);
		abilityList[6]=new Ability("HELLFIRE", 20, 35, 85,"fire",true, false);
		abilityList[7]=new Ability("METEOR", 30, 45, 80,"fire",false, false);
		abilityList[8]=new Ability("PHOENIX TEAR", 70, 45, 100,"fire",false, true);
		abilityList[9]=new Ability("PHOENIX-FIRE HEARTH", 30, 60, 100,"fire",true, true);
		
		//water
		abilityList[10]=new Ability("SQUIRT", 35, 20, 100,"water",false, false);
		abilityList[11]=new Ability("AQUA MISSILE", 45, 25, 95,"water",false, false);
		abilityList[12]=new Ability("JET STREAM", 60, 40, 85,"water",false, false);
		abilityList[13]=new Ability("BUBBLE BURST", 75, 50, 80,"water",false, false);
		abilityList[14]=new Ability("IMMERSION", 100, 60, 70,"water",false, false);
		abilityList[15]=new Ability("TSUNAMI", 15, 25, 90,"water",true, false);
		abilityList[16]=new Ability("TYPHOON", 20, 35, 85,"water",true, false);
		abilityList[17]=new Ability("MAELSTROM", 30, 45, 80,"water",false, false);
		abilityList[18]=new Ability("HEALING RAIN", 70, 45, 100,"water",false, true);
		abilityList[19]=new Ability("POSEIDON'S REIGN", 30, 60, 100,"water",true, true);
		
		//earth
		abilityList[20]=new Ability("STONE THROW", 35, 20, 100,"earth",false, false);
		abilityList[21]=new Ability("ROCK BARRAGE", 45, 25, 95,"earth",false, false);
		abilityList[22]=new Ability("STALAGMITES", 60, 40, 85,"earth",false, false);
		abilityList[23]=new Ability("EARTHEN GAOL", 75, 50, 80,"earth",false, false);
		abilityList[24]=new Ability("GEOCRUSH", 100, 60, 70,"earth",false, false);
		abilityList[25]=new Ability("QUICKSAND", 15, 25, 90,"earth",true, false);
		abilityList[26]=new Ability("QUAKE", 20, 35, 85,"earth",true, false);
		abilityList[27]=new Ability("TERRAFORM", 30, 45, 80,"earth",false, false);
		abilityList[28]=new Ability("EARTHEN ROOT", 70, 45, 100,"earth",false, true);
		abilityList[29]=new Ability("MOTHER GAIA", 30, 60, 100,"earth",true, true);;
		
		//air
		abilityList[30]=new Ability("WING SLICE", 35, 20, 100,"air",false, false);
		abilityList[31]=new Ability("AEROBALL", 45, 25, 95,"air",false, false);
		abilityList[32]=new Ability("TWISTER", 60, 40, 85,"air",false, false);
		abilityList[33]=new Ability("GALEFORE", 75, 50, 80,"air",false, false);
		abilityList[34]=new Ability("ZEPHYR DRAFT", 100, 60, 70,"air",false, false);
		abilityList[35]=new Ability("TORNADO", 15, 25, 90,"air",true, false);
		abilityList[36]=new Ability("HURRICANE DESTRUCTION", 20, 35, 85,"air",true, false);
		abilityList[37]=new Ability("TEMPEST TORRENT", 30, 45, 80,"air",false, false);
		abilityList[38]=new Ability("BREATH OF LIFE", 70, 45, 100,"air",false, true);
		abilityList[39]=new Ability("HEALING WIND", 30, 60, 100,"air",true, true);
		
		//electricity
		abilityList[40]=new Ability("SHOCK", 35, 20, 100,"electric",false, false);
		abilityList[41]=new Ability("JOLT TACKLE", 45, 25, 95,"electric",false, false);
		abilityList[42]=new Ability("ELECTRO-BOLT", 60, 40, 85,"electric",false, false);
		abilityList[43]=new Ability("SUPERBOLT", 75, 50, 80,"electric",false, false);
		abilityList[44]=new Ability("ARC LIGHTNING", 100, 60, 70,"electric",false, false);
		abilityList[45]=new Ability("CHAIN LIGHTNING", 15, 25, 90,"electric",true, false);
		abilityList[46]=new Ability("THUNDERSTORM", 20, 35, 85,"electric",true, false);
		abilityList[47]=new Ability("ELECTROMAGNETIC PULSE", 30, 45, 80,"electric",false, false);
		abilityList[48]=new Ability("RECHARGE", 70, 45, 100,"electric",false, true);
		abilityList[49]=new Ability("DEFIBRILATING STORM", 30, 60, 100,"electric",true, true);
		
	}
	
	public Pet[] getPets(){
		return petList;
	}
	
	public Ability[] getAbilities(){
		return abilityList;
	}

}
