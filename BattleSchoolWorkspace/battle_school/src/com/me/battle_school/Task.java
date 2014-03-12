package com.me.battle_school;

public class Task {
	private int idNo;
	private boolean completed=false;
	
	public Task(int id){
		this.idNo=id;
	}
	
	public void completeTask(){
		completed = true;
	}
	public boolean isCompleted(){
		return completed;
	}
}
