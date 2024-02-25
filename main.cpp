#include <iostream>

int main() {

	int HP = 10;
	int damage;
	int HP_grr = 20;
	char sex;
	bool sperma = true;
	int c_damage;
	int rand_int;

	std::cout << "HP: " << HP << std::endl << "HP_grr: " << HP_grr << std::endl;
	
	while (sperma) {
		srand(time(NULL));

		std::cout << "y/n" << std::endl;
		std::cin >> sex;
		switch (sex)
		{
		case 'y':
			sperma = true;
			break;
		case 'n':
			sperma = false;
			break;
		}
		if (sperma) {
			c_damage = 4 + rand() % 10;
			rand_int = 1 + rand() % 7;
			if (rand_int < 4) {
				damage = 0;
			}
			else if (rand_int >= 4) {
				damage = 1 + rand() % 5;
			}
			HP_grr -= c_damage;
			HP -= damage;

			std::cout << "HP: " << HP << std::endl << "damage: " << damage << std::endl << "HP_grr: " << HP_grr << std::endl;
			if (HP <= 0) {
				std::cout << std::endl;
				std::cout << "GAME OVER";
				sperma = false;
			}
			if (HP_grr <= 0) {
				std::cout << std::endl;
				std::cout << "WIN";
				sperma = false;
			}
		}

	}

	return 0;
}