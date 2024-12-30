#define NPLANETS 8
typedef struct {
	char name[10];
	double radius;
	double density;
	double semi_major_axis;
	} Planet;

int read_planets(Planet *);