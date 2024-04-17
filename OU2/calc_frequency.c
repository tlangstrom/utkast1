#include "calc_frequency.h"

charFrequency *calc_frequency(FILE *frequency_file_p) {
    charFrequency *frequency = (charFrequency *)malloc(256 * sizeof(charFrequency));

    for(int i = 0; i < 256; i++) {
        frequency[i].character = i;
        frequency[i].frequency = 0;
    }

    int character;
    while((character = fgetc(frequency_file_p)) != EOF) {
        if(character >= 0 && character < 256) {
            frequency[character].frequency++;
        }
    }
    
    // for(int i = 0; i < 256; i++) {
    //     if(frequency[i].frequency > 0) 
    //     printf("Item %d: [%d, %d]\n", i, frequency[i].character, frequency[i].frequency);
    // }
    
    return frequency;
}