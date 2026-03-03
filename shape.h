#ifndef SHAPE_H
#define SHAPE_H

enum shape_kind {RECTANGLE, CIRCLE};
struct point {int x, y;};

struct shape {
	shape_kind kind;	
	struct point center;
	union{
		struct{
			int height, width;
		} rectangle;
		struct {
			int radius;
		} circle;
	}u;
};

int area(struct shape);

#endif
