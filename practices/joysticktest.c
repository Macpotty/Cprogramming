#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "sys/ioctl.h"
#include "linux/joystick.h"
#define JOY_DEV "/dev/input/js0"
int main(){
	int joy_fd, *axis=NULL, num_of_axis=0, num_of_buttons=0, x;
	char *button=NULL, name_of_joystick[50];
	struct js_event js;

	if((joy_fd = open(JOY_DEV, O_RDONLY)) == -1){
		printf("Couldn't open joystick file.\n");
		return -1;
	}
	ioctl(joy_fd, JSIOCGAXES, &num_of_axis);
	ioctl(joy_fd, JSIOCGBUTTONS, &num_of_buttons);
	ioctl(joy_fd, JSIOCGNAME(50), &name_of_joystick);

	axis = (int*)calloc(num_of_axis, sizeof(int));
	button = (char*)calloc(num_of_buttons, sizeof(char));
	printf("Joysticked:%s\n\t%d axis\n\t%d buttons\n\n"
			, name_of_joystick
			, num_of_axis
			, num_of_buttons);
	fcntl(joy_fd, F_SETFL, O_NONBLOCK);
	while(1){
		read(joy_fd, &js, sizeof(struct js_event));

		switch (js.type & ~JS_EVENT_INIT){
			case JS_EVENT_AXIS:
					axis[js.number] = js.value;
					break;
			case JS_EVENT_BUTTON:
					button[js.number] = js.value;
					break;
		}
		printf("X1: %6d  Y1: %6d  X2: %6d  Y2: %6d  LT1: %6d  LT2: %6d  LR: %6d  UD: %6d  "
				,axis[0], axis[1], axis[2], axis[3], axis[4], axis[5], axis[6], axis[7]);
		for(x = 0; x < num_of_buttons; x++)
			printf("B%d: %d  ", x, button[x]);
		printf("  \r");
		fflush(stdout);
	}

	close(joy_fd);
	return 0;
}