#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

#ifndef classes_h
#define classes_h

namespace rp{
	//all items
	class item{
		protected:
			string name;
			string des;//description
			int value;
		public:
			string getName(){
				return name;
			}
			string getDes(){
				return des;
			}
			int getValue(){
				return value;
			}
		
			void setName(string var){
				name = var;
			}
			void setDes(string var){
				des = var;
			}
			void setValue(int var){
				value = var;	
			}
		
			virtual void a() = 0;
	};

	//item headers
	#include "items.h"
	#include "equipment.h"

	//all characters
	class character{
		protected:
			string name;
			string des;//description
			int maxHealth;
			int health;
			int toHit;
			int dmg; //damage
			int ac; //armor
		public:
		
			string getName(){
				return name;
			}
			string getDes(){
				return des;
			}
			int getMaxHealth(){
				return maxHealth;
			}
			int getHealth(){
				return health;
			}
			int getToHit(){
				return toHit;
			}
			int getDmg(){
				return dmg;
			}
			int getAc(){
				return ac;
			}
		
			void setName(string var){
				name = var;
			}
			void setDes(string var){
				des = var;
			}
			void setMaxHealth(int var){
				maxHealth = var;
			}
			void setHealth(int var){
				health = var;
			}
			void setToHit(int var){
				toHit = var;
			}
			void setDmg(int var){
				dmg = var;
			}
			void setAc(int var){
				ac = var;
			}
		
			//other functions in class
			template<class T> //takes the apponent and deals damage
			void attack(T *object){
				if (object->getAc() < getToHit()){
					object->recieveDamage(getDmg());
				}
			}
		
			void recieveDamage(int amount){
				setHealth(getHealth() - amount + ac);
			}
		
			void gainHealth(int amount){
				if ((amount + getHealth()) > getMaxHealth()){
					setHealth(getMaxHealth());
				}else{
					setHealth(getHealth() + amount);
				}
			}
		
			virtual void a() = 0;
	};

	//character headers
	#include "enemies.h"
	#include "characters.h"
}
#endif
