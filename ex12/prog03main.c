#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prog03header.h"

int main() {
  int i;
  Planet planets[NPLANETS];
  
  if( read_planets( planets ) != 0 ){
      fprintf(stderr, "Input Error!\n");
      exit(3);
  }

  for (i = 0; i < NPLANETS; i++) {
    printf("Name: %s\n", planets[i].name);
    printf("  Radius: %.0f [km]\n", planets[i].radius);          /* 蜊雁ｾ� */
    printf("  Density: %.2f [g/cm3]\n", planets[i].density);     /* 蟇�ｺｦ */
    printf("  Semi-Major Axis: %.3e [km]\n", planets[i].semi_major_axis);   /* 霆碁％髟ｷ蜊雁ｾ� */
  }

  return 0;
}

#ifdef TEST0 /* 蜊倅ｽ薙ユ繧ｹ繝育畑 read_planets 豁｣蟶ｸ蜍穂ｽ懶ｼ域綾繧雁､ 0 �峨�蝣ｴ蜷� */
int read_planets(Planet *planets) {
  int i;
  for (i = 0; i < NPLANETS; i++) {
    strcpy(planets[i].name, "Sample");     /* 繝�せ繝育畑縺ｮ繧ｵ繝ｳ繝励Ν繝��繧ｿ */
    planets[i].radius = 1000;
    planets[i].density = 1.00;
    planets[i].semi_major_axis = 100000000;
  }
  return 0;
}
#elif TEST1 /* 蜊倅ｽ薙ユ繧ｹ繝育畑 read_planets 逡ｰ蟶ｸ蜍穂ｽ懶ｼ域綾繧雁､ -1 �峨�蝣ｴ蜷� */
int read_planets(Planet *planets) {
  return -1;
}
#endif
