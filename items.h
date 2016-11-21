#ifndef items_h
#define items_h

class consumable : public item{
	private:
		int change;
	public:
		consumable(string n = "", string d = "", int v = 0, int c = 0){
			name = n;
			des = d;
			value = v;
			change = c;
		}
		
		int getChange(){
			return change;
		}
		
		void setChange(int var){
			change = var;
		}
		
		template<class T>
		void use(T *target, string type){
			if (type == "health"){
				target->setHealth(target->getHealth() + change);
			}else if (type == "maxHealth"){
				target->setMaxHealth(target->getMaxHealth() + change);
			}else if (type == "toHit"){
				target->setToHit(target->getToHit() + change);
			}else if (type == "dmg"){
				target->setDmg(target->getDmg() + change);
			}else if (type == "ac"){
				target->setAc(target->getAc() + change);
			}
		}
};

#endif
