/** negative-harmony.c
 * Given a tonal center and the notes of a chord, returns the negative
 * of the chord.
 * Note: just a hack. I was tired on counting on the staff.
 * Also, doesn't use 'correct' note names, just equivalent piano keys.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  if(argc < 2) {
    printf("Usage: %s KEY NOTE [NOTES...]", argv[0]);
  }
}
