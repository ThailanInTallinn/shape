#include <stdio.h>
#include <math.h>
#include "shape.h"

int main(void){
	return 0;
}

double area(struct shape s){
	if(s.kind == RECTANGLE){
		return s.u.rectangle.height * s.u.rectangle.width;
	}
	return s.u.circle.radius * s.u.circle.radius * 3.14;
}

struct shape move(struct shape s, int x, int y){
	struct point new_center = ((struct point) {.x = s.center.x + x, .y = s.center.y + y});

	if(s.kind == RECTANGLE){
		int new_width = s.u.rectangle.width + x;
		int new_height = s.u.rectangle.height + y;

		return ((struct shape) {
				.kind = s.kind,
				.center = new_center,
				.u.rectangle = {.width = new_width, .height = new_height},
				});
	} 

	return ((struct shape) {
			.kind = s.kind,
			s.center  = new_center,
			s.u.circle.radius = s.u.circle.radius,
			});
}

struct shape scale(struct shape s, double c){
	if(s.kind == RECTANGLE){
		int new_width = s.u.rectangle.width * c;
		int new_height = s.u.rectangle.height * c;
		return ((struct shape) {
				.kind = s.kind,
				.center = s.center,
				.u.rectangle = {.width = new_width, .height = new_height},
				});
	}

	return ((struct shape) {
			.kind = s.kind,
			s.center  = s.center,
			s.u.circle.radius = s.u.circle.radius * c,
			});
}
