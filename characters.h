#ifndef nonPlayerCharacters_h
#define nonPlayerCharacters_h

#include <typeinfo>

//player
class player : public character{
	private:
		weapon weapons[25];
		armor armorList[25];
		
		weapon mainHand;
		weapon offHand;
	public:
		player(string n, string d = "", int mh = 0, int h = 0, int th = 0, int dm = 0, int a  = 0){
			name = n;
			des = d;
			maxHealth = mh;
			health = h;
			toHit = th;
			dmg = dm;
			ac = a;
		}
		
		void getWeapons(weapon w[25]){
			for (int v = 0; v < (sizeof(weapons)/sizeof(weapons[0])); v++){
				w[v] = weapons[v];
			}
		}
		void getArmor(armor a[25]){
			for (int v = 0; v < (sizeof(armorList)/ sizeof(armorList[0])); v++){
				a[v] = armorList[v];
			}
		}
		weapon getMainHand(){
			return mainHand;
		}
		weapon getOffHand(){
			return offHand;
		}
		
		void setMainHand(weapon var){
			mainHand = var;
		}
		void setOffHand(weapon var){
			offHand = var;
		}
		
		void printInventory(){
			//weapons
			for (int v = 0; v < (sizeof(weapons)/sizeof(weapons[0])); v++){
				cout << weapons[v].getName() << endl;
			}
		}
		template<class T>
		void addWeapon(T i){
			for (int v = 0; v < (sizeof(weapons)/sizeof(weapons[0])); v++){
				if (weapons[v].getName() == ""){
					weapons[v] = i;
					break;
				}
			}
		}
		
		template<class T>	
		void addArmor(T i){
			for (int v = 0; v < (sizeof(armorList)/sizeof(armorList[0])); v++){
				if (armorList[v].getName() == ""){
					armorList[v] = i;
					ac += armorList[v].getAcIncrease();
					break;
				}
			}
		}
		template<class T>
		void removeWeapon(T i){
			for (int v = 0; v < (sizeof(weapons)/sizeof(weapons[0])); v++){
				if (weapons[v].getName() == i.getName()){
					weapons[v] = emptyWeapon;
					break;
				}
			}
		}
		
		template<class T>
		void removeArmor(T i){
			for (int v = 0; v < (sizeof(armorList)/sizeof(armorList[0])); v++){
				if (armorList[v].getName() == i.getName()){
					armorList[v] = emptyArmor;
					break;
				}
			}
		}
		
		template<class T>
		void attack(T *object){
			if (object->getAc() < getToHit()){
				if (getMainHand().getOneHanded()){
					object->recieveDamage(
					getDmg() + 
					getMainHand().getDmgIncrease() + 
					getOffHand().getDmgIncrease());
				} else{
					object->recieveDamage(
					getDmg() + 
					getMainHand().getDmgIncrease());
				}
			}
		}
		
		void a(){
			//just to make sure this class works because of virtual crap
		}
};

#endif
