#include <iostream>

void calc_new_alram_time(int *hour, int *minute) {
	if (*minute < 45) {
		if (*hour == 0)
			*hour = 24;
		--(*hour);
		*minute = *minute + 15;
	} else {
		*minute -= 45;
	}
}

int main(void) {
	int hour;
	int minute;

	std::cin >> hour >> minute;
	calc_new_alram_time(&hour, &minute);
	std::cout << hour << " " << minute << std::endl;
	return (0);
}
