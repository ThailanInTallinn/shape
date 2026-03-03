#ifndef SHAPE_H
#define SHAPE_H

enum shape_kind {RECTANGLE, CIRCLE};
struct point {int x, y;};

struct shape {
	enum shape_kind kind;	
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

double area(struct shape);
struct shape move(struct shape, int, int);
struct shape scale(struct shape, double);

#endif
