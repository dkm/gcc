int check_args_are_correct (int argument0, int argument1, int argument2,
			    int argument3, int argument4, int argument5,
			    int argument6, int argument7, int argument8,
			    int argument9, int argument10, int argument11);

int
check_args_are_correct_user (int argument0, int argument1, int argument2,
			     int argument3, int argument4, int argument5,
			     int argument6, int argument7, int argument8,
			     int argument9, int argument10, int argument11)
{
  return argument0 == 0 && argument1 == 1 && argument2 == 2 && argument3 == 3
	 && argument4 == 4 && argument5 == 5 && argument6 == 6 && argument7 == 7
	 && argument8 == 8 && argument9 == 9 && argument10 == 10
	 && argument11 == 11;
}

int
main (int argc, char **argv)
{

  // CHECK r0 0
  // CHECK r1 1
  // CHECK r2 2
  // CHECK r3 3
  // CHECK r4 4
  // CHECK r5 5
  // CHECK r6 6
  // CHECK r6 6
  // CHECK r7 7
  // CHECK r8 8
  // CHECK r9 9
  // CHECK r10 10
  // CHECK r11 11

  return !check_args_are_correct (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
}
