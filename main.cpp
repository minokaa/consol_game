#include <iostream>
#include <windows.h>

int main() {
	SetConsoleOutputCP(CP_UTF8);

	int HP = 10;
	int damage = 0;
	int HP_grr = 20;
	int input_menu;
	short status_menu = 1;
	int c_damage;
	int rand_int;
	int shop;
	int d1 = 0;
	int p1 = 0;
	int money = 10;
	int HP_grr_default = 20;
	int money_def = 5;
	int damage_def = 3;
	float money_sex = 1.3;

	std::cout << "HP: " << HP << std::endl
		<< "HP_grr: " << HP_grr << std::endl;;

	while (status_menu != 0) {

		srand(time(NULL));

		std::cout << std::endl;
		std::cout << "hit/shop/quit" << std::endl;
		std::cin >> input_menu;		//menu
		
		
		switch (input_menu)
		{
		case 1:
			status_menu = 1;
			break;
		case 3:
			status_menu = 0;
			break;
		case 2:
			status_menu = 2;
			break;
		default:
			status_menu = 0;
			break;
		}

		if (status_menu == 1) {		// fight
			c_damage = 4 + rand() % 10;
			rand_int = 1 + rand() % 7;
			if (rand_int < 4) {
				damage = 0;
			}
			else if (rand_int >= 4) {
				damage = 1 + rand() % damage_def;
				damage -= p1;
				if (damage < 0) {
					damage = 0;
				}
			}
			c_damage += d1;
			HP_grr -= c_damage;
			HP -= damage;

			std::cout << std::endl
				<< "FIGHT" << std::endl
				<< std::endl
				<< "HP: " << HP << std::endl
				<< "damage: " << damage << std::endl
				<< "HP_grr: " << HP_grr << std::endl;
			if (HP <= 0) {
				std::cout << std::endl;
				std::cout << "BALLS OVER";
				status_menu = 0;
			}
			if (HP_grr <= 0) {
				std::cout << std::endl;
				std::cout << "================" << std::endl
					<< "WIN" << std::endl
					<< "================" << std::endl << std::endl;
				HP_grr_default *= 1.3;
				damage_def *= 1.3;
				HP_grr = HP_grr_default;
				std::cout << "HP: " << HP << std::endl
					<< "HP_grr: " << HP_grr << std::endl;;
				money += (money_def * 1.7);
				money_def *= 1.5;
			}
		}

		else if (status_menu == 2) {	//shop
			std::cout << std::endl;
			std::cout << "================" << std::endl
				<< "SHOP" << std::endl
				<< "================" << std::endl
				<< "money: " << money << std::endl
				<< "================" << std::endl
				<< (int)(7.7 * money_sex) << "    " << (int)(10 * money_sex) << "        " << (int)(3.9 * money_sex) << std::endl
				<< "damage/protection/healthup" << std::endl;
			std::cin >> shop;
			switch (shop) {
			case 1:
				if (money >= 7.6 * money_sex) {
					d1++;
					money -= (int)(7.6 * money_sex);
					money_sex += 0.2;
				}
				else {
					std::cout << std::endl;
					std::cout << "NO MONEY :c" << std::endl;
				}
				break;
			case 2:
				if (money >= 10 * money_sex) {
					p1++;
					money -= (int)(10 * money_sex);
					money_sex += 0.2;
				}
				else {
					std::cout << std::endl;
					std::cout << "NO MONEY :c" << std::endl;
				}
				break;
			case 3:
				if (money >= 3.9 * money_sex) {
					HP += 3;
					money -= (int)(3.9 * money_sex);
					money_sex += 0.2;
				}
				else {
					std::cout << std::endl;
					std::cout << "NO MONEY :c" << std::endl;
				}
				break;
			default:
				status_menu = 0;
				break;
			}
		}
	}

	return 0;
}

