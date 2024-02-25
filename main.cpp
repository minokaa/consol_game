#include <iostream>

int main() {

	int HP = 10;
	int damage = 0;
	int HP_grr = 20;
	char input_menu;
	short status_menu = 1;
	int c_damage;
	int rand_int;
	char shop;
	int d1 = 0;
	int p1 = 0;
	int money = 10;

	std::cout << "HP: " << HP << std::endl
		<< "HP_grr: " << HP_grr << std::endl;;
	
	while (status_menu != 0) {
		srand(time(NULL));

		std::cout << std::endl;
		std::cout << "hit/shop/quit" << std::endl;
		std::cin >> input_menu;
		switch (input_menu)
		{
		case 'h':
			status_menu = 1;
			break;
		case 'q':
			status_menu = 0;
			break;
		case 's':
			status_menu = 2;
			break;
		}
		if (status_menu == 1) {
			c_damage = 4 + rand() % 10;
			rand_int = 1 + rand() % 7;
			if (rand_int < 4) {
				damage = 0;
			}
			else if (rand_int >= 4) {
				damage = 1 + rand() % 5;
				damage -= p1;
				if (damage < 0) {
					damage = 0;
				}
			}
			c_damage += d1;
			HP_grr -= c_damage;
			HP -= damage;

			std::cout << "HP: " << HP << std::endl
				<< "damage: " << damage << std::endl
				<< "HP_grr: " << HP_grr << std::endl;
			if (HP <= 0) {
				std::cout << std::endl;
				std::cout << "GAME OVER";
				status_menu = 0;
			}
			if (HP_grr <= 0) {
				std::cout << std::endl;
				std::cout << "WIN";
				status_menu = 0;
			}
		}
		else if (status_menu == 2) {
			std::cout << std::endl;
			std::cout << "================" << std::endl
				<< "SHOP" << std::endl
				<< "================" << std::endl
				<< "money: " << money << std::endl
				<< "damage/protection" << std::endl;
			std::cin >> shop;
			switch (shop) {
			case 'd':
				if (money >= 10) {
					d1++;
					money -= 10;
				}
				break;
			case 'p':
				if (money >= 13) {
					p1++;
					money -= 13;
				}
				else {
					std::cout << std::endl;
					std::cout << "NO MONEY" << std::endl;
				}
				break;
			}
			
		}
	}

	return 0;
}
