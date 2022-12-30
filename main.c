

#include "car_header.h"

void printf_int(int i)
{
	printf("%d\n",i);
}

/************************************************************************
*
*	main: 
*
************************************************************************/


void main(void)
{
	void (*print_int_ptr)(int) = &printf_int;
	(*print_int_ptr)(10);
	FILE* ostream = fopen("cars.txt", "w");
	FILE* car_file_ptr = fopen("cars.txt", "r");

	struct car* car1 =car_new("Volvo", "v70", "red", 1995, CAR_TRANSMISSION_MANUAL);
	struct car* car2=car_new("BMW", "z3", "Blue", 2001, CAR_TRANSMISSION_AUTOMATIC);
	struct car* car3=car_new("Skoda", "oktavia RS", "White", 2003, CAR_TRANSMISSION_MANUAL);
	
	struct car* car_array[] = {car1,car2,car3};
	cars_print(&car_array, 3, 0);
	car_change_color(&car1, "Green");
	
	car_print(car1,0);
	
	cars_print(&car_array, 3, ostream);
	
	car_delete(&car1);
	car_delete(&car2);
	car_delete(&car3);
	
	/*fclose(ostream);*/
	
	file_read(stdout, car_file_ptr);

	printf("klart");
}