#ifndef equipment_h
#define equipment_h

//this is for weapons
class weapon : public item{
	private:
		int dmgIncrease;
		int durability;
		bool oneHanded;
	public:
		weapon(string n = "", string d = "", int v = 0, int di = 0, int du = 0, bool oh = NULL){
			name = n;
			des = d;
			value = v;
			dmgIncrease = di;
			durability = du;
			oneHanded = oh;
		}
		int getDmgIncrease(){
			return dmgIncrease;
		}
		int getDurability(){
			return durability;
		}
		bool getOneHanded(){
			return oneHanded;
		}
	
		void setDmgIncrease(int var){
			dmgIncrease = var;
		}
		void setDurability(int var){
			durability = var;
		}
		void setOneHanded(bool var){
			oneHanded = var;
		}
	
		void a(){
	
		}
};

weapon emptyWeapon;

class armour : public item{
	private:
		int acIncrease;
		int durability;
		string place;
	public:
		armour(string n = "", string d = "", int v = 0, int aci = 0, int du = 0, string p = ""){
			name = n;
			des = d;
			value = v;
			acIncrease = aci;
			durability = du;
			place = p;
		}
		int getAcIncrease(){
			return acIncrease;
		}
		int getDurability(){
			return durability;
		}
		string getPlace(){
			return place;
		}
	
		void setAcIncrease(int var){
			acIncrease = var;
		}
		void setDurability(int var){
			durability = var;
		}
		void setOneHanded(string var){
			place = var;
		}
	
		void a(){
	
		}
};

armour emptyArmour;

#endif
