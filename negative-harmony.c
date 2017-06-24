/** negative-harmony.c
 * Given a tonal center and the notes of a chord, returns the negative
 * of the chord.
 * Note: just a hack. I was tired on counting on the staff.
 * Also, doesn't use 'correct' note names, just equivalent piano keys.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sharps[25][3] =
{ "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B",
  "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C" };
  
char flats[25][3] =
{ "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B",
  "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B", "C" };

int main(int argc, char** argv) {
  if(argc < 2) {
    printf("Usage: %s KEY NOTE [NOTES...]\n", argv[0]);
  }
  
  int key; //tonal center represented as an index in the globals.
  int low_mirror; // minor third of key. actual 'mirror' is between m/M3.
  int i, j;
  for(i = 0; i < 12, i++) {
    if(strncmp(sharps[i], argv[1], 2) == 0 ||
       strncmp(flats[i],  argv[1], 2) == 0) {
      key = i;
      low_mirror = i + 4;
      printf("Key is %s (%d)\n", argv[1], i);
      break;
    }
  }
  
  int current; // Current note
  int diff;
  for(j = argc-1; j >= 2; j--) {
    for(i = 0; i < 12, i++) {
      if(strncmp(sharps[i], argv[j], 2) == 0 ||
         strncmp(flats[i],  argv[j], 2) == 0) {
        current = i;
        diff = current - low_mirror - 1;
        int to_print = low_mirror - diff;
        while(to_print > 20) {
          to_print -= 12;
        }
        while(to_print < 0) {
          to_print += 12;
        }
        printf("%s ", sharps[to_print]);
      }
    }
  }
}
